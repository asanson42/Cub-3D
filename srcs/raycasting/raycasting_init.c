/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:58:33 by asanson           #+#    #+#             */
/*   Updated: 2022/06/06 17:00:04 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init2(t_data *data)
{
	data->mlx.forward = 0;
	data->mlx.back = 0;
	data->mlx.left = 0;
	data->mlx.right = 0;
	data->mlx.rotate_right = 0;
	data->mlx.rotate_left = 0;
	data->ray.posx = (double)data->dx + 0.5;
	data->ray.posy = (double)data->dy + 0.5;
	data->ray.dirx = 0;
	data->ray.diry = 0;
	data->ray.planx = 0;
	data->ray.plany = 0;
	ft_init_dir(data);
}

void	ft_init3(t_data *data)
{
	data->ray.hit = 0;
	data->ray.perpwalldist = 0;
	data->ray.camerax = 2 * data->ray.x / (double)data->rx - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planx * data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.plany * data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	data->ray.movespeed = 0.1;
	data->ray.rotspeed = 0.033 * 1.8;
	ft_init_more3(data);
}

void	ft_init_textures(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydirx < 0)
		data->t.texdir = 0;
	if (data->ray.side == 0 && data->ray.raydirx >= 0)
		data->t.texdir = 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->t.texdir = 2;
	if (data->ray.side == 1 && data->ray.raydiry >= 0)
		data->t.texdir = 3;
	if (data->ray.side == 0)
		data->t.wallx = data->ray.posy + data->ray.perpwalldist
			* data->ray.raydiry;
	else
		data->t.wallx = data->ray.posx + data->ray.perpwalldist
			* data->ray.raydirx;
	data->t.wallx -= floor(data->t.wallx);
}

void	ft_launch(t_data *data)
{
	ft_verify_errors(data);
	ft_mlx(data);
}
