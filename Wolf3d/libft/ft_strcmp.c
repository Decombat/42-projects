/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:01 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 19:16:08 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				c;
	unsigned char	*a;
	unsigned char	*b;

	c = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[c] == b[c] && a[c] && b[c])
		c++;
	return (a[c] - b[c]);
}
