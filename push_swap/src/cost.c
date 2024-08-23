/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:19:30 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 01:01:17 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_cost(t_node **stack, int size)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = 0;
	if (size % 2 == 0)
		j = (-size / 2) + 1;
	else
		j = -size / 2;
	tmp = *stack;
	while (i <= size / 2)
	{
		tmp->cost = i;
		tmp = tmp->next;
		i++;
	}
	while (i < size)
	{
		tmp->cost = j;
		tmp = tmp->next;
		i++;
		j++;
	}
}
