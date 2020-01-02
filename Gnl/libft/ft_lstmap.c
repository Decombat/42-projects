/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:32:40 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/12 12:23:09 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *copie;
	t_list *tmp;
	t_list *current;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		current = f(lst);
		if (tmp)
		{
			copie->next = current;
			copie = copie->next;
		}
		else
		{
			tmp = current;
			copie = tmp;
		}
		lst = lst->next;
	}
	return (tmp);
}
