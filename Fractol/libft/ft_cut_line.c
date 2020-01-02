/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:43:33 by fedecomb          #+#    #+#             */
/*   Updated: 2018/09/25 15:52:53 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut_line(char *str, int len)
{
	int		size;
	int		c;
	char	*dst;

	c = 0;
	size = ft_strlen(str);
	dst = ft_strnew(size - len);
	while (len < size)
		dst[c++] = str[len++];
	dst[c] = 0;
	ft_strdel(&str);
	return (dst);
}
