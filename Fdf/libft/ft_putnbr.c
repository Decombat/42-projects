/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:51:38 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 21:08:40 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print(long n)
{
	if (n)
		ft_print(n / 10);
	if (n)
		ft_putchar(n % 10 + '0');
}

void			ft_putnbr(int n)
{
	long cop;

	cop = (long)n;
	if (!cop)
		ft_putchar('0');
	if (cop < 0)
	{
		cop = -cop;
		ft_putchar('-');
	}
	ft_print(cop);
}
