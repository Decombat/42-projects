/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:55:36 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/11 14:16:02 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *copie;

	if (*alst && del)
	{
		copie = *alst;
		while (copie)
		{
			del(copie->content, copie->content_size);
			free(copie);
			copie = copie->next;
		}
		*alst = NULL;
	}
}
