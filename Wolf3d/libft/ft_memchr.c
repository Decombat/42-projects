/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:32:48 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/10 16:39:03 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*cp;

	len = 0;
	cp = (unsigned char *)s;
	while (len < n)
	{
		if (*cp == (unsigned char)c)
			return (cp);
		len++;
		cp++;
	}
	return (0);
}
