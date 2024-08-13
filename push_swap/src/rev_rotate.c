/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:38:35 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 00:17:11 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*ass;

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
}
