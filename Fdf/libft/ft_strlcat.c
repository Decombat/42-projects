/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:41:57 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 19:44:07 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	len;

	d = 0;
	s = 0;
	if (!size)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	while (dst[d] && d < size)
		d++;
	while (src[s] && d < size - 1)
		dst[d++] = src[s++];
	if (size && size >= len)
		dst[d] = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + len);
}
