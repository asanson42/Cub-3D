/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:06:19 by mmahias           #+#    #+#             */
/*   Updated: 2022/06/07 15:23:54 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_dupmap(char *str, t_data *data)
{
	static int	i = 0;
	int			j;

	j = 0;
	data->map[i] = NULL;
	data->map[i] = malloc(sizeof(char) * (data->sizeline + 1));
	while (str[j])
	{
		if (ft_start(str[j], data, i, j) == 1)
			data->map[i][j] = '0';
		else if (str[j] == ' ')
			data->map[i][j] = '1';
		else
			data->map[i][j] = str[j];
		j++;
	}
	while (j <= data->sizeline - 1)
	{
		data->map[i][j] = ' ';
		j++;
	}
	data->map[i][j] = '\0';
	i++;
	return (0);
}

int	ft_is_map(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
			&& str[i] != 'N' && str[i] != 'S' \
			&& str[i] != 'W' && str[i] != 'E' && str[i] != '\n' \
			&& str[i] != '\t')
			{
				if (data->insidemap == 1)
					data->wrongmapchar = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_data *data)
{
	int			i;
	static int	snbline = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, data) == 1)
	{
		if (data->f == -1 || data->c == -1 || data->no == NULL || \
				data->so == NULL || data->we == NULL || data->ea == NULL)
			data->error = 2;
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snbline = snbline + 1;
	}
	data->nbline = snbline;
	data->sizeline = ssizeline;
}
