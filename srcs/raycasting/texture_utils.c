/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:07:52 by asanson           #+#    #+#             */
/*   Updated: 2022/06/06 17:07:54 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_textures_addr(t_data *data)
{
	data->texture[0].addr = (int *)mlx_get_data_addr(data->texture[0].img,
			&data->texture[0].bpp, &data->texture[0].linelen,
			&data->texture[0].endian);
	data->texture[1].addr = (int *)mlx_get_data_addr(data->texture[1].img,
			&data->texture[1].bpp, &data->texture[1].linelen,
			&data->texture[1].endian);
	data->texture[2].addr = (int *)mlx_get_data_addr(data->texture[2].img,
			&data->texture[2].bpp, &data->texture[2].linelen,
			&data->texture[2].endian);
	data->texture[3].addr = (int *)mlx_get_data_addr(data->texture[3].img,
			&data->texture[3].bpp, &data->texture[3].linelen,
			&data->texture[3].endian);
}

void	get_textures(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->no, &data->texture[0].width, &data->texture[0].height);
	if (!data->texture[0].img)
		ft_error(data, "North texture");
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->so, &data->texture[1].width, &data->texture[1].height);
	if (!data->texture[1].img)
		ft_error(data, "South texture");
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->we, &data->texture[2].width, &data->texture[2].height);
	if (!data->texture[2].img)
		ft_error(data, "West texture");
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->ea, &data->texture[3].width, &data->texture[3].height);
	if (!data->texture[3].img)
		ft_error(data, "East texture");
	get_textures_addr(data);
}
