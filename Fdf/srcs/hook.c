/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:34:19 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 16:23:57 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_pers(int key, t_lib *data)
{
	t_space		add;

	add = ft_new_space(0, 0, 0, 0);
	if (key == 0x7b || key == 0x7c)
		add.x = (key == 0x7c) ? 10 : -10;
	if (key == 0x1b || key == 0x18)
		add.h = (key == 0x18) ? 1 : -1;
	if (key == 0x7d || key == 0x7e)
		add.y = (key == 0x7d) ? 10 : -10;
	ft_parse(&data->map, add, &ft_move_shape);
	return (1);
}

static int	key_autres(int key, t_lib *data)
{
	static int	cmp = 0;
	t_space		add;

	if (cmp <= 5 && key == 0x0c)
	{
		cmp++;
		add = ft_new_space(0, 0, 0, 2.0);
		ft_parse(&data->map, add, &ft_zoom_shape);
		ft_get_ctr(&data->ctr, data->map);
	}
	if (cmp > 0 && key == 0x0d)
	{
		cmp--;
		add = ft_new_space(0, 0, 0, -2.0);
		ft_parse(&data->map, add, &ft_zoom_shape);
		ft_get_ctr(&data->ctr, data->map);
	}
	if (key == 0x01)
	{
		add = ft_new_space(0, 0, 0, data->coef);
		data->spectre_max += (data->spectre_max < 1.0) ? 0.05 : -1.0;
		data->coef = ft_coef_color(data);
		ft_parse(&data->map, add, &ft_auto_color);
	}
	return (1);
}

int			key_hook(int key, t_lib *data)
{
	ft_bzero((void*)data->img, data->sz * ECRAN_Y);
	if (key == 0x1b || key == 0x18 || key == 0x7d ||
			key == 0x7e || key == 0x7b || key == 0x7c)
		key_pers(key, data);
	if (key == 0x0c || key == 0x0d || key == 0x01 || key == 0x02)
		key_autres(key, data);
	if (key == 0x35)
	{
		mlx_destroy_window(data->init, data->wind);
		exit(0);
	}
	ft_print_line(data->map, data);
	mlx_put_image_to_window(data->init, data->wind, data->img_mlx, 0, 0);
	return (0);
}

static void	ft_mouse_line(t_cor *i, int x, int y)
{
	static float teinte = 0.0;
	static float satur = 0.0;

	i->x = x;
	i->y = y;
	i->h = 0;
	i->color.t = teinte;
	i->color.s = satur;
	i->color.l = 1.0;
	teinte += 0.1;
	satur += 0.2;
}

int			mouse_hook(int button, int x, int y, t_lib *data)
{
	static t_cor	pnt_1;
	static t_cor	pnt_2;
	static int		select = 0;
	t_space			add;

	add = ft_new_space(0, 0, 0, 0);
	if (button == 1 && !select)
	{
		ft_mouse_line(&pnt_1, x, y);
		select = 1;
	}
	else if (button == 1 && select)
	{
		ft_mouse_line(&pnt_2, x, y);
		ft_line(&pnt_1, &pnt_2, data, add);
		mlx_put_image_to_window(data->init, data->wind, data->img_mlx, 0, 0);
		select = 0;
	}
	return (1);
}
