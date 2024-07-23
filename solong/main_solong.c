/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 03:56:43 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:23 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/* static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */

int main(int argc, char **argv)
{
	t_data	data;
			
	if (argc != 2)
		write(2, "Wrong argc", 10);
	else if (ft_valid_format(argv[1]))
	{
		data.map = ft_read_map(argv[1]);
		if (ft_map_valid(&data, argv[1]))
		{
			ft_open_window(&data);			
		}
		ft_free_double(data.map);
	}
	return (EXIT_SUCCESS);
}
