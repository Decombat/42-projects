/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:37:39 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 15:12:13 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_line	*ft_new_maillon(int nbr, t_line *next)
{
	t_line *new;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
		return (0);
	new->nbr = nbr;
	new->str = NULL;
	new->next = next;
	return (new);
}

static int		ft_new_line(t_line *new, char **line, int end)
{
	int		len;

	len = 0;
	while ((new->str)[len] && (new->str)[len] != '\n')
		len++;
	if (new->str[len] == '\n' || (!end && new->str))
	{
		*line = ft_strnew(len);
		*line = ft_strncpy(*line, new->str, len);
		if (len < (int)ft_strlen(new->str))
			new->str = ft_cut_line(new->str, len + 1);
		else
			ft_strdel(&new->str);
		return (1);
	}
	return (0);
}

static void		ft_read_buff(t_line *new, char *buff)
{
	char	*leaks;

	if (!new->str)
	{
		new->str = ft_strnew(BUFF_SIZE);
		new->str = ft_strncpy(new->str, buff, BUFF_SIZE);
	}
	else
	{
		leaks = new->str;
		new->str = ft_strjoin(new->str, buff);
		ft_strdel(&leaks);
	}
}

static int		ft_read_fd(const int fd, char **line, t_line *new)
{
	char	*buff;

	buff = ft_strnew(BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE))
	{
		ft_read_buff(new, buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		if (ft_new_line(new, line, 1))
		{
			ft_strdel(&buff);
			return (1);
		}
	}
	ft_strdel(&buff);
	if (new->str && *new->str)
		if (ft_new_line(new, line, 0))
			return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*new = NULL;
	t_line			*cmp;

	if (fd < 0 || (read(fd, NULL, 0)) < 0)
		return (-1);
	if (!new)
		new = ft_new_maillon(fd, NULL);
	cmp = new;
	if (new)
	{
		while (cmp && cmp->nbr != fd)
			cmp = cmp->next;
		if (!cmp)
			return (ft_read_fd(fd, line, (new = ft_new_maillon(fd, new))));
	}
	return (ft_read_fd(fd, line, cmp));
}
