/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:23:53 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 16:22:37 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_swap_cor(t_cor **a, t_cor **b)
{
	t_cor	c;

	if ((*a)->x > (*b)->x)
	{
		c = **a;
		**a = **b;
		**b = c;
	}
}

int				ft_abs(int c)
{
	if (c < 0)
		return (c *= -1);
	return (c);
}

static void		ft_max_min(t_ctr *vlr, int i)
{
	if (vlr->max < i)
		vlr->max = i;
	if (vlr->min > i)
		vlr->min = i;
}

void			ft_get_ctr(t_rec *d, t_map *map)
{
	d->x.max = 0;
	d->x.min = 0;
	d->y.max = 0;
	d->y.min = 0;
	d->h.max = 0;
	d->h.min = 0;
	while (map)
	{
		while (map->cor)
		{
			ft_max_min(&d->x, map->cor->x);
			ft_max_min(&d->y, map->cor->y);
			ft_max_min(&d->h, map->cor->h);
			if (!map->cor->next)
				break ;
			map->cor = map->cor->next;
		}
		if (!map->next)
			break ;
		map = map->next;
	}
	ft_list_first(&map);
}

void			ft_list_first(t_map **map)
{
	if (!map || !*map)
		return ;
	if ((*map)->first)
		*map = (*map)->first;
	while (*map)
	{
		if ((*map)->cor && (*map)->cor->first)
			(*map)->cor = (*map)->cor->first;
		if ((*map)->next)
			*map = (*map)->next;
		else
			break ;
	}
	if ((*map)->first)
		*map = (*map)->first;
}
