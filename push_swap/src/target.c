/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:50:39 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 01:01:29 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_node_target(t_node **cur, t_node *stacka)
{
	while (stacka)
	{
		if (stacka->index > (*cur)->index)
		{
			if ((*cur)->target == -1)
				(*cur)->target = stacka->index;
			if (stacka->index < (*cur)->target)
				(*cur)->target = stacka->index;
		}
		stacka = stacka->next;
	}
}

void	ft_set_target_b(t_node **stackb, t_node *stacka)
{
	t_node	*head;

	head = *stackb;
	while (*stackb)
	{
		ft_set_node_target(stackb, stacka);
		*stackb = (*stackb)->next;
	}
	*stackb = head;
}
