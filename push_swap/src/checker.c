/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:24:58 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 01:00:42 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_moves(char *str, t_data *data)
{
	if (!ft_strncmp("pa\n", str, 3))
		return (ft_push_a(data, 0), 1);
	else if (!ft_strncmp("pb\n", str, 3))
		return (ft_push_b(data, 0), 1);
	else if (!ft_strncmp("sa\n", str, 3))
		return (ft_swap(&data->s_a, 0), 1);
	else if (!ft_strncmp("sb\n", str, 3))
		return (ft_swap(&data->s_b, 0), 1);
	else if (!ft_strncmp("ss\n", str, 3))
		return (ft_swap_double(&data->s_a, &data->s_b, 0), 1);
	else if (!ft_strncmp("ra\n", str, 3))
		return (ft_rotate(&data->s_a, 0), 1);
	else if (!ft_strncmp("rb\n", str, 3))
		return (ft_rotate(&data->s_b, 0), 1);
	else if (!ft_strncmp("rr\n", str, 3))
		return (ft_rotate_double(&data->s_a, &data->s_b, 0), 1);
	else if (!ft_strncmp("rra\n", str, 4))
		return (ft_rev_rotate(&data->s_a, 0), 1);
	else if (!ft_strncmp("rrb\n", str, 4))
		return (ft_rev_rotate(&data->s_b, 0), 1);
	else if (!ft_strncmp("rrr\n", str, 4))
		return (ft_rev_rotate_double(&data->s_a, &data->s_b, 0), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*tmp;

	ft_start(argc, argv, &data);
	if (ft_numeric_args(&data))
		data.nums = ft_convert(&data);
	if (ft_unique(&data))
		ft_stack_a(&data);
	tmp = get_next_line(0);
	while (tmp)
	{
		if (!ft_check_moves(tmp, &data))
		{
			free(tmp);
			ft_error("Error\n", &data);
		}
		free(tmp);
		tmp = get_next_line(0);
	}
	if (ft_is_sorted(data.s_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_finish(&data);
}
