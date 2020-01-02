/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:25:24 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/16 19:29:39 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZ 21* 26

typedef struct			s_position
{
	int					x;
	int					y;
	struct s_position	*next;
}						t_position;

typedef struct			s_tetri
{
	t_position			*pa;
	t_position			*pb;
	t_position			*pc;
	t_position			*pd;
	int					placed;
	struct s_tetri		*next;
	char				letter;
}						t_tetri;

char					*ft_readfd(char *str);

char					**ft_map_new(int size);
void					ft_map_free(char **map);
void					ft_map_print(char **map);

void					ft_fdtotetris(int fd);
t_tetri					*ft_atotet(char *str, char letter);
t_tetri					*new_tetri(void);
t_tetri					*ft_tetri_add_pos(t_tetri *tetri, char *str);
int						ft_is_tetri_valid(t_tetri *tetri);
void					ft_remove_extra_spaces(t_tetri *tetri);

t_position				*new_position(int x, int y);
t_position				*ft_itopos(t_position *pos, int i, int j);
int						ft_are_pos_adj(t_tetri *t, t_position *p);
int						ft_check_char(char *str, int i, int j, int k);

int						ft_check_and_place(char **frame, t_tetri *elem,
						int x, int y);
int						ft_frame_check(char **frame, t_tetri *elem,
						int x, int y);
void					ft_frame_remove(char **frame, t_tetri *elem,
						int x, int y);
#endif
