/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:51:05 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/29 20:12:36 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	(void)keydata;
	t_data *aux;
	aux = (t_data *)param;
	if (mlx_is_key_down(aux->window, MLX_KEY_W))
		puts("arriba");
	if (mlx_is_key_down(aux->window, MLX_KEY_A))
		puts("izquierda");
	if (mlx_is_key_down(aux->window, MLX_KEY_S))
		puts("abajo");
	if (mlx_is_key_down(aux->window, MLX_KEY_D))
		puts("derecha");
	if (mlx_is_key_down(aux->window, MLX_KEY_ESCAPE))
	{
		puts("SALIR");
		exit(0);
	}
}
void	ft_move(t_data *data)
{
	
}
