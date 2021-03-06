/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:38:26 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 16:22:58 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_open_file(int fd)
{
	t_lib	*data;
	t_space	add;

	add = ft_new_space(0, 0, 0, 0);
	if (!(data = (t_lib *)malloc(sizeof(t_lib))))
		return (0);
	data->init = mlx_init();
	data->wind = mlx_new_window(data->init, ECRAN_X, ECRAN_Y, "fdf");
	data->img_mlx = mlx_new_image(data->init, ECRAN_X, ECRAN_Y);
	data->img = mlx_get_data_addr(data->img_mlx, &data->bpp, &data->sz,
			&data->endian);
	data->spectre_max = 0.0;
	ft_new_shape(&data->map, fd);
	ft_parse(&data->map, add, &ft_add_iso);
	ft_get_ctr(&data->ctr, data->map);
	add.incr = ft_coef_color(data);
	data->coef = add.incr;
	ft_parse(&data->map, add, &ft_auto_color);
	ft_print_line(data->map, data);
	mlx_put_image_to_window(data->init, data->wind, data->img_mlx, 0, 0);
	mlx_key_hook(data->wind, key_hook, data);
	mlx_mouse_hook(data->wind, mouse_hook, data);
	mlx_loop(data->init);
	return (0);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		if (ac == 1)
			ft_putstr("usage: ./fdf [input_file]\n");
		else
			ft_putstr("usage: ./fdf [file]\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, NULL, 0)) < 0)
	{
		ft_putstr("usage: ./fdf [valid_file]\n");
		return (-1);
	}
	return (ft_open_file(fd));
}
