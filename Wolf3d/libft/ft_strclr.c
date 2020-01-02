/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:45:18 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/12 12:35:43 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	c;

	if (s)
	{
		c = ft_strlen(s);
		while (c >= 0)
			s[c--] = '\0';
	}
}
