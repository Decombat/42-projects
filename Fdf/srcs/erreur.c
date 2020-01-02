/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:13:59 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 18:45:52 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_verif_line(char *line)
{
	if (!*line)
	{
		ft_putstr("usage: ./fdf [valid_file]\n");
		exit(1);
	}
}

void	ft_verif_tab(char **tab)
{
	static int param = 0;
	static int i = 0;

	param = i;
	i = 0;
	while (tab && tab[i])
		i++;
	if (!tab || (param && i != param))
	{
		ft_putstr("usage: ./fdf [valid_file]\n");
		exit(1);
	}
}
