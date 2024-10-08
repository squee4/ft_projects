/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:37:18 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/23 22:24:09 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_start(argc, argv, &data);
	if (ft_numeric_args(&data))
		data.nums = ft_convert(&data);
	if (ft_unique(&data))
		ft_stack_a(&data);
	if (ft_is_sorted(data.s_a))
		ft_finish(&data);
	ft_sorting_algo(&data);
	ft_finish(&data);
}
