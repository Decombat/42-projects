/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_iso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:02:10 by fedecomb          #+#    #+#             */
/*   Updated: 2018/09/27 16:58:12 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse(t_map **map, t_space add, void (*ft)(t_map **, t_space))
{
	if (!map || !*map)
		return ;
	while (*map)
	{
		while ((*map)->cor)
		{
			ft(map, add);
			if (!(*map)->cor->next)
				break ;
			(*map)->cor = (*map)->cor->next;
		}
		if (!(*map)->next)
			break ;
		*map = (*map)->next;
	}
	ft_list_first(map);
}

void	ft_add_iso(t_map **map, t_space add)
{
	add.x = (*map)->cor->x;
	add.y = (*map)->cor->y;
	(*map)->cor->x = (add.x + add.y);
	(*map)->cor->y = (add.y - add.x) / 2;
}

void	ft_move_shape(t_map **map, t_space add)
{
	if (add.x)
		(*map)->cor->x += add.x;
	if (add.y)
		(*map)->cor->y += add.y;
	if (add.h > 0)
		(*map)->cor->y -= (*map)->cor->h;
	else if (add.h < 0)
		(*map)->cor->y += (*map)->cor->h;
}

void	ft_zoom_shape(t_map **map, t_space add)
{
	if (add.incr && add.incr > 0.0)
	{
		(*map)->cor->x *= add.incr;
		(*map)->cor->y *= add.incr;
	}
	else if (add.incr && add.incr < 0.0)
	{
		(*map)->cor->x /= (float)ft_abs(add.incr);
		(*map)->cor->y /= (float)ft_abs(add.incr);
	}
}
