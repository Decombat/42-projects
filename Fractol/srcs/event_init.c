/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:17:38 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 16:37:57 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_event(char *fractal, t_lib *data)
{
	data->echelle = 2.0;
	data->precision = 30.0;
	ft_new_cor(&data->add, 0.0, 0.0);
	ft_new_cor(&data->ctr, 0.0, 0.0);
	if (!ft_strcmp(fractal, "burningship"))
		ft_burningship(data);
	else if (!ft_strcmp(fractal, "julia"))
		ft_get_value(data, 0.285, 0.01, 1);
	else if (!ft_strcmp(fractal, "mandelbrot"))
	{
		data->ctr.x -= 0.5;
		data->state = 0;
	}
	else
	{
		ft_putstr("usage: ./fractol [julia][mandelbrot][burningship]\n");
		exit(1);
	}
}

int		ft_keyboard_event(int keycode, t_lib *data)
{
	if (keycode == 53)
	{
		ft_free_lib(data);
		exit(0);
	}
	else if (keycode == 49)
	{
		data->state += (data->state < 4) ? 1 : -4;
		data->echelle = 2.0;
		data->color = 0.0;
		data->lum = 0.0;
		data->precision = 30.0;
		if (data->state == 0)
			ft_init_event("mandelbrot", data);
		else if (data->state == 1)
			ft_init_event("julia", data);
		else if (data->state == 2)
			ft_get_value(data, -0.123, 0.745, 2);
		else if (data->state == 3)
			ft_get_value(data, -0.038088, 0.97, 3);
		else if (data->state == 4)
			ft_init_event("burningship", data);
		ft_to_window(data);
	}
	else
		ft_key_redirect(keycode, data);
	return (0);
}

void	ft_init_hooks(t_lib *data)
{
	data->event.key = &ft_keyboard_event;
	mlx_hook(data->wind, KeyPress, KeyRelease, data->event.key, data);
	data->event.mouse = &ft_mouse_param;
	mlx_hook(data->wind, MotionNotify, PointerMotionMask, ft_mouse_param, data);
	data->event.mouse_wheel = &ft_mouse_zoom_in;
	mlx_hook(data->wind, Button4, ButtonPressMask, ft_mouse_zoom_in, data);
}

int		ft_to_window(t_lib *data)
{
	ft_print_pixel(data);
	mlx_put_image_to_window(data->init, data->wind, data->img_mlx, 0, 0);
	return (0);
}
