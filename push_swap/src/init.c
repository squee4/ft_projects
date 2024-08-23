/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:46:33 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/23 22:14:41 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_start(int argc, char **argv, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	if (argc == 2)
	{
		if (!argv[1][0])
			ft_error("Error\n", data);
		data->arg = ft_split(argv[1], ' ');
		data->count = words(argv[1], ' ');
		data->alloc = 1;
	}
	else if (argc != 1)
	{
		data->arg = argv + 1;
		data->count = argc - 1;
	}
	else
		ft_error("Error\n", data);
}
