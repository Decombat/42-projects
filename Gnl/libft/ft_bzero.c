/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:23:26 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/14 20:49:10 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			c;
	unsigned char	*cp;

	c = 0;
	cp = (unsigned char *)s;
	while (c < n)
		cp[c++] = 0;
}
