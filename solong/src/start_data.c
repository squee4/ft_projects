/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 05:43:04 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/23 16:33:10 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_dimension_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player.y = i;
				data->player.x = j;
			}
			j++;
		}
		data->width = j;
		j = 0;
		i++;
	}
	data->height = i;
	data->size = 150;
	//if (data->height < 10 || data->width < 20)
	//	data->size = 128;
}

void	ft_fill(char **map, int width, int height, t_point cur)
{
	if (cur.y < 0 || cur.y >= height || cur.x < 0 ||
			cur.x >= width || map[cur.y][cur.x] == '1')
		return;
	map[cur.y][cur.x] = '1';
	ft_fill(map, width, height, (t_point){cur.x - 1, cur.y});
	ft_fill(map, width, height, (t_point){cur.x + 1, cur.y});
	ft_fill(map, width, height, (t_point){cur.x, cur.y - 1});
	ft_fill(map, width, height, (t_point){cur.x, cur.y + 1});
}
