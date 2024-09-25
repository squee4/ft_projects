/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 05:43:04 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/24 19:06:27 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_dimension_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j] != 0)
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
	data->moves = 0;
}

void	ft_fill(char **map, int width, int height, t_point cur)
{
	if (cur.y < 0 || cur.y >= height || cur.x < 0
		|| cur.x >= width || map[cur.y][cur.x] == '1')
		return ;
	map[cur.y][cur.x] = '1';
	ft_fill(map, width, height, (t_point){cur.x - 1, cur.y});
	ft_fill(map, width, height, (t_point){cur.x + 1, cur.y});
	ft_fill(map, width, height, (t_point){cur.x, cur.y - 1});
	ft_fill(map, width, height, (t_point){cur.x, cur.y + 1});
}

void	ft_redraw_player(t_data *data)
{
	mlx_delete_image(data->window, data->images.player);
	data->images.player = ft_load_image("./textures/player.png", data);
	ft_draw_tile('P', data->player.x * 100, data->player.y * 100, data);
}

void	ft_move_handler(t_data *data, char dest)
{
	if (dest == 'C')
		ft_redraw_coins(data);
	if (data->coins == 0)
		mlx_delete_image(data->window, data->images.door);
	if (dest == 'E' && data->coins == 0)
		ft_error("End of game\n", data);
	data->moves++;
	ft_print("Moves: ", data->moves);
}

int	ft_double_break(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] && str[i + 1] == '\n')
				return (1);
		}
		i++;
	}
	return (0);
}
