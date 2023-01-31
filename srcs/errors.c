/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:08:52 by asanson           #+#    #+#             */
/*   Updated: 2022/06/07 15:41:42 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_data(t_data *data, char *str)
{
	int	i;

	i = -1;
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
	{
		while (++i < data->nbline)
			free(data->map[i]);
	}
	if (data->map)
		free(data->map);
	printf("Error: %s\n", str);
	exit(1);
}

void	ft_verify_errors(t_data *data)
{
	if (check_borders(data) == 1 || check_all(data))
		free_data(data, "Openned map");
	if (data->start == 'x' && data->wrongmapchar != 2)
		free_data(data, "No players in the map");
	if (data->c == 0 || data->f == 0)
		free_data(data, "Wrong data F or C");
	if (data->multiplayer == 1)
		free_data(data, "Too few players");
	if (data->emptyline == 1)
		free_data(data, "Empty line in the map");
	if (data->wrongmapchar == 2)
		free_data(data, "Wrong char in the map");
}

void	ft_error2(t_data *data)
{
	if (data->map)
		free(data->map);
	ft_exit(data);
}

void	ft_error(t_data *data, char *str)
{
	int	i;

	i = -1;
	data->indicator3 = 1;
	if (ft_strcmp(str, "Game Ended") != 0)
		write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	write(1, ".\n", 2);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
	{
		while (++i < data->nbline)
			free(data->map[i]);
	}
	ft_error2(data);
}

int	ft_exit(t_data *data)
{
	if (data->texture[0].img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->texture[0].img);
	if (data->texture[1].img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->texture[1].img);
	if (data->texture[2].img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->texture[2].img);
	if (data->texture[3].img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->texture[3].img);
	if (data->mlx.mlx_win)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img);
	if (data->mlx.img2)
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img2);
	if (data->mlx.mlx_ptr)
	{
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
	}
	exit(0);
}
