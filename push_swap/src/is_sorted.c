/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:17:49 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/23 22:23:24 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->index != i)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}
