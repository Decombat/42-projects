/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:03:40 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 18:46:40 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_add_line(char ***tab, t_cor **pnt)
{
	static int	x = 0;
	static int	y = 0;
	static int	h = 0;
	t_cor		*cop;

	x = 0;
	h = 0;
	while ((*tab)[h])
	{
		if (!*pnt)
		{
			*pnt = ft_new_cor(x, y, ft_atoi((*tab)[h]), NULL);
			cop = *pnt;
		}
		else
		{
			(*pnt)->next = ft_new_cor(x, y, ft_atoi((*tab)[h]), cop);
			*pnt = (*pnt)->next;
		}
		free((*tab)[h]);
		x += 2;
		h++;
	}
	y += 2;
	*pnt = cop;
}

static void	ft_verif_split(char **line, char ***tab)
{
	ft_verif_line(*line);
	*tab = ft_strsplit(*line, ' ');
	ft_verif_tab(*tab);
}

void		ft_new_shape(t_map **map, int fd)
{
	char	*line;
	char	**tab;
	t_map	*cop;

	line = NULL;
	*map = ft_new_map(NULL, NULL);
	while (get_next_line(fd, &line))
	{
		ft_verif_split(&line, &tab);
		if (!(*map)->cor)
		{
			ft_add_line(&tab, &(*map)->cor);
			cop = *map;
		}
		else
		{
			(*map)->next = ft_new_map(NULL, cop);
			*map = (*map)->next;
			ft_add_line(&tab, &(*map)->cor);
		}
		ft_strdel(&line);
		free(tab);
	}
	*map = cop;
}
