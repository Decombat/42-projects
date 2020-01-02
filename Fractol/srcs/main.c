/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:17:55 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 16:22:43 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_lib	*data;

	if (ac != 2)
	{
		ft_putstr("usage: ./fractol [julia][mandelbrot][burningship]\n");
		exit(1);
	}
	if (!(data = (t_lib*)malloc(sizeof(t_lib))))
		return (0);
	data->init = mlx_init();
	data->wind = mlx_new_window(data->init, ECRAN_X, ECRAN_Y, "fractol");
	data->img_mlx = mlx_new_image(data->init, ECRAN_X, ECRAN_Y);
	data->img = mlx_get_data_addr(data->img_mlx,
									&data->bpp, &data->sz, &data->endian);
	data->color = 0.0;
	data->lum = 0.0;
	ft_init_event(av[1], data);
	ft_init_hooks(data);
	ft_to_window(data);
	mlx_loop(data->init);
	return (0);
}
