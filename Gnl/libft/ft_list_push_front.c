/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:58:17 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/15 16:31:50 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_front(t_list **begin_list,
			void *data, size_t content_size)
{
	t_list *start;

	if (!*begin_list)
		*begin_list = ft_create_elem(data, content_size);
	else
	{
		start = ft_create_elem(data, content_size);
		start->next = *begin_list;
		*begin_list = start;
	}
}
