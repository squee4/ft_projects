/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:11:44 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 01:02:03 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_calculate_tcost(int cur, int a)
{
	int	ret;

	ret = 0;
	if (cur >= 0 && a >= 0)
	{
		ret = cur;
		if (a > cur)
			ret = a;
	}
	else if (a <= 0 && cur <= 0)
	{
		ret = -1 * cur;
		if (a < cur)
			ret = -1 * a;
	}
	else
	{
		if (a <= 0 && cur >= 0)
			ret = -a + cur;
		else if (a >= 0 && cur <= 0)
			ret = -cur + a;
	}
	return (ret);
}

void	ft_set_node_tcost(t_node **cur, t_node *stacka)
{
	while (stacka)
	{
		if (stacka->index == (*cur)->target)
			(*cur)->tcost = ft_calculate_tcost((*cur)->cost, stacka->cost);
		stacka = stacka->next;
	}
}

void	ft_set_tcost(t_node **stackb, t_node *stacka)
{
	t_node	*head;

	head = *stackb;
	while (*stackb)
	{
		ft_set_node_tcost(stackb, stacka);
		*stackb = (*stackb)->next;
	}
	*stackb = head;
}
