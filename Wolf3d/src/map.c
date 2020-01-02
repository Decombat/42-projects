//map

#include "wolf.h"

void	ft_map(t_data *data)
{
	char *buff = ft_strnew(BUFF_SIZE + 1);
	char *line;
	int i = 0;
	int size = 0;
	data->max.x = 0;
	data->max.y = 0;

	while (read(data->fd, buff, BUFF_SIZE))
		while (buff[size])
			if (buff[size++] == '\n')
				data->max.y++;
	ft_strdel(&buff);
	data->max.x = size / data->max.y - 1;
	if (!(data->src = (Uint32 *)malloc(sizeof(Uint32) * (data->max.x * data->max.y))))
		return ;
	size = 0;
	while (get_next_line(data->fd_cop, &line))
	{
		while (line[i])
			data->src[size++] = line[i++] - '0' & 0xF;
		i = 0;
		ft_strdel(&line);
	}
}
