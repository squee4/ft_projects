/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:09:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 00:56:19 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_new_node(int value, t_data *data)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(*node));
	if (!node)
		ft_error("Error\n", data);
	node->value = value;
	node->index = -1;
	node->target = -1;
	node->cost = -1;
	node->tcost = -1;
	node->next = NULL;
	return (node);
}

void	ft_add_node_top(t_node **stack, t_node *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_stack_a(t_data *data)
{
	int	len;
	int	*nums;

	len = data->count - 1;
	nums = data->nums;
	data->size_a = data->count;
	while (len >= 0)
		ft_add_node_top(&data->s_a, ft_new_node(nums[len--], data));
	ft_index(data, &data->s_a);
}
