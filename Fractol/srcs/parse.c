/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:18:04 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 16:18:02 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_carre(t_cor *pnt2, t_cor *add, t_tsl *tsl, int state)
{
	t_cor		pnt1;

	pnt1.x = (pnt2->x * pnt2->x) - (pnt2->y * pnt2->y);
	pnt1.y = 2.0 * pnt2->x * pnt2->y;
	if (state == 4)
	{
		pnt1.x = (fabs(pnt2->x * pnt2->x) - (pnt2->y * pnt2->y)) - add->x;
		pnt1.y = -fabs(pnt1.y) - add->y;
	}
	else
	{
		pnt1.x += add->x;
		pnt1.y += add->y;
	}
	tsl->t += exp(-(sqrt(pnt2->x * pnt2->x + pnt2->y * pnt2->y)));
	*pnt2 = pnt1;
}

void			ft_parse_pixel(t_cor pix, t_lib *data)
{
	t_tsl		tsl;
	t_cor		pnt;
	t_cor		add;
	int			i;

	i = 0;
	pnt.x = data->ctr.x + ((2 * pix.x / ECRAN_X) - RATIO_X) * data->echelle;
	pnt.y = data->ctr.y + ((2 * pix.y / ECRAN_X) - RATIO_Y) * data->echelle;
	if (!data->state || data->state == 4)
		ft_new_cor(&add, pnt.x, pnt.y);
	else
		add = data->add;
	ft_new_tsl(&tsl, exp(-(sqrt(pnt.x * pnt.x + pnt.y * pnt.y))), 1.0, 1.0);
	tsl.t += data->color;
	while (i++ <= data->precision && sqrt(pnt.x * pnt.x + pnt.y * pnt.y) < 4)
		ft_carre(&pnt, &add, &tsl, data->state);
	tsl.t /= data->precision;
	if (tsl.t >= 1.0)
		tsl.t -= 0.99;
	else if (tsl.t <= 0.0)
		tsl.t += 0.99;
	tsl.l += data->lum;
	ft_put_pixel(data, pix.x, pix.y, mlx_get_color_value(data->wind,
				ft_convert_rvb(ft_tsl_to_rvb(tsl))));
}

void			*ft_new_thread(void *add)
{
	t_thr		*data;
	float		y;

	data = add;
	y = data->pix.y;
	while (data->pix.y < (y + 100.0))
	{
		while (data->pix.x <= ECRAN_X)
		{
			ft_parse_pixel(data->pix, data->lib);
			data->pix.x++;
		}
		data->pix.x = 0;
		data->pix.y += 1.0;
	}
	pthread_exit(NULL);
}

void			ft_create_thread(t_lib *data)
{
	t_thr	*cop;

	while (data->thr)
		if (!(pthread_create(
						&data->thr->thread, NULL, ft_new_thread, data->thr)))
			data->thr = data->thr->next;
	data->thr = data->first;
	while (data->thr)
	{
		pthread_join(data->thr->thread, NULL);
		cop = data->thr;
		data->thr = data->thr->next;
		free(cop);
	}
}

void			ft_print_pixel(t_lib *data)
{
	t_cor		pix;

	data->thr = NULL;
	ft_new_cor(&pix, 0.0, 0.0);
	while (pix.y < ECRAN_Y)
	{
		if (!data->thr)
		{
			data->first = NULL;
			data->thr = ft_new_thr(pix, data->ctr, data);
			data->first = data->thr;
		}
		else
		{
			data->thr->next = ft_new_thr(pix, data->ctr, data);
			data->thr = data->thr->next;
		}
		pix.y += 100.0;
	}
	data->thr = data->first;
	ft_create_thread(data);
}
