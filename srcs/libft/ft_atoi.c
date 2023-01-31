/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:09:59 by mmahias           #+#    #+#             */
/*   Updated: 2022/06/06 17:23:22 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_nb_virgule(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}

int	ft_natoi(const char *str, int i)
{
	int	c;
	int	n;

	c = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c = c * -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * c);
}

int	full_rgb(char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (line[i] == 'F' || line[i] == 'C' || line[i] == ' ')
		i++;
	r = ft_natoi(line, i);
	while (line[i] >= 48 && line[i] <= 57)
		i++;
	while (line[i] == ',')
		i++;
	g = ft_natoi(line, i);
	while (line[i] >= 48 && line[i] <= 57)
		i++;
	while (line[i] == ',')
		i++;
	b = ft_natoi(line, i);
	return (0 << 24 | r << 16 | g << 8 | b);
}
