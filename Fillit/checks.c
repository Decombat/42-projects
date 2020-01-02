/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:45:58 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/16 15:07:33 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_is_tetri_valid(t_tetri *tetri)
{
	int i;

	if ((i = ft_are_pos_adj(tetri, tetri->pa))
			&& (i += ft_are_pos_adj(tetri, tetri->pb))
			&& (i += ft_are_pos_adj(tetri, tetri->pc))
			&& (i += ft_are_pos_adj(tetri, tetri->pd)) && i >= 6)
		return (1);
	return (0);
}

t_tetri		*ft_tetri_add_pos(t_tetri *tetri, char *str)
{
	int			i;
	int			j;
	t_position	*p;

	p = tetri->pa;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 5)
		{
			if (!ft_check_char(str, i, j, i * 5 + j))
				return (0);
			if (str[i * 5 + j] == '#')
			{
				if (tetri->pa && ft_itopos(tetri->pa, j, i))
					tetri->pa = tetri->pa->next;
				else
					return (0);
			}
		}
	}
	tetri->pa = p;
	return (tetri);
}

int			ft_check_char(char *str, int i, int j, int k)
{
	k = i * 5 + j;
	if (str[k] != '\n' && str[k] != '.' && str[k] != '#')
		return (0);
	if (j && ((j && str[k - 1] == '\n') || (!j && str[k - 1] != '\n')))
		return (0);
	return (1);
}
