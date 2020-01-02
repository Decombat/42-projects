/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_mots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:02:31 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 20:47:51 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_mots(char const *s, char c)
{
	int nbr_mots;
	int i;

	nbr_mots = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			nbr_mots++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nbr_mots);
}
