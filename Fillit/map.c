/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:30:18 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/15 15:07:37 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_map_new(int size)
{
	char	**tab;
	int		size_y;
	int		size_x;
	int		cp;

	if (!size)
		return (NULL);
	size_y = size;
	size_x = size;
	if (!(tab = (char **)malloc(sizeof(char *) * (size_y + 1))))
		return (NULL);
	tab[size_y] = 0;
	while (size_y)
	{
		size_y--;
		if (!(tab[size_y] = (char *)malloc(sizeof(char) * (size_x + 1))))
			return (NULL);
		cp = size_x;
		tab[size_y][size_x] = 0;
		while (cp)
			tab[size_y][--cp] = '.';
	}
	return (tab);
}

void			ft_map_free(char **map)
{
	int len;

	len = 0;
	if (map)
	{
		while (map[len])
		{
			free(map[len]);
			map[len++] = NULL;
		}
		free(map);
		map = NULL;
	}
}

void			ft_map_print(char **map)
{
	int	len;

	len = 0;
	while (map[len])
	{
		ft_putstr(map[len++]);
		ft_putchar('\n');
	}
}
