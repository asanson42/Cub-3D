/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:57:17 by mmahias           #+#    #+#             */
/*   Updated: 2022/06/06 17:22:05 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_path_texture2(char **texture, t_data *data)
{
	if (*texture != NULL)
	{
		data->error = 2;
		return (1);
	}
	return (0);
}	

int	ft_path_texture(char *str, char **texture, t_data *data, int j)
{
	data->count2 = 0;
	if (ft_path_texture2(texture, data) == 1)
		return (0);
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0 \
			|| ft_strlen2(str) <= 2)
		data->error = 2;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			data->error = 2;
		j++;
	}
	*texture = malloc(sizeof(char *) * (ft_strlen2(str) + 1));
	if (!*texture)
		data->error = 2;
	while (str[j] != '\0')
	{
		(*texture)[data->count2] = str[j];
		data->count2++;
		j++;
	}
	(*texture)[data->count2] = '\0';
	return (0);
}

void	ft_texture(char *str, t_data *data)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &data->so, data, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &data->no, data, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &data->we, data, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &data->ea, data, 2);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' \
			&& str[0] != 'E' && str[0] != 'F' && str[0] != 'C' \
			&& str[0] > 65 && str[0] < 122)
		data->error = 2;
	j++;
}

void	ft_color_res(char **str, t_data *data)
{
	int	i;

	i = 0;
	data->i = 1;
	if (data->sizeline > 0 && (data->no == NULL || data->so == NULL \
				|| data->we == NULL || data->ea == NULL))
		data->error = 2;
	if ((data->no != NULL || data->so != NULL || data->we != NULL \
				|| data->ea != NULL) && (data->rx == 0 || data->ry == 0))
		data->error = 2;
	if (*str[i] == 'F')
		data->f = full_rgb(*str + i);
	else if (*str[i] == 'C')
		data->c = full_rgb(*str);
}
