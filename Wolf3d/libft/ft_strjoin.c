/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:38:41 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/12 12:39:32 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len_new;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	len_new = 0;
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		new[len_new++] = s1[len_s1++];
	while (s2[len_s2])
		new[len_new++] = s2[len_s2++];
	new[len_new] = 0;
	return (new);
}
