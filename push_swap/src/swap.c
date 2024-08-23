/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:20:35 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/23 23:56:15 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_node **stack, int p)
{
	t_node	*second;

	if (*stack && (*stack)->next)
	{
		second = (*stack)->next;
		(*stack)->next = second->next;
		second->next = *stack;
		*stack = second;
		if (p == 1)
			write(1, "sa\n", 3);
		else if (p == 2)
			write(1, "sb\n", 3);
		else if (p == 3)
			write(1, "ss\n", 3);
	}
}

void	ft_swap_double(t_node **sa, t_node **sb, int p)
{
	ft_swap(sa, 0);
	if (p)
		ft_swap(sb, 3);
	else
		ft_swap(sb, 0);
}
