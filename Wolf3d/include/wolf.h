#ifndef WOLF_H
#define WOLF_H

# define ECRAN_Y 800
# define ECRAN_X 1300
# define THREAD 8

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <SDL2/SDL.h>
# include <SDL_image.h>
# include "../libft/includes/libft.h"
# include <pthread.h>

#include <stdint.h>

# define NAME "WOLF"

# define BLOCK 64.0
# define ANGLE 60.0
# define DIST_P 277
# define ECRAN_L 640
# define ECRAN_H 400
# define TEXTURE 0x01
# define RAD (180 / M_PI)
# define VIT 10

typedef struct s_pnt
{
	float x;
	float y;
}		t_pnt;

typedef struct s_pos
{
	int x;
	int y;
}		t_pos;

typedef struct	s_data
{
	t_pnt max;
	int fd;
	int fd_cop;
	Uint32 *src;
	t_pos pos;
	t_pnt mv;
	double angle;
	float	*hauteur;
}				t_data;

typedef struct s_sdl
{
	SDL_Window *screen;
	SDL_Renderer *render;
	SDL_Texture *texture;
	Uint32 *pixel;
	int *pitch;
}				t_sdl;

//clr
SDL_Texture		*ft_create_texture(SDL_Renderer *renderer);

//hook
void			ft_texture_test(t_data *data, t_sdl *sdl);
void    		ft_fullscreen(SDL_Window *screen, SDL_Event event);

//autres
void ft_erreur(int i);
void    ft_sprite(SDL_Window *screen, SDL_Renderer *rendu);

//map
void ft_map(t_data *data);
void print_bits(int octet);
void print_char(unsigned char octet);

//print
void print_bits(int octet);
void ft_printmap(t_data *data);
void print_char(unsigned char octet);
Uint32            ft_convert_rvb(t_rvb clr);

//ecran
void    ft_get_pos(t_data *data);
void ft_ecran(t_data *data);

void    ft_character(t_sdl *sdl);

#endif
