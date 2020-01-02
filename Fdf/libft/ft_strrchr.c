/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:47 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/12 12:28:09 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[len])
	{
		if (s[len] == (char)c)
			i = len + 1;
		len++;
	}
	if ((char)c == '\0')
		return ((char *)&s[len]);
	if (i)
		return ((char *)&s[i - 1]);
	return (0);
}
