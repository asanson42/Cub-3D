/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:54:33 by mmahias           #+#    #+#             */
/*   Updated: 2022/06/07 14:44:17 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_parsing_map(char *file, t_data *data)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->nbline));
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (data->insidemap == 1 && ft_emptyline(str) == 0 \
		&& data->count < data->nbline)
			data->emptyline = 1;
		data->insidemap = ft_is_map(str, data);
		if (data->insidemap == 1)
		{
			data->count++;
			ft_dupmap(str, data);
		}
		free(str);
	}
	close(fd);
	ft_launch(data);
	return (0);
}

static void	ft_parsing_utils(char *str, t_data *data, int fd)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		free(str);
	}
	free_data(data, "Parsing");
}

void	ft_parsing(char *file, t_data *data)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_data(data, "Invalid file");
	data->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		ft_color_res(&str, data);
		ft_texture(str, data);
		ft_map(str, data);
		free(str);
		if (data->error == 2)
			ft_parsing_utils(str, data, fd);
	}
	close(fd);
	if (data->sizeline == 0 || data->nbline == 0)
		free_data(data, "No map");
	ft_parsing_map(file, data);
}
