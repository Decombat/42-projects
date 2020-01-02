/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:07:42 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 17:58:11 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	ft_transfer(long *n)
{
	char	c;

	c = *n % 10 + '0';
	*n = *n / 10;
	return (c);
}

static int	ft_negatif(long *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	else
		return (0);
}

char		*ft_itoa(int n)
{
	long	cop;
	int		neg;
	int		len;
	int		i;
	char	*new;

	i = 0;
	cop = (long)n;
	neg = ft_negatif(&cop);
	len = ft_lenint(cop) + neg;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = 0;
	if (neg)
		new[i++] = '-';
	while (len > i)
		new[--len] = ft_transfer(&cop);
	return (new);
}
