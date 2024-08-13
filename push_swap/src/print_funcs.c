/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:54:27 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 21:03:04 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_values(t_node *list)
{
	if (!list)
	{
		write(1, "Empty stack\n", 12);
		return ;
	}
	while (list)
	{
		printf("address %p; value %d - next %p;\n", list, list->value, list->next);
		list = list->next;
	}
}

void	ft_print_indexes(t_node *list)
{
	if (!list)
	{
		write(1, "Empty stack\n", 12);
		return ;
	}
	while (list)
	{
		printf("address %p; index %d - next %p;\n", list, list->index, list->next);
		list = list->next;
	}
}

void	ft_print_pos(t_node *list)
{
	if (!list)
	{
		write(1, "Empty stack\n", 12);
		return ;
	}
	while (list)
	{
		printf("address %p; pos %d - next %p;\n", list, list->pos, list->next);
		list = list->next;
	}
}
