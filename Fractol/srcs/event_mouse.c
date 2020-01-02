/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:17:50 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 17:20:46 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_param(int x, int y, t_lib *data)
{
	int	mx;
	int	my;

	if (data->state != 4 && data->state != 0  && data->clic != 1)
	{
		if (x < ECRAN_X && x > 0 && y < ECRAN_Y && y > 0)
		{
			mx = x - ECRAN_X / 2;
			my = ECRAN_Y / 2 - y;
			data->add.x += (mx > 0) ? 0.001 : -0.001;
			data->add.y -= (my > 0) ? 0.001 : -0.001;
			ft_to_window(data);
		}
	}
	return (0);
}

int		ft_key_redirect(int keycode, t_lib *data)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 44)
		ft_key_color(keycode, data);
	else if (keycode == 78)
		ft_key_zoom(78, data);
	else if (keycode == 69)
		ft_key_zoom(69, data);
	ft_to_window(data);
	return (0);
}

int		ft_key_zoom(int keycode, t_lib *data)
{
	if (keycode == 69 || keycode == 78)
	{
		data->echelle *= (keycode == 78 ? 0.9 : 1.1);
		//data->precision *= (keycode == 78 ? 1.02 : 0.98);
	}
	return (0);
}

int		ft_mouse_zoom_in(int mouse_key, int x, int y, t_lib *data)
{
	if (mouse_key == 1)
		data->clic = (!data->clic) ? 1 : 0;
	else if (mouse_key == 2)
	{
		data->ctr.x += data->echelle * ((2 * (double)x / ECRAN_X) - RATIO_X);
		data->ctr.y += data->echelle * ((2 * (double)y / ECRAN_X) - RATIO_Y);
	}
	else if (x < ECRAN_X && x > 0 && y < ECRAN_Y && y > 0)
	{
		if (mouse_key == 5)
			ft_key_zoom(78, data);
		else if (mouse_key == 4)
			ft_key_zoom(69, data);
	}
	ft_to_window(data);
	return (0);
}
