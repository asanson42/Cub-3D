/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:58:47 by asanson           #+#    #+#             */
/*   Updated: 2022/06/07 15:36:57 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	borders_utils(t_data *m, int i)
{
	while (i < m->nbline - 1)
	{
		if (!((m->map[i][0] == '1' || m->map[i][0] == ' ')
			&& (m->map[i][m->sizeline - 1] == '1'
			|| m->map[i][m->sizeline - 1] == ' ')))
			return (1);
		i++;
	}
	return (0);
}

int	check_borders(t_data *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map[i][j])
	{
		if (!(map->map[i][j] == '1' || map->map[i][j] == ' '))
			return (1);
		j++;
	}
	if (borders_utils(map, i) == 1)
		return (1);
	j = 0;
	while (j < map->sizeline)
	{
		if (!(map->map[map->nbline - 1][j] == '1'
			|| map->map[map->nbline - 1][j] == ' '))
			return (1);
		j++;
	}
	return (0);
}

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == ' ' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_space(t_data *map, int x, int y)
{
	if (x != 0)
		if (map->map[x - 1][y] != '1' && map->map[x - 1][y] != ' ')
			return (0);
	if (x != map->nbline - 1)
		if (map->map[x + 1][y] != '1' && map->map[x + 1][y] != ' ')
			return (0);
	if (y != 0)
		if (map->map[x][y - 1] != '1' && map->map[x][y - 1] != ' ')
			return (0);
	if (y != map->sizeline - 1)
		if (map->map[x][y + 1] != '1' && map->map[x][y + 1] != ' ')
			return (0);
	return (1);
}

int	check_all(t_data *map)
{
	char	act;
	int		i;
	int		j;

	i = 0;
	while (i < map->nbline)
	{
		j = 0;
		while (j < map->sizeline)
		{
			act = map->map[i][j];
			if (valid_char(act) == 0)
				return (1);
			if (act == ' ')
				if (check_space(map, i, j) != 1)
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}
