/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:00:10 by asanson           #+#    #+#             */
/*   Updated: 2022/06/06 17:18:13 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_forward_back(t_data *data)
{
	if (data->mlx.forward == 1)
	{
		if (data->map[(int)(data->ray.posx + (data->ray.dirx
					* data->ray.movespeed * 2))][(int)data->ray.posy] != '1')
			data->ray.posx += data->ray.dirx * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			+ (data->ray.diry * data->ray.movespeed * 2))] == '0')
			data->ray.posy += data->ray.diry * data->ray.movespeed;
	}
	if (data->mlx.back == 1)
	{
		if (data->map[(int)(data->ray.posx - (data->ray.dirx
					* data->ray.movespeed * 2))][(int)data->ray.posy] != '1')
			data->ray.posx -= data->ray.dirx * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			- (data->ray.diry * data->ray.movespeed * 2))] == '0')
			data->ray.posy -= data->ray.diry * data->ray.movespeed;
	}
}

void	ft_left_right(t_data *data)
{
	if (data->mlx.right == 1)
	{
		if (data->map[(int)(data->ray.posx + (data->ray.diry
					* data->ray.movespeed * 2))][(int)data->ray.posy] != '1')
			data->ray.posx += data->ray.diry * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			- (data->ray.dirx * data->ray.movespeed * 2))] == '0')
			data->ray.posy -= data->ray.dirx * data->ray.movespeed;
	}
	if (data->mlx.left == 1)
	{
		if (data->map[(int)(data->ray.posx - (data->ray.diry
					* data->ray.movespeed * 2))][(int)data->ray.posy] != '1')
			data->ray.posx -= data->ray.diry * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			+ (data->ray.posx * data->ray.movespeed * 2))] == '0')
			data->ray.posy += data->ray.dirx * data->ray.movespeed;
	}
}

void	ft_rotate_left(t_data *data)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = data->ray.planx;
	olddirx = data->ray.dirx;
	if (data->mlx.rotate_left == 1)
	{
		data->ray.dirx = data->ray.dirx * cos(data->ray.rotspeed / 2)
			- data->ray.diry * sin(data->ray.rotspeed / 2);
		data->ray.diry = olddirx * sin(data->ray.rotspeed / 2)
			+ data->ray.diry * cos(data->ray.rotspeed / 2);
		data->ray.planx = data->ray.planx * cos(data->ray.rotspeed / 2)
			- data->ray.plany * sin(data->ray.rotspeed / 2);
		data->ray.plany = oldplanx * sin(data->ray.rotspeed / 2)
			+ data->ray.plany * cos(data->ray.rotspeed / 2);
	}
}

void	ft_rotate(t_data *data)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = data->ray.planx;
	olddirx = data->ray.dirx;
	if (data->mlx.rotate_right == 1)
	{
		data->ray.dirx = data->ray.dirx * cos(-data->ray.rotspeed / 2)
			- data->ray.diry * sin(-data->ray.rotspeed / 2);
		data->ray.diry = olddirx * sin(-data->ray.rotspeed / 2)
			+ data->ray.diry * cos(-data->ray.rotspeed / 2);
		data->ray.planx = data->ray.planx * cos(-data->ray.rotspeed / 2)
			- data->ray.plany * sin(-data->ray.rotspeed / 2);
		data->ray.plany = oldplanx * sin(-data->ray.rotspeed / 2)
			+ data->ray.plany * cos(-data->ray.rotspeed / 2);
	}
	ft_rotate_left(data);
}
