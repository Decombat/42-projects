/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:25:02 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 16:27:04 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_auto_color(t_map **map, t_space add)
{
	(*map)->cor->color.t = add.incr * (*map)->cor->h;
}

float				ft_coef_color(t_lib *data)
{
	int		dif;
	float	i;

	if (!data->spectre_max)
		data->spectre_max = 0.0;
	i = 0.0;
	dif = data->ctr.h.min;
	while (dif++ < data->ctr.h.max)
		i += 1.0;
	if (i)
		i = data->spectre_max / i;
	return (i);
}

void				ft_print_color(t_cor a, t_cor b, double *teinte, float i)
{
	t_cor df;

	df.y = ft_abs(b.y - a.y);
	df.h = ft_dif_hauteur(a.h, b.h);
	if ((a.y > b.y && b.h > a.h) || (a.y < b.y && b.h > a.h))
		*teinte += ((i * (float)df.h) / ((float)df.y));
	else if ((a.y < b.y && b.h < a.h) || (a.y > b.y && b.h < a.h))
		*teinte -= ((i * (float)df.h) / ((float)df.y));
}

unsigned long		ft_convert_rvb(t_rvb clr)
{
	return ((((unsigned char)clr.r & 0xFF) << 16) +
			(((unsigned char)clr.v & 0xFF) << 8) +
			(((unsigned char)clr.b & 0xFF) << 0));
}
