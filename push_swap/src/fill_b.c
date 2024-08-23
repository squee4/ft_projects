/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:12:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 00:57:41 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_a(t_node **a, t_data *data)
{
	if (data->count == 2)
	{
		if ((*a)->index == 1)
			ft_swap(a, 1);
	}
	else if (data->count > 2)
	{
		if ((*a)->next->index == data->count - 1)
			ft_rev_rotate(a, 1);
		if ((*a)->index == data->count - 1)
			ft_rotate(a, 1);
		if ((*a)->index == data->count - 2)
			ft_swap(a, 1);
	}
}

void	ft_fill_b(t_data *data)
{
	int	i;

	i = 0;
	if (data->count > 3)
	{
		while (i < (data->count - 3))
		{
			if ((i < data->count / 2) && (data->s_a->index < data->count / 2))
			{
				ft_push_b(data, 1);
				i++;
			}
			else if ((i >= data->count / 2) && (i < (data->count - 3))
				&& data->s_a->index < (data->count - 3))
			{
				ft_push_b(data, 1);
				i++;
			}
			else
				ft_rotate(&data->s_a, 1);
		}
	}
	ft_sort_a(&data->s_a, data);
}
