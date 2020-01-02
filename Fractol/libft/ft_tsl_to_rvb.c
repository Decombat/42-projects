/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tsl_to_rvb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:06:50 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/09 13:11:31 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_rvb					ft_cr_col(float a, float b, float c)
{
	t_rvb clr;

	clr.r = a * 255.0;
	clr.v = b * 255.0;
	clr.b = c * 255.0;
	return (clr);
}

t_rvb							ft_tsl_to_rvb(t_tsl tsl)
{
	double i;
	double f;
	double p;
	double q;
	double t;

	i = floor(tsl.t * 6.0);
	f = tsl.t * 6.0 - i;
	p = tsl.l * (1.0 - tsl.s);
	q = tsl.l * (1.0 - f * tsl.s);
	t = tsl.l * (1.0 - (1.0 - f) * tsl.s);
	if (i == 0)
		return (ft_cr_col(tsl.l, t, p));
	else if (i == 1)
		return (ft_cr_col(q, tsl.l, p));
	else if (i == 2)
		return (ft_cr_col(p, tsl.l, t));
	else if (i == 3)
		return (ft_cr_col(p, q, tsl.l));
	else if (i == 4)
		return (ft_cr_col(t, p, tsl.l));
	else
		return (ft_cr_col(tsl.l, p, q));
}
