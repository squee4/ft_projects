/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:38:49 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 00:01:51 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = head;
	*stack = head->next;
	head->next = NULL;
}
