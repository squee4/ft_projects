/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:25:25 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/25 21:28:38 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	**ft_read_map(char	*map_name)
{
	int		fd;
	char	*buffer;
	char	**tmp;

	buffer = ft_calloc(sizeof(char), 1000);
	if (!buffer)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	read(fd, buffer, 999);
	close(fd);
	tmp = ft_split(buffer, '\n');
	free(buffer);
	return (tmp);
}

int		ft_valid_format(char *map_name)
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
		return (write(2, "Map is not square\n", 18), 0);
	if (!ft_surrounded(data))
		return (write(2, "Map must be surrounded by walls\n", 32), 0);
	if (!ft_valid_chars(data, "PEC01"))
		return (write(2, "Map contains non valid characters\n", 34), 0);
	if (!ft_contains_one(data, 'P'))
		return (write(2, "Map must contain only one P\n", 28), 0);
	if (!ft_contains_one(data, 'E'))
		return (write(2, "Map must contain only one E\n", 28), 0);
	if (!ft_contains_multi(data, 'C'))
		return (write(2, "Map must contain minimum one C\n", 31), 0);
	ft_fill(data->map, data->width, data->height, data->player);
	if (!ft_valid_chars(data, "01"))
		return (write(2, "Map is not resolvable\n", 22), 0);
	ft_free_double(data->map);
	data->map = ft_read_map(map_name);
	return (1);
}

void	ft_error(char *message, t_data *data)
{
	int	msg_len;

	msg_len = ft_strlen(message);
	write(2, message, msg_len);
	(void)data;
	//ft_free_stuff(data);
	ft_free_images(data);
	exit(EXIT_FAILURE);
}

/* void	ft_free_stuff(t_data *data)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if ()
		i++;
	}
} */
