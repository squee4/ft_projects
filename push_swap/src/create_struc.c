/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:09:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 12:23:39 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->index = -1;
	node->target = -1;
	node->cost = -1;
	node->next = NULL;
	return (node);
}

void	ft_add_node_top(t_node **stack, t_node *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_stack_a(t_node **stack, int *nums, int len)
{
	int		i;

	i = len;
	while (i >= 0)
	{
		ft_add_node_top(stack, ft_new_node(nums[i]));
		if (i == len)
			stack[0]->next = NULL;
		i--;
	}
}
