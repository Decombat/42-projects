//autres

#include "wolf.h"

void	ft_character(t_sdl *sdl)
{
	SDL_Surface *image = IMG_Load("../../Desktop/knife.png");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl->render, image);
	//SDL_Rect dest = {ECRAN_L - image->w / 2, ECRAN_H - image->h / 2, image->w, image->h};
	SDL_Rect dest = {ECRAN_L - image->w / 2, ECRAN_H*2 - image->h, image->w, image->h};
	SDL_RenderCopy(sdl->render, texture, NULL, &dest);
}

void    ft_sprite(SDL_Window *screen, SDL_Renderer *rendu)
{
	SDL_Surface *image = SDL_LoadBMP("../../Desktop/image.bmp");
	int nbr_bits_p = image->format->BitsPerPixel;
	int w = 0;
	int h = 0;
	Uint16 *pix = (Uint16 *)image->pixels;
	while(w < (image->w  * image->h))
	{	
		if (h == image->w)
		{
			ft_putchar('\n');
			h = 0;
		}
		h++;
		w++;
	}		
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rendu, image);
	SDL_Rect dest = {ECRAN_L / 2 - image->w / 2, ECRAN_H / 2 - image->h / 2, image->w, image->h};
	SDL_RenderCopy(rendu, texture, NULL, &dest);
	SDL_RenderPresent(rendu);
}

void    ft_erreur(int i)
{
	if (i == 1)
		ft_putstr("usage: ./wolf3D [input_file]\n");
	else if (i == 2)
		ft_putstr("usage: ./wolf3D [valid_file]\n");
	else if (i == 3)
		ft_putstr("erreur SDL_Init");
	else if (i == 4)
		ft_putstr("erreur SDL_CreateWindow");
	else if (i == 5)
		ft_putstr("erreur malloc");
	exit(-1);
}
