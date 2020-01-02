/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:17:44 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 16:39:10 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burningship(t_lib *data)
{
	data->state = 4;
	data->echelle = 2.5;
	data->ctr.y -= 0.5;
}

void	ft_get_value(t_lib *data, double x, double y, int state)
{
	data->add.x = x;
	data->add.y = y;
	data->state = state;
}

void	ft_key_color(int keycode, t_lib *data)
{
	if (keycode == 123)
		data->color += 0.1;
	else if (keycode == 124)
		data->color -= 0.1;
	else if(keycode == 125 && data->precision > 10.0)
			data->precision -= 1.0;
	else if (keycode == 126 && data->precision < 100.0)
			data->precision += 1.0;
	else if (keycode == 44)
		data->lum -= 0.1;
}
