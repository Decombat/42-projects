/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:49:17 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 21:12:38 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print_fd(long n, int fd)
{
	if (n)
		ft_print_fd(n / 10, fd);
	if (n)
		ft_putchar_fd(n % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long cop;

	cop = (long)n;
	if (!cop)
		ft_putchar_fd('0', fd);
	if (cop < 0)
	{
		cop = -cop;
		ft_putchar_fd('-', fd);
	}
	ft_print_fd(cop, fd);
}
