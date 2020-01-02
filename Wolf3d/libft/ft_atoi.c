/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:57:57 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 20:14:09 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intmax(const char *str)
{
	char	*comp;
	int		int_max;
	int		c;

	c = 0;
	int_max = -2147483648;
	comp = "-2147483648";
	while (c <= 10)
	{
		if (str[c] == comp[c])
			c++;
		else
			return (0);
	}
	return (int_max);
}

int				ft_atoi(const char *str)
{
	int				n;
	int				c;
	int long		res;

	n = 0;
	c = 0;
	res = 0;
	if (ft_intmax(str))
		return (ft_intmax(str));
	while (VD(str[c]))
		c++;
	if (str[c] == '-')
		c = ++n + c;
	else if (str[c] == '+')
		c++;
	if (!ft_isdigit(str[c]))
		return (0);
	while (ft_isdigit(str[c]))
	{
		res = res * 10;
		res = res + str[c++] - '0';
	}
	if (n)
		return (res * -1);
	return (res);
}
