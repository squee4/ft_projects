/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:21:33 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/29 19:41:20 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

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
				ft_draw_tile('1', j * 50, i * 50, data);
			else if (data->map[i][j] == 'E')
				ft_draw_tile('1', j * 50, i * 50, data);
			else
				ft_draw_tile('0', j * 50, i * 50, data);
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
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				ft_draw_tile('P', j * 50, i * 50, data);
			else if (data->map[i][j] == 'C')
				ft_draw_tile('C', j * 50, i * 50, data);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_open_window(t_data *data)
{
	int	width;
	int height;

	width = data->width * data->size;
	height = data->height * data->size;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->window = mlx_init(width, height, "so_long", true);
	if (!data->window)
		ft_error("Error starting window", data);
	ft_draw_map(data);
	ft_draw_rest(data);
	mlx_key_hook(data->window, &my_keyhook, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}
