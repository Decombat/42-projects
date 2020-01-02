/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:34:59 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 12:29:54 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		len;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	len = 0;
	start = 0;
	end = ft_strlen(s);
	while (VD1(s[start]))
		start++;
	while (VD1(s[end - 1]))
		end--;
	if (!end)
		start = 0;
	if (!(new = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start < end)
		new[len++] = s[start++];
	new[len] = 0;
	return (new);
}
