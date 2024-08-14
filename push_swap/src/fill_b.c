/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:12:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 21:05:34 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_a(t_node **a, t_data *data)
{
	if ((*a)->next->index == data->count - 1)
		ft_rev_rotate(a, 1);
	if ((*a)->index == data->count - 1)
		ft_rotate(a, 1);
	if ((*a)->index == data->count - 2)
		ft_swap(a, 1);
}

void	ft_fill_b(t_node **a, t_node **b, t_data *data)
{
	int i;

	i = 0;
	if (data->count > 3)
	{
		while (i < (data->count - 3))
		{
			if ((*a)->index == i)
			{
				ft_push(b, a, 2);
				i++;
			}
			else
				ft_rotate(a, 1);
		}
	}
	ft_sort_a(a, data);
	i = 0;
/* 	while (i < data->count - 3)
	{
		ft_push(a, b, 1);
		i++;
	} */
}
