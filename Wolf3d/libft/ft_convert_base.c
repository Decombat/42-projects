/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:03:35 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 19:18:06 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_f(char *nbr, int *tab)
{
	int i;
	int base;

	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 1;
	tab[6] = 0;
	i = 0;
	base = 0;
	while (nbr[i])
	{
		if (nbr[i] > '9')
			nbr[i] = nbr[i] - 'a' + 10;
		else
			nbr[i] = nbr[i] - 48;
		i++;
	}
}

static void		ft_trad(char *base_from, char *nbr)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (nbr[n])
	{
		if (nbr[n] == base_from[i])
		{
			nbr[n] = i + '0';
			if (nbr[n] > '9')
				nbr[n] = nbr[n] + 39;
			n++;
			i = -1;
		}
		i++;
	}
}

static void		ft_rec(int *tab, char *str, int base, char *base_to)
{
	if (tab[4])
	{
		tab[4]--;
		if (base % tab[1] > 9)
			str[tab[4]] = base_to[base % tab[1]];
		else
			str[tab[4]] = base_to[base % tab[1]];
		ft_rec(tab, str, base / tab[1], base_to);
	}
}

static char		*ft_base(int base_o, int base, int *tab, char *base_to)
{
	char *str;

	while (base / tab[1] != 0)
	{
		base = base / tab[1];
		tab[4]++;
	}
	if (!(str = (char *)malloc(sizeof(char) * tab[4])))
		return (NULL);
	str[tab[4]] = '\0';
	ft_rec(tab, str, base_o, base_to);
	return (str);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	tab[7];
	int	base;

	tab[0] = 0;
	tab[1] = 0;
	tab[5] = 0;
	base = 0;
	ft_trad(base_from, nbr);
	if (!base_from || !base_to)
		return (NULL);
	while (base_from[tab[0]])
		tab[0]++;
	while (base_to[tab[1]])
		tab[1]++;
	while (nbr[tab[5]])
		tab[5]++;
	ft_f(nbr, tab);
	while (tab[2] < tab[5])
	{
		base = base + nbr[tab[2]];
		if (tab[2] + 1 != tab[5])
			base = base * tab[0];
		tab[2]++;
	}
	return (ft_base(base, base, tab, base_to));
}
