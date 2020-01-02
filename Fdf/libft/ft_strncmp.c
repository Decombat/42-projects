/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:28 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 20:07:45 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			c;
	unsigned char	*a;
	unsigned char	*b;

	c = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (!n)
		return (0);
	while (a[c] == b[c] && c + 1 < n && a[c] && b[c])
		c++;
	return (a[c] - b[c]);
}
