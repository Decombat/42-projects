//main

#include "wolf.h"

static void    ft_spr(SDL_Window *screen, SDL_Renderer *rendu)
{
	SDL_Surface *image = SDL_LoadBMP("../../Desktop/3.bmp");
	int nbr_bits_p = image->format->BitsPerPixel;
	int w = 0;
	int h = 0;
	Uint8 *pix = (Uint8 *)image->pixels;
	while(w < (image->w  * image->h))
	{	
		if (h == image->w)
                {
                        ft_putchar('\n');
                        h = 0;
                }
		ft_putnbr((int)pix[w] & 0x01);	
		ft_putstr(" ");
		h++;
		w++;
	}		
	exit(1);
}

int    ft_event(t_data *data, t_sdl *sdl)
{
	SDL_Event	event;
	t_pnt		add;

	while (SDL_PollEvent(&event))	
	{
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			data->angle += (data->angle < 360.0) ? 1.0 + 5 : -360.0 + 5;
			ft_ecran(data);
			ft_texture_test(data, sdl);
		}
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			data->angle -= (data->angle > 0) ? 1 + 5 : -360 + 5;
			ft_ecran(data);
			ft_texture_test(data, sdl);
		}
		if (event.key.keysym.sym == SDLK_UP)
		{
			add.x = cos((data->angle + 30) / RAD) * VIT;
			add.y = sin((data->angle + 30) / RAD) * VIT;
			
			data->mv.x += add.x;
			data->mv.y += add.y;

			if (data->mv.x < 0)
			{
				if ((data->src[(int)(data->pos.x - 1 + data->pos.y * data->max.x)] & 0xF))
					data->mv.x -= add.x;
				else
				{	
					data->mv.x += BLOCK;
					data->pos.x--;
				}					
			}
			else if (data->mv.x >= BLOCK)
			{
				if ((data->src[(int)(data->pos.x + 1 + data->pos.y * data->max.x)] & 0xF))
					data->mv.x -= add.x;
				else
				{
					data->mv.x -= BLOCK;
					data->pos.x++;
				}
			}
			if (data->mv.y < 0)
			{
				if ((data->src[(int)(data->pos.x + (data->pos.y + 1) * data->max.x)] & 0xF))
					data->mv.y -= add.y;
				else
				{	
					data->mv.y += BLOCK;
					data->pos.y++;
				}					
			}
			else if (data->mv.y >= BLOCK)
			{
				if ((data->src[(int)(data->pos.x + (data->pos.y - 1) * data->max.x)] & 0xF))
					data->mv.y -= add.y;
				else
				{
					data->mv.y -= BLOCK;
					data->pos.y--;
				}
			}
			ft_ecran(data);
			ft_texture_test(data, sdl);
		}
		if (event.key.keysym.sym == SDLK_x)
			ft_spr(sdl->screen, sdl->render);
		if (event.key.keysym.sym == SDLK_f)
			ft_fullscreen(sdl->screen, event);
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			return (0);
		if (event.type == SDL_QUIT)
			return (0);
	}
	return (1);
}

int     main(int ac, char **av)
{
	t_data			*data;
	t_sdl			*sdl;
	Uint32			flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

	if (ac != 2)
		ft_erreur(1);
	if (!(sdl = (t_sdl *)malloc(sizeof(t_sdl))))
		ft_erreur(5);
	if (!(sdl->pixel = (Uint32 *)malloc(sizeof(Uint32) * (ECRAN_H * ECRAN_L))))
		ft_erreur(5);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_erreur(5);
	data->fd = open(av[1], O_RDONLY);
	data->fd_cop = open(av[1], O_RDONLY);
	if (data->fd < 0 || (read(data->fd, NULL, 0)) < 0)
		ft_erreur(2);
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_erreur(3);
	if (!(sdl->screen = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, ECRAN_L * 2, ECRAN_H * 2, flags)))
		ft_erreur(4);
	sdl->render = SDL_CreateRenderer(sdl->screen, -1, SDL_RENDERER_ACCELERATED);
	sdl->texture = SDL_CreateTexture(sdl->render, SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STREAMING, ECRAN_L, ECRAN_H);
	if (!(data->hauteur = (float *)malloc(sizeof(float) * ECRAN_L)))
		ft_erreur(5);
	ft_map(data);
	data->angle = 0.0;
	data->mv.x = BLOCK/2;
	data->mv.y = BLOCK/2;
	ft_get_pos(data);
	ft_ecran(data);
	ft_texture_test(data, sdl);
	while (ft_event(data, sdl))
	{}
	SDL_DestroyTexture(sdl->texture);
	SDL_DestroyRenderer(sdl->render);
	SDL_DestroyWindow(sdl->screen);
	SDL_Quit();
	return (0);
}
