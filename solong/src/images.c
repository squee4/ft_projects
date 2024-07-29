/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:04:08 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/25 22:30:29 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

mlx_image_t	*ft_load_image(char *img_name, t_data *data)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(img_name);
	if (!texture)
	{
		printf("%s", img_name);
		ft_error("Error loading texture", data);
	}
	image = mlx_texture_to_image(data->window, texture);
	mlx_delete_texture(texture);
	if (!image)
		ft_error("Error loading image", data);	
	return (image);
}

void	ft_start_images(t_data *data)
{
	data->images.floor = ft_load_image("./textures/floor.png", data);
	data->images.wall = ft_load_image("./textures/wall.png", data);
	data->images.player = ft_load_image("./textures/player.png", data);
	data->images.coin = ft_load_image("./textures/coin.png", data);
	data->images.exit = ft_load_image("./textures/exit.png", data);
}

void	ft_free_images(t_data *data)
{
	if (data->images.floor)
		mlx_delete_image(data->window, data->images.floor);
	if (data->images.wall)
		mlx_delete_image(data->window, data->images.wall);
	if (data->images.player)
		mlx_delete_image(data->window, data->images.player);
	if (data->images.coin)
		mlx_delete_image(data->window, data->images.coin);
	if (data->images.exit)
		mlx_delete_image(data->window, data->images.exit);
}
