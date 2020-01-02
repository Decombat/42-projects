/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:33 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 19:15:15 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t c;

	c = 0;
	while (c < len)
	{
		if (src[c])
			dst[c] = src[c];
		else
		{
			while (c < len)
				dst[c++] = 0;
			return (dst);
		}
		c++;
	}
	return (dst);
}
