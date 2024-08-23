/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:31:37 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 00:56:57 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_data *data, int p)
{
	t_node	*tmp;

	tmp = data->s_b;
	if (!data->s_b)
		return ;
	data->s_b = (data->s_b)->next;
	tmp->next = data->s_a;
	data->s_a = tmp;
	data->size_b--;
	data->size_a++;
	if (p == 1)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_data *data, int p)
{
	t_node	*tmp;

	tmp = data->s_a;
	if (!data->s_a)
		return ;
	data->s_a = (data->s_a)->next;
	tmp->next = data->s_b;
	data->s_b = tmp;
	data->size_a--;
	data->size_b++;
	if (p == 1)
		write(1, "pb\n", 3);
}
