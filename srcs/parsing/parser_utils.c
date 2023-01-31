/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:08:50 by mmahias           #+#    #+#             */
/*   Updated: 2022/06/07 14:43:50 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_start(char c, t_data *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->start != 'x')
			data->multiplayer = 1;
		data->start = c;
		data->dx = i;
		data->dy = j;
		return (1);
	}
	return (0);
}

void	ft_init(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = -1;
	data->c = -1;
	data->rx = 1280;
	data->ry = 720;
	data->nbline = 0;
	data->sizeline = 0;
	data->map = NULL;
	data->dx = 0;
	data->dy = 0;
	data->emptyline = 0;
	data->insidemap = 0;
	data->count = 0;
	data->wrongmapchar = 0;
	ft_init_more(data);
}
