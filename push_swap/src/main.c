/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:37:18 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 00:09:38 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc == 2)
	{
		data.arg = ft_split(argv[1], ' ');
		data.count = words(argv[1], ' ');
	}
	else if (argc != 1)
	{
		data.arg = argv + 1;
		data.count = argc - 1;
	}
	else
	{
		write(2, "Wrong argc\n", 11);
		return (0);
	}

	printf("Numeric - %d.\n", ft_numeric_args(data.arg));
	data.nums = ft_convert(data.arg);
	printf("Unique - %d.\n", ft_unique(data.nums));
	ft_fill(data.nums, data.count);
	ft_stack_a(&data.s_a, data.nums, data.count - 1);
	ft_index(&data, &data.s_a);
	ft_set_pos(&data.s_a);
	//ft_print_values(data.s_a);
	ft_rev_rotate(&data.s_a);
	write(1, "stack a values\n", 15);
	ft_print_values(data.s_a);
	write(1, "stack b values\n", 15);
	ft_print_values(data.s_b);
	return (0);
}
