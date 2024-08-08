/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:07:36 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/02 02:09:29 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_square(t_data *data)
{
	size_t	width;
	int		i;

	i = 0;
	width = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (width != ft_strlen(data->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_contains_one(t_data *data, char c)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (found && data->map[i][j] == c)
				return (0);
			if (!found && data->map[i][j] == c)
				found = 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (found)
		return (1);
	return (0);
}

int	ft_contains_multi(t_data *data, char c)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (!found && data->map[i][j] == c)
				found = 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (found)
		return (1);
	return (0);
}

int	ft_valid_chars(t_data *data, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (!ft_strchr(set, data->map[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_surrounded(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (i == 0 || i == (data->height - 1) || j == 0
				|| j == (data->width - 1))
			{
				if (data->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
