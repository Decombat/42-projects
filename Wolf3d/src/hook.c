//hok

#include "wolf.h"

t_tsl	ft_define_tsl(float t, float s, float l)
{
	t_tsl tsl;
	tsl.t = t;
	tsl.s = s;
	tsl.l = l;
	return tsl;
}

void		ft_print_uint(Uint32 bit)
{
	int x = 0;
	while (x <= 32)
	{
		if ((bit & 0x1) == 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		bit = bit >> 1;
		x++;
	}
}

void	ft_texture_test(t_data *data, t_sdl *sdl)
{

	int x = 0;
	int y = 0;
	int h = 0;
	t_tsl mur = ft_define_tsl(0.4, 1.0, 1.0);
	t_tsl sol = ft_define_tsl(0.1, 0.0, 0.5);
	t_tsl sky = ft_define_tsl(0.6, 1.0, 1.0);

	while (x < ECRAN_L)
	{
		if ((int)data->hauteur[x] < ECRAN_H)
			h = (ECRAN_H - (int)data->hauteur[x]) / 2;
		else
			h = 0;	
		while (y < ECRAN_H)
		{
			if (y > h && y < (ECRAN_H - h))
				sdl->pixel[y * ECRAN_L + x] = (Uint32)ft_convert_rvb(ft_tsl_to_rvb(mur));
			else if (y < h)
				sdl->pixel[y * ECRAN_L + x] = (Uint32)ft_convert_rvb(ft_tsl_to_rvb(sky));
			else if (y > (ECRAN_H - h))
				sdl->pixel[y * ECRAN_L + x] = (Uint32)ft_convert_rvb(ft_tsl_to_rvb(sol));
			y++;
		}
		y = 0;
		x++;
	}
	SDL_UpdateTexture(sdl->texture, 0, sdl->pixel, ECRAN_L * 4 );
	SDL_RenderCopy(sdl->render, sdl->texture, NULL, NULL);
	ft_character(sdl);
	SDL_RenderPresent(sdl->render);
}

void    ft_fullscreen(SDL_Window *screen, SDL_Event event)
{
	static int      fs = 0;

	if (!fs)
		SDL_SetWindowFullscreen(screen, SDL_WINDOW_FULLSCREEN_DESKTOP);
	else if (fs)
		SDL_SetWindowFullscreen(screen, 0);
	fs = (fs == 1) ? 0 : 1;
}
