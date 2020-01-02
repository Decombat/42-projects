/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:05:36 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/15 15:09:40 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_frame_check(char **frame, t_tetri *elem, int x, int y)
{
	int cpx;
	int cpy;

	cpx = x;
	cpy = y;
	if (!elem)
		return (1);
	while (frame[cpy])
	{
		while (frame[cpy][cpx])
		{
			if (ft_check_and_place(frame, elem, cpx, cpy))
			{
				if (ft_frame_check(frame, elem->next, 0, 0))
					return (1);
				else
					(ft_frame_remove(frame, elem, cpx, cpy));
			}
			cpx++;
		}
		cpx = 0;
		cpy++;
	}
	return (0);
}

int		ft_check_and_place(char **frame, t_tetri *elem, int x, int y)
{
	int			size;
	t_position	*p;

	size = ft_strlen(*frame);
	p = elem->pa;
	while (p)
	{
		if (p->x + x < size && p->y + y < size &&
				frame[p->y + y][p->x + x] == '.')
			p = p->next;
		else
			return (0);
	}
	p = elem->pa;
	while (p)
	{
		frame[p->y + y][p->x + x] = elem->letter;
		p = p->next;
	}
	return (1);
}

void	ft_frame_remove(char **frame, t_tetri *elem, int x, int y)
{
	t_position *p;

	p = elem->pa;
	while (p)
	{
		frame[p->y + y][p->x + x] = '.';
		p = p->next;
	}
}
