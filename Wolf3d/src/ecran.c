//ecran

#include "wolf.h"

float ft_compare_cmp(t_pnt cmp, t_pnt *diff, t_pos *pos, double rotate)
{
	int angle = rotate * (180 / M_PI);
	if (cmp.x < cmp.y)
	{
		diff->y *= ((cmp.y - cmp.x) / cmp.y);
		diff->x = BLOCK;
		pos->x += (angle < 90 || angle > 270) ? 1 : -1;
		return(cmp.x);
	}	
	else
	{	
		diff->x *= ((cmp.x - cmp.y) / cmp.x);
		diff->y = BLOCK;
		pos->y += (angle > 180) ? 1 : -1;
		return(cmp.y);
	}
}

void	ft_diff(t_pnt *diff, t_pnt mv, float angle)
{
	diff->x = ((angle < 90) || (angle > 270)) ? BLOCK - mv.x : mv.x;
	diff->y = ((angle < 180)) ? BLOCK - mv.y : mv.y;
}

float	ft_print_wall(t_pos r_check, t_data *data)
{        
	t_pnt diff;
	t_pnt cmp;
	double angle_r;
	float distance = 0;
	float hauteur = 0;	

	cmp.x = 0.0;
	cmp.y = 0.0;
	angle_r = data->angle / (180 / M_PI);
	ft_diff(&diff, data->mv, data->angle);
	while (!(data->src[(int)((r_check.y * data->max.x) + r_check.x)] & 0xF))
	{
		cmp.x = fabs(diff.x / (cos(angle_r) + 0.0001));
		cmp.y = fabs(diff.y / (sin(angle_r) + 0.0001));
		distance += ft_compare_cmp(cmp, &diff, &r_check, angle_r);
	}
	hauteur = BLOCK / distance * 277;
	return (hauteur);
}

void	ft_get_pos(t_data *data)
{
	data->pos.x = 0;
	data->pos.y = 0;
	while (data->src[data->pos.x])
		if (data->src[data->pos.x++] == '0')
			break ;
	while (data->pos.x > data->max.x)
	{
		data->pos.x -= data->max.x;
		data->pos.y++;
	}
}

void	ft_ecran(t_data *data)
{
	int champ_v = 0;
	float copie_angle = data->angle;

	while (champ_v <= ECRAN_L)
	{
		data->hauteur[champ_v] = ft_print_wall(data->pos, data);
		if (data->angle >= 360.0)
			data->angle -= 360.0;
		data->angle += ANGLE / ECRAN_L;
		champ_v++;
	}
	data->angle = copie_angle;		
}
