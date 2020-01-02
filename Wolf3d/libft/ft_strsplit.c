/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:56:44 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/31 12:41:57 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_separateur_chaine(char const *s, int mots, char c)
{
	int				i;
	int				cp;
	size_t			len;
	char			*str;

	i = 0;
	cp = 0;
	len = 0;
	str = NULL;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (cp == mots)
		{
			while (s[len + i] != c && s[len])
				len++;
			str = ft_strsub(s, i, len);
			break ;
		}
		cp++;
		while (s[i] != c)
			i++;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		mots;
	int		i;
	char	**tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	mots = ft_nbr_mots(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (mots + 1))))
		return (NULL);
	tab[mots] = NULL;
	while (i < mots)
	{
		tab[i] = ft_separateur_chaine(s, i, c);
		i++;
	}
	return (tab);
}
