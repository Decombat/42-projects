/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:17:58 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 18:46:22 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor		*ft_new_cor(float x, float y, float h, t_cor *first)
{
	t_cor	*pnt;

	if (!(pnt = (t_cor *)malloc(sizeof(t_cor))))
		return (0);
	pnt->x = x;
	pnt->y = y;
	pnt->h = h;
	pnt->color.t = 0.0;
	pnt->color.s = 0.8;
	pnt->color.l = 1.0;
	pnt->first = first;
	pnt->next = NULL;
	return (pnt);
}

t_map		*ft_new_map(t_cor *content, t_map *first)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->cor = content;
	map->first = first;
	map->next = NULL;
	return (map);
}

t_space		ft_new_space(int x, int y, int h, float incr)
{
	t_space new;

	new.x = x;
	new.y = y;
	new.h = h;
	new.incr = incr;
	return (new);
}
