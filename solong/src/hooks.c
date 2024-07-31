/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:51:05 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/31 04:31:30 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	printptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	(void)keydata;
	t_data *aux;
	aux = (t_data *)param;
	if (mlx_is_key_down(aux->window, MLX_KEY_W))
	{
		ft_move_up(aux);
		puts("arriba");
	}
	if (mlx_is_key_down(aux->window, MLX_KEY_A))
	{
		ft_move_left(aux);
		puts("izquierda");
	}
	if (mlx_is_key_down(aux->window, MLX_KEY_S))
	{
		ft_move_down(aux);
		puts("abajo");
	}
	if (mlx_is_key_down(aux->window, MLX_KEY_D))
	{
		ft_move_right(aux);
		puts("derecha");
	}
	if (mlx_is_key_down(aux->window, MLX_KEY_ESCAPE))
	{
		puts("SALIR");
		exit(0);
	}
}

void	ft_move_up(t_data *data)
{
	char	dest;
	//int		coinid;

	dest = data->map[data->player.y - 1][data->player.x];
	if (dest != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y--;
		data->map[data->player.y][data->player.x] = 'P';
		if (dest == 'C')
			ft_redraw_coins(data);
		data->images.player->instances->y -= 50;
		data->moves++;
		printptr(data->map);
	}
}

void	ft_move_left(t_data *data)
{
	char	dest;
	//int		coinid;

	dest = data->map[data->player.y][data->player.x - 1];
	if (dest != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x--;
		data->map[data->player.y][data->player.x] = 'P';
		if (dest == 'C')
			ft_redraw_coins(data);
		data->images.player->instances->x -= 50;
		data->moves++;
		printptr(data->map);
	}
}

void	ft_move_down(t_data *data)
{
	char	dest;
	//int		coinid;

	dest = data->map[data->player.y + 1][data->player.x];
	if (dest != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y++;
		data->map[data->player.y][data->player.x] = 'P';
		if (dest == 'C')
			ft_redraw_coins(data);
		data->images.player->instances->y += 50;
		data->moves++;
		printptr(data->map);
	}
}

void	ft_move_right(t_data *data)
{
	char	dest;

	dest = data->map[data->player.y][data->player.x + 1];
	if (dest != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x++;
		data->map[data->player.y][data->player.x] = 'P';
		if (dest == 'C')
			ft_redraw_coins(data);
		data->images.player->instances->x += 50;
		data->moves++;
		printptr(data->map);
	}
}
