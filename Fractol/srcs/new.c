/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:18:00 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 16:21:04 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_thr		*ft_new_thr(t_cor pix, t_cor ctr, t_lib *data)
{
	t_thr	*thr;

	if (!(thr = (t_thr *)malloc(sizeof(t_thr))))
		return (NULL);
	thr->pix = pix;
	thr->ctr = ctr;
	thr->lib = data;
	thr->next = NULL;
	return (thr);
}

void		ft_new_tsl(t_tsl *tsl, float t, float s, float l)
{
	tsl->t = t;
	tsl->s = s;
	tsl->l = l;
}

void		ft_new_cor(t_cor *new, float x, float y)
{
	new->x = x;
	new->y = y;
}

void		ft_free_lib(t_lib *data)
{
	mlx_destroy_image(data->init, data->img_mlx);
	mlx_destroy_window(data->init, data->wind);
	free (data);
}
