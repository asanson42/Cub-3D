/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:54:50 by asanson           #+#    #+#             */
/*   Updated: 2022/06/06 17:17:13 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == FORWARD_W_Z)
		data->mlx.forward = 1;
	else if (keycode == BACK_S_S)
		data->mlx.back = 1;
	else if (keycode == LEFT_A_Q)
		data->mlx.left = 1;
	else if (keycode == RIGHT_D_D)
		data->mlx.right = 1;
	else if (keycode == ROTATE_LEFT)
		data->mlx.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		data->mlx.rotate_right = 1;
	else if (keycode == 65307)
		ft_error(data, "Game Ended");
	return (1);
}

int	ft_keyrelease(int keycode, t_data *data)
{
	if (keycode == FORWARD_W_Z)
		data->mlx.forward = 0;
	else if (keycode == BACK_S_S)
		data->mlx.back = 0;
	else if (keycode == LEFT_A_Q)
		data->mlx.left = 0;
	else if (keycode == RIGHT_D_D)
		data->mlx.right = 0;
	else if (keycode == ROTATE_LEFT)
		data->mlx.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		data->mlx.rotate_right = 0;
	return (1);
}
