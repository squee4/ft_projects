/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:38:35 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 00:04:22 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate(t_node **stack, int p)
{
	t_node	*head;
	t_node	*ass;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		ass = *stack;
		while (ass->next)
			ass = ass->next;
		while ((*stack)->next)
		{
			if ((*stack)->next == ass)
				(*stack)->next = NULL;
			else
				*stack = (*stack)->next;
		}
		ass->next = head;
		*stack = ass;
		if (p == 1)
			write(1, "rra\n", 4);
		else if (p == 2)
			write(1, "rrb\n", 4);
		else if (p == 3)
			write(1, "rrr\n", 4);
	}
}

void	ft_rev_rotate_double(t_node **sa, t_node **sb, int p)
{
	ft_rev_rotate(sa, 0);
	if (p)
		ft_rev_rotate(sb, 3);
	else
		ft_rev_rotate(sb, 0);
}
