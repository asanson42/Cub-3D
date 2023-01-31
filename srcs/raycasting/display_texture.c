/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:54:34 by asanson           #+#    #+#             */
/*   Updated: 2022/06/06 16:54:36 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	display_texture(t_data *data, int x, int y)
{
	y = data->ray.drawstart - 1;
	ft_init_textures(data);
	data->t.step = 1.0 * data->texture[0].height / data->ray.lineheight;
	data->t.texx = (int)(data->t.wallx
			* (double)data->texture[data->t.texdir].width);
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		data->t.texx = data->texture[data->t.texdir].width - data->t.texx - 1;
	if (data->ray.side == 1 && data->ray.raydirx < 0)
		data->t.texx = data->texture[data->t.texdir].width - data->t.texx - 1;
	data->t.texpos = (data->ray.drawstart - data->ry / 2
			+ data->ray.lineheight / 2) * data->t.step;
	while (++y <= data->ray.drawend)
	{
		data->t.texy = (int)data->t.texpos
			& (data->texture[data->t.texdir].height - 1);
		data->t.texpos += data->t.step;
		if (y < data->ry && x < data->rx)
			data->mlx.addr[y * data->mlx.linelen / 4 + x]
				= data->texture[data->t.texdir].addr[data->t.texy
				* data->texture[data->t.texdir].linelen / 4 + data->t.texx];
	}
}

int	display_column(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	data->ray.drawend = data->ry - data->ray.drawstart;
	i = data->ray.drawend;
	while (++j < data->ray.drawstart)
		data->mlx.addr[j * data->mlx.linelen / 4 + data->ray.x] = data->c;
	if (j <= data->ray.drawend)
		display_texture(data, data->ray.x, j);
	j = i;
	while (++j < data->ry)
		data->mlx.addr[j * data->mlx.linelen / 4 + data->ray.x] = data->f;
	return (0);
}
