/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:18:30 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/19 17:20:48 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ECRAN_Y 800
# define ECRAN_X 1300
# define THREAD 8
# define BLANK 200
# define RATIO_X 1
# define RATIO_Y 0.62

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <pthread.h>
# include "X.h"

typedef struct		s_event
{
	int				(*key)();
	int				(*mouse)();
	int				(*mouse_wheel)();
}					t_event;

typedef struct		s_cor
{
	double			x;
	double			y;
}					t_cor;

typedef struct		s_thr
{
	pthread_t		thread;
	t_cor			pix;
	t_cor			ctr;
	struct s_lib	*lib;
	struct s_thr	*next;
}					t_thr;

typedef struct		s_lib
{
	void			*init;
	void			*wind;
	void			*img_mlx;
	char			*img;
	int				bpp;
	int				sz;
	int				endian;
	double			echelle;
	double			precision;
	t_cor			add;
	t_thr			*thr;
	t_thr			*first;
	int				clic;
	t_event			event;
	int				state;
	t_cor			ctr;
	float			color;
	float			lum;
}					t_lib;

void				ft_new_cor(t_cor *new, float x, float y);
t_thr				*ft_new_thr(t_cor pix, t_cor ctr, t_lib *data);
void				ft_new_tsl(t_tsl *tsl, float t, float s, float l);

void				*ft_new_thread(void *add);
void				ft_print_pixel(t_lib *data);
void				ft_parse_pixel(t_cor pix, t_lib *data);
void				ft_create_thread(t_lib *data);

unsigned long		ft_convert_rvb(t_rvb clr);
void				ft_put_pixel(t_lib *data, int x, int y, int color);

void				ft_init_event(char *fractal, t_lib *data);
int					ft_keyboard_event(int keycode, t_lib *data);
void				ft_init_hooks(t_lib *data);
int					ft_to_window(t_lib *data);
int					ft_mouse_zoom_in(int z, int x, int y, t_lib *data);
int					ft_mouse_param(int x, int y, t_lib *data);
void				ft_key_color(int keycode, t_lib *data);
int					ft_key_zoom(int keycode, t_lib *data);

void				ft_burningship(t_lib *data);
void				ft_get_value(t_lib *data, double x, double y, int state);
int					ft_key_redirect(int keycode, t_lib *data);
void				ft_free_lib(t_lib *data);

#endif
