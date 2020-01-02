/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:54 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/10 19:36:13 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int c;

	i = 0;
	c = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[c])
		{
			while (haystack[i++] == needle[c++])
			{
				if (!needle[c])
					return ((char *)&haystack[i - c]);
			}
			i = i - c;
			c = 0;
		}
		i++;
	}
	return (0);
}
