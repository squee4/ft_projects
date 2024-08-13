/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:54:22 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 21:02:37 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_pos(t_node **stack)
{
	int		i;
	t_node	*head;

	i = 0;
	head = *stack;
	while (*stack)
	{
		(*stack)->pos = i;
		i++;
		*stack = (*stack)->next;
	}
	*stack = head;
}
