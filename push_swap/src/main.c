/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:37:18 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/21 19:24:30 by ijerruz-         ###   ########.fr       */
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
		ft_error("Wrong argc\n", &data);
	if (ft_numeric_args(&data))
		data.nums = ft_convert(&data);
	if (ft_unique(&data))
		ft_stack_a(&data);
	ft_index(&data, &data.s_a);
	ft_set_pos(&data.s_a);
	//ft_print_values(data.s_a);
	//ft_rev_rotate(&data.s_a);
	///ft_fill_b(&data.s_a, &data.s_b, &data);
	write(1, "stack a values\n", 15);
	ft_fill_b(&data.s_a, &data.s_b, &data);
	ft_print_values(data.s_a);
	write(1, "stack b values\n", 15);
	ft_print_values(data.s_b);
	ft_error("fin del programa\n", &data);
	return (0);
}
