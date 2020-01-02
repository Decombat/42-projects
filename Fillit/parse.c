/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/16 19:29:36 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char					*ft_readfd(char *str)
{
	char	block[BUF_SIZ];
	int		fd;
	int		size;
	char	*dup;

	dup = NULL;
	fd = open(str, O_RDONLY);
	if ((size = (read(fd, block, BUF_SIZ))) && size % 21 == 20)
	{
		if ((dup = malloc(sizeof(char) * size + 2)) == 0)
			return (0);
		ft_strncpy(dup, block, ft_strlen(block));
		dup[size] = '\n';
		dup[size + 1] = '\0';
	}
	else
	{
		write(1, "error", 5);
		exit(0);
	}
	if (close(fd) < 0)
		return (0);
	return (dup);
}

t_tetri					*ft_atotet(char *str, char letter)
{
	t_tetri		*tetri;

	tetri = new_tetri();
	if (ft_tetri_add_pos(tetri, str) && (ft_is_tetri_valid(tetri))
			&& str[20] == '\n')
	{
		tetri->letter = letter;
		if (str[20] == '\n' && str[21])
			tetri->next = ft_atotet(&str[21], letter + 1);
	}
	else
	{
		write(1, "error", 5);
		exit(0);
	}
	return (tetri);
}

t_tetri					*new_tetri(void)
{
	t_tetri		*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	tetri->pa = new_position(-2, -2);
	tetri->pb = new_position(-2, -2);
	tetri->pc = new_position(-2, -2);
	tetri->pd = new_position(-2, -2);
	tetri->pa->next = tetri->pb;
	tetri->pb->next = tetri->pc;
	tetri->pc->next = tetri->pd;
	tetri->pd->next = NULL;
	tetri->placed = 0;
	tetri->next = NULL;
	return (tetri);
}

void					ft_remove_extra_spaces(t_tetri *tetri)
{
	t_tetri *copie;

	copie = tetri;
	while (tetri)
	{
		while (tetri->pa->x && tetri->pb->x && tetri->pc->x && tetri->pd->x)
		{
			tetri->pa->x--;
			tetri->pb->x--;
			tetri->pc->x--;
			tetri->pd->x--;
		}
		while (tetri->pa->y && tetri->pb->y && tetri->pc->y && tetri->pd->y)
		{
			tetri->pa->y--;
			tetri->pb->y--;
			tetri->pc->y--;
			tetri->pd->y--;
		}
		tetri = tetri->next;
	}
	tetri = copie;
}
