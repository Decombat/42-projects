/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/16 13:10:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char		*s;
	t_tetri		*lst_tetri;
	int			size;
	char		**map;

	if (ac != 2)
		return (0);
	size = 2;
	s = ft_readfd(av[1]);
	map = ft_map_new(size);
	lst_tetri = ft_atotet(s, 'A');
	ft_remove_extra_spaces(lst_tetri);
	while ((!ft_frame_check(map, lst_tetri, 0, 0)))
	{
		ft_map_free(map);
		map = ft_map_new(size++);
	}
	ft_map_print(map);
}
