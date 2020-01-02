/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:18:09 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/07 16:42:12 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

unsigned long	ft_convert_rvb(t_rvb clr)
{
	return ((((unsigned char)clr.r & 0xFF) << 16) +
			(((unsigned char)clr.v & 0xFF) << 8) +
			(((unsigned char)clr.b & 0xFF) << 0));
}
