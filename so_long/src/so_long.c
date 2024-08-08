/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 03:56:43 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/07 20:36:52 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		write(2, "Wrong argc\n", 11);
	else if (ft_valid_format(argv[1]))
	{
		data.map = ft_read_map(argv[1]);
		if (ft_map_valid(&data, argv[1]))
			ft_open_window(&data);
	}
	return (EXIT_SUCCESS);
}
