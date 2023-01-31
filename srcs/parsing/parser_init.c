/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:04:39 by mmahias           #+#    #+#             */
/*   Updated: 2022/06/06 17:06:11 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_more(t_data *data)
{
	data->start = 'x';
	data->multiplayer = 0;
	data->indicator2 = 0;
	data->indicator3 = 0;
	data->mlx.img = NULL;
	data->mlx.img2 = NULL;
	data->mlx.addr = NULL;
	data->mlx.addr2 = NULL;
	data->texture[0].img = NULL;
	data->texture[1].img = NULL;
	data->texture[2].img = NULL;
	data->texture[3].img = NULL;
	data->texture[4].img = NULL;
	data->mlx.mlx_win = NULL;
	data->map = NULL;
	data->mlx.bpp = 0;
	data->mlx.linelen = 0;
	data->mlx.endian = 0;
}

void	ft_init_dir(t_data *data)
{
	if (data->start == 'N')
		data->ray.dirx = -1;
	if (data->start == 'S')
		data->ray.dirx = 1;
	if (data->start == 'E')
		data->ray.diry = 1;
	if (data->start == 'W')
		data->ray.diry = -1;
	if (data->start == 'N')
		data->ray.plany = 0.66;
	if (data->start == 'S')
		data->ray.plany = -0.66;
	if (data->start == 'E')
		data->ray.planx = 0.66;
	if (data->start == 'W')
		data->ray.planx = -0.66;
}

void	ft_init_more3(t_data *data)
{
	if (data->ray.raydiry == 0)
		data->ray.deltadistx = 0;
	else if (data->ray.raydirx == 0)
		data->ray.deltadistx = 1;
	else
		data->ray.deltadistx = sqrt(1 + (data->ray.raydiry * \
		data->ray.raydiry) / (data->ray.raydirx * data->ray.raydirx));
	if (data->ray.raydirx == 0)
		data->ray.deltadisty = 0;
	else if (data->ray.raydiry == 0)
		data->ray.deltadisty = 1;
	else
		data->ray.deltadisty = sqrt(1 + (data->ray.raydirx * \
		data->ray.raydirx) / (data->ray.raydiry * data->ray.raydiry));
}

int	ft_emptyline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
			&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}
