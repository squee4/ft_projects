/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:25:25 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/07 19:23:54 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_read_map(char	*map_name)
{
	int		fd;
	char	*buffer;
	char	**map;

	buffer = ft_calloc(sizeof(char), 10000);
	if (!buffer)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0 || read(fd, buffer, 9999) == 0 || ft_double_break(buffer))
	{
		close(fd);
		free(buffer);
		write(2, "Map not valid\n", 14);
		exit(EXIT_FAILURE);
	}
	close(fd);
	map = ft_split(buffer, '\n');
	free(buffer);
	return (map);
}

int	ft_valid_format(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4)
	{
		if (!ft_strncmp(&map_name[len - 4], ".ber", 4))
			return (1);
	}
	write(2, "Not valid map name\n", 19);
	return (0);
}

int	ft_map_valid(t_data *data, char *map_name)
{
	ft_dimension_player(data);
	if (!ft_is_square(data))
		ft_error("Map is not square\n", data);
	if (!ft_surrounded(data))
		ft_error("Map must be surrounded by walls\n", data);
	if (!ft_valid_chars(data, "PEC01"))
		ft_error("Map contains non valid characters\n", data);
	if (!ft_contains_one(data, 'P'))
		ft_error("Map must contain only one P\n", data);
	if (!ft_contains_one(data, 'E'))
		ft_error("Map must contain only one E\n", data);
	if (!ft_contains_multi(data, 'C'))
		ft_error("Map must contain minimum one C\n", data);
	ft_fill(data->map, data->width, data->height, data->player);
	if (!ft_valid_chars(data, "01"))
		ft_error("Map is not resolvable\n", data);
	ft_free_double(data->map);
	data->map = ft_read_map(map_name);
	return (1);
}

void	ft_error(char *message, t_data *data)
{
	int	msg_len;

	msg_len = ft_strlen(message);
	write(2, message, msg_len);
	ft_free_images(data);
	ft_free_double(data->map);
	exit(EXIT_FAILURE);
}

void	ft_print(char *message, int num)
{
	int		msg_len;
	char	*number;
	int		num_len;

	msg_len = ft_strlen(message);
	write(1, message, msg_len);
	number = ft_itoa(num);
	num_len = ft_strlen(number);
	write(1, number, num_len);
	write(1, "\n", 1);
	free(number);
}
