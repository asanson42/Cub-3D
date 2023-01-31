/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:09:11 by asanson           #+#    #+#             */
/*   Updated: 2022/06/07 15:43:03 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_cub(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			free_data(data, "File without \".cub\"");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, data);
	else
		free_data(data, "File without \".cub\"");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init(&data);
	if (argc == 2)
		ft_cub(argv[1], &data);
	else
		write(1, "Error: Wrong amount of arguments.\n", 34);
	return (0);
}
