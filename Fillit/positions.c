/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:48:05 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/16 14:45:38 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_position		*new_position(int x, int y)
{
	t_position	*position;

	if (!(position = (t_position *)malloc(sizeof(t_position))))
		return (0);
	position->x = x;
	position->y = y;
	position->next = NULL;
	return (position);
}

t_position		*ft_itopos(t_position *pos, int i, int j)
{
	pos->x = i;
	pos->y = j;
	return (pos);
}

int				ft_are_pos_adj_one(t_position *p1, t_position *p2)
{
	if (p1->y == p2->y && (p1->x == p2->x + 1 || p1->x == p2->x - 1))
		return (1);
	if (p1->x == p2->x && (p1->y == p2->y + 1 || p1->y == p2->y - 1))
		return (1);
	return (0);
}

int				ft_are_pos_adj(t_tetri *tetri, t_position *p2)
{
	int i;

	i = 0;
	i += ft_are_pos_adj_one(tetri->pa, p2);
	i += ft_are_pos_adj_one(tetri->pb, p2);
	i += ft_are_pos_adj_one(tetri->pc, p2);
	i += ft_are_pos_adj_one(tetri->pd, p2);
	return (i);
}
