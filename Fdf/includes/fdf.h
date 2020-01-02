/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:27:19 by fedecomb          #+#    #+#             */
/*   Updated: 2018/10/02 17:25:07 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# define JAUNE 16776960

# define ECRAN_Y 900
# define ECRAN_X 1440

typedef struct	s_ctr
{
	int			max;
	int			min;
}				t_ctr;

typedef struct	s_rec
{
	t_ctr		x;
	t_ctr		y;
	t_ctr		h;
}				t_rec;

typedef struct	s_cor
{
	float			x;
	float			y;
	float			h;
	int				e;
	t_tsl			color;
	struct s_cor	*next;
	struct s_cor	*first;
}				t_cor;

typedef struct	s_map
{
	t_cor			*cor;
	struct s_map	*next;
	struct s_map	*first;
}				t_map;

typedef struct	s_lib
{
	void			*init;
	void			*wind;
	t_map			*map;
	t_rec			ctr;
	void			*img_mlx;
	char			*img;
	int				bpp;
	int				sz;
	int				endian;
	float			coef;
	float			spectre_max;
}				t_lib;

typedef struct	s_space
{
	int				x;
	int				y;
	int				h;
	float			incr;
}				t_space;

int				ft_open_file(int fd);

t_cor			*ft_new_cor(float x, float y, float h, t_cor *first);
t_map			*ft_new_map(t_cor *content, t_map *first);
t_space			ft_new_space(int x, int y, int h, float incr);
void			ft_new_shape(t_map **map, int fd);

int				key_hook(int key, t_lib *data);
int				mouse_hook(int button, int x, int y, t_lib *data);

void			ft_print_line(t_map *map, t_lib *data);
void			ft_line(t_cor *a, t_cor *b, t_lib *data, t_space add);
void			ft_put_pixel(t_lib *data, int x, int y, int color);

void			ft_move_shape(t_map **map, t_space add);
void			ft_add_iso(t_map **map, t_space add);
void			ft_parse(t_map **map, t_space add,
		void			(*ft)(t_map **, t_space));
void			ft_zoom_shape(t_map **map, t_space add);

int				ft_abs(int c);
void			ft_list_first(t_map **map);
void			ft_get_ctr(t_rec *d, t_map *map);
void			ft_swap_cor(t_cor **a, t_cor **b);
int				ft_dif_hauteur(float a, float b);

unsigned long	ft_convert_rvb(t_rvb clr);

float			ft_coef_color(t_lib *data);
void			ft_auto_color(t_map **map, t_space add);
void			ft_valid_shape(t_map **map, t_space add);
void			ft_print_color(t_cor a, t_cor b, double *teinte, float i);

void			ft_verif_line(char *line);
void			ft_verif_tab(char **tab);

#endif
