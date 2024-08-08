/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:21:33 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/02 01:59:33 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_draw_tile(char c, int x, int y, t_data *data)
{
	mlx_image_t	*img;

	if (c == '1')
		img = data->images.wall;
	if (c == '0')
		img = data->images.floor;
	if (c == 'P')
		img = data->images.player;
	if (c == 'E')
		img = data->images.exit;
	if (c == 'D')
		img = data->images.door;
	if (c == 'C')
		img = data->images.coin;
	if (mlx_image_to_window(data->window, img, x, y) < 0)
		ft_error("Error drawing a tile", data);
}

void	ft_draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_start_images(data);
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				ft_draw_tile('1', j * 100, i * 100, data);
			else if (data->map[i][j] == 'E')
				ft_draw_tile('E', j * 100, i * 100, data);
			else
				ft_draw_tile('0', j * 100, i * 100, data);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_rest(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->coins = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				ft_draw_tile('D', j * 100, i * 100, data);
			else if (data->map[i][j] == 'C')
			{
				ft_draw_tile('C', j * 100, i * 100, data);
				data->coins++;
			}
			else if (data->map[i][j] == 'P')
				ft_draw_tile('P', j * 100, i * 100, data);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_redraw_coins(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->coins--;
	mlx_delete_image(data->window, data->images.coin);
	data->images.coin = ft_load_image("./textures/coin.png", data);
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				ft_draw_tile('C', j * 100, i * 100, data);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_open_window(t_data *data)
{
	int	width;
	int	height;

	width = data->width * 100;
	height = data->height * 100;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->window = mlx_init(width, height, "so_long", true);
	if (!data->window)
		ft_error("Error starting window", data);
	ft_draw_map(data);
	ft_draw_rest(data);
	mlx_key_hook(data->window, &my_keyhook, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	ft_free_double(data->map);
}
