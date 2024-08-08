/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:51:05 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/07 20:41:26 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*aux;

	(void)keydata;
	aux = (t_data *)param;
	if (mlx_is_key_down(aux->window, MLX_KEY_W))
		ft_move_up(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_A))
		ft_move_left(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_S))
		ft_move_down(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_D))
		ft_move_right(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_UP))
		ft_move_up(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_LEFT))
		ft_move_left(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_DOWN))
		ft_move_down(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_RIGHT))
		ft_move_right(aux);
	if (mlx_is_key_down(aux->window, MLX_KEY_ESCAPE))
		ft_error("Quit game\n", aux);
}

void	ft_move_up(t_data *data)
{
	char	dest;

	dest = data->map[data->player.y - 1][data->player.x];
	if (dest != '1')
	{
		if (dest != 'E')
		{
			if (data->map[data->player.y][data->player.x] != 'E')
				data->map[data->player.y][data->player.x] = '0';
			data->player.y--;
			data->map[data->player.y][data->player.x] = 'P';
			data->images.player->instances->y -= 100;
		}
		else
		{
			data->map[data->player.y][data->player.x] = '0';
			data->player.y--;
			ft_redraw_player(data);
		}
		ft_move_handler(data, dest);
	}
}

void	ft_move_left(t_data *data)
{
	char	dest;

	dest = data->map[data->player.y][data->player.x - 1];
	if (dest != '1')
	{
		if (dest != 'E')
		{
			if (data->map[data->player.y][data->player.x] != 'E')
				data->map[data->player.y][data->player.x] = '0';
			data->player.x--;
			data->map[data->player.y][data->player.x] = 'P';
			data->images.player->instances->x -= 100;
		}
		else
		{
			data->map[data->player.y][data->player.x] = '0';
			data->player.x--;
			ft_redraw_player(data);
		}
		ft_move_handler(data, dest);
	}
}

void	ft_move_down(t_data *data)
{
	char	dest;

	dest = data->map[data->player.y + 1][data->player.x];
	if (dest != '1')
	{
		if (dest != 'E')
		{
			if (data->map[data->player.y][data->player.x] != 'E')
				data->map[data->player.y][data->player.x] = '0';
			data->player.y++;
			data->map[data->player.y][data->player.x] = 'P';
			data->images.player->instances->y += 100;
		}
		else
		{
			data->map[data->player.y][data->player.x] = '0';
			data->player.y++;
			ft_redraw_player(data);
		}
		ft_move_handler(data, dest);
	}
}

void	ft_move_right(t_data *data)
{
	char	dest;

	dest = data->map[data->player.y][data->player.x + 1];
	if (dest != '1')
	{
		if (dest != 'E')
		{
			if (data->map[data->player.y][data->player.x] != 'E')
				data->map[data->player.y][data->player.x] = '0';
			data->player.x++;
			data->map[data->player.y][data->player.x] = 'P';
			data->images.player->instances->x += 100;
		}
		else
		{
			data->map[data->player.y][data->player.x] = '0';
			data->player.x++;
			ft_redraw_player(data);
		}
		ft_move_handler(data, dest);
	}
}
