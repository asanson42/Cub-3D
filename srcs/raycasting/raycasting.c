/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:55:18 by asanson           #+#    #+#             */
/*   Updated: 2022/06/06 16:58:26 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_raycasting(t_data *data)
{
	data->ray.x = 0;
	while (data->ray.x < data->rx)
	{
		ft_init3(data);
		ft_stepsidedist(data);
		display_column(data);
		data->ray.x++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.mlx_win, data->mlx.img, 0, 0);
	ft_forward_back(data);
	ft_left_right(data);
	ft_rotate(data);
	ft_swap(data);
	return (0);
}

int	ft_mlx(t_data *data)
{
	ft_init2(data);
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		ft_error(data, "Mlx: Init Impossible");
	get_textures(data);
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->rx, data->ry);
	data->mlx.addr = (int *)mlx_get_data_addr(data->mlx.img,
			&data->mlx.bpp, &data->mlx.linelen, &data->mlx.endian);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_ptr,
			data->rx, data->ry, "CUB3D");
	data->mlx.img2 = mlx_new_image(data->mlx.mlx_ptr, data->rx, data->ry);
	data->mlx.addr2 = (int *)mlx_get_data_addr(data->mlx.img2,
			&data->mlx.bpp, &data->mlx.linelen, &data->mlx.endian);
	mlx_hook(data->mlx.mlx_win, 33, 1L << 17, ft_exit, data);
	mlx_hook(data->mlx.mlx_win, 2, 1L << 0, ft_keypress, data);
	mlx_loop_hook(data->mlx.mlx_ptr, ft_raycasting, data);
	mlx_hook(data->mlx.mlx_win, 3, 1L << 1, ft_keyrelease, data);
	mlx_loop(data->mlx.mlx_ptr);
	return (0);
}
