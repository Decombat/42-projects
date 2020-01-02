/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:58:51 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 19:34:00 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;

	len = 0;
	while (s[len])
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len++;
	}
	if ((char)c == '\0')
		return ((char *)&s[len]);
	return (0);
}
