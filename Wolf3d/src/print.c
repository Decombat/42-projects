//print

#include "wolf.h"

Uint32       ft_convert_rvb(t_rvb clr)
{
	return ((((unsigned char)clr.r & 0xFF) << 16) +
			(((unsigned char)clr.v & 0xFF) << 8) +
			(((unsigned char)clr.b & 0xFF) << 0));
}


void    print_bits(int octet)
{
	int oct = octet;
	oct = (((oct & 0xaaaaaaaa) >> 1) | ((oct & 0x55555555) << 1));
	oct = (((oct & 0xcccccccc) >> 2) | ((oct & 0x33333333) << 2));
	oct = (((oct & 0xf0f0f0f0) >> 4) | ((oct & 0x0f0f0f0f) << 4));
	oct = (((oct & 0xff00ff00) >> 8) | ((oct & 0x00ff00ff) << 8));
	int size = sizeof(int) * 4;
	while (size)
	{
		if ((oct & 0x1) == 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		oct = oct >> 1;
		size--;
	}
	ft_putchar(' ');
}

void    ft_printmap(t_data *data)
{
	int x = 0, y = 0;

	while (y < (data->max.x * data->max.y))			
	{
		ft_putnbr(data->src[y++] & 0xF);
		x++;
		if (x == data->max.x)
		{
			x = 0;
			ft_putchar('\n');
		}
	}
}

void    print_char(unsigned char octet)
{
	int z = 128, oct = octet;

	while (z > 0)
	{
		if (oct & z)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		z >>= 1;
	}
	ft_putchar(' ');
}
