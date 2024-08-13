/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:20:35 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 22:44:22 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*second;

	if (*stack && (*stack)->next)
	{
		second = (*stack)->next;
		(*stack)->next = second->next;
		second->next = *stack;
		//second = *stack;
		*stack = second;
	}
}
