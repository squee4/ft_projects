/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:21:33 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/23 16:40:09 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_load_textures(t_data *data)
{
	mlx_texture_t	*png;
	
	png = mlx_load_png("./textures/asdf.png");
	if (!png)
		ft_error("Error loading floor texture", data);
	data->images[0] = mlx_texture_to_image(data->window, png);
	if (!data->images[0])
		ft_error("Error loading floor image", data);
	
	png = mlx_load_png("./textures/asdf.png");
	if (!png)
		ft_error("Error loading floor texture", data);
	data->images[0] = mlx_texture_to_image(data->window, png);
	if (!data->images[0])
		ft_error("Error loading floor image", data);
}

void	ft_draw_map(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				
				if (!mlx_image_to_window(data->window, img, j * 50, i * 50) < 0)
					ft_error("Error loading image", data);
			}
			else
			{
				mlx_image_t	*img = mlx_texture_to_image(data->window, data->texture[0]);
				if (!img || (mlx_image_to_window(data->window, img, j * 50, i * 50) < 0))
					ft_error("Error loading image", data);
			}
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
	ft_load_textures(data);
	ft_draw_map(data, 0, 0);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}
