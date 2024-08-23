/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:38:49 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 00:03:14 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_node **stack, int p)
{
	t_node	*head;

	head = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = head;
	*stack = head->next;
	head->next = NULL;
	if (p == 1)
		write(1, "ra\n", 3);
	else if (p == 2)
		write(1, "rb\n", 3);
	else if (p == 3)
		write(1, "rr\n", 3);
}

void	ft_rotate_double(t_node **sa, t_node **sb, int p)
{
	ft_rotate(sa, 0);
	if (p)
		ft_rotate(sb, 3);
	else
		ft_rotate(sb, 0);
}
