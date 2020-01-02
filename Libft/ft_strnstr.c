/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:40 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 19:14:34 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int c;

	i = 0;
	c = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[c])
		{
			while (haystack[i++] == needle[c++])
			{
				if (!needle[c] && i <= len)
					return ((char *)&haystack[i - c]);
			}
			i = i - c;
			c = 0;
		}
		i++;
	}
	return (0);
}
