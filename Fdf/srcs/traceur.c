/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:05:00 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 16:26:44 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_put_pixel(t_lib *data, int x, int y, int color)
{
	if (x > 0 && y > 0 && x < ECRAN_X && y < ECRAN_Y &&
			data->sz * (ECRAN_Y + 0) > data->sz * y + (x * 4) + 3)
	{
		data->img[data->sz * y + (x * 4)] = color;
		data->img[data->sz * y + (x * 4) + 1] = color >> 8;
		data->img[data->sz * y + (x * 4) + 2] = color >> 16;
		data->img[data->sz * y + (x * 4) + 3] = 0;
	}
}

int				ft_dif_hauteur(float a, float b)
{
	int dif;

	dif = 0;
	if (a < b)
		while (a++ < b)
			dif++;
	else if (b < a)
		while (b++ < a)
			dif++;
	return (dif);
}

void			ft_line(t_cor *a, t_cor *b, t_lib *data, t_space add)
{
	t_cor	df;
	t_cor	pt;

	ft_swap_cor(&a, &b);
	pt = *a;
	df.e = ft_abs(b->x - a->x);
	df.x = df.e * 2;
	df.y = ft_abs(b->y - a->y) * 2;
	while (pt.x <= b->x)
	{
		ft_put_pixel(data, (pt.x + add.x), (pt.y + add.y), mlx_get_color_value(
					data->wind, ft_convert_rvb(ft_tsl_to_rvb(pt.color))));
		df.e -= df.y;
		while (df.e < 0)
		{
			ft_put_pixel(data, (pt.x + add.x), (pt.y + add.y),
	mlx_get_color_value(data->wind, ft_convert_rvb(ft_tsl_to_rvb(pt.color))));
			if (pt.y == b->y)
				break ;
			ft_print_color(*a, *b, &pt.color.t, add.incr);
			pt.y -= (a->y > b->y) ? 1 : -1;
			df.e += df.x;
		}
		pt.x++;
	}
}

static void		ft_send_line(t_map *map, t_lib *data, t_space add)
{
	while (map->cor)
	{
		if (map->next)
			ft_line(map->cor, map->next->cor, data, add);
		if (map->cor->next)
		{
			ft_line(map->cor, map->cor->next, data, add);
			map->cor = map->cor->next;
		}
		if (!map->next && !map->cor->next)
			break ;
		else if (!map->next && map->first)
			map = map->first;
		else if (map->next)
			map = map->next;
	}
}

void			ft_print_line(t_map *map, t_lib *data)
{
	t_space add;

	add = ft_new_space((ECRAN_X - data->ctr.x.max + abs(data->ctr.x.min)) / 2,
	(ECRAN_Y - data->ctr.y.max + abs(data->ctr.y.min)) / 2, 0, data->coef);
	if (!map)
		return ;
	ft_send_line(map, data, add);
	if (map->first)
		map = map->first;
	while (map)
	{
		if (map->next)
			ft_line(map->cor, map->next->cor, data, add);
		else
			break ;
		map = map->next;
	}
	ft_list_first(&map);
}
