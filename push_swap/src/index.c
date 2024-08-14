/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:29:24 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 18:35:28 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_num(int *a, int *b, int *swp)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	*swp = 1;
}

void	ft_sort_num(t_data *data)
{
	int	i;
	int	j;
	int	swap;
	int	len;
	int	*list;

	i = 0;
	j = 0;
	len = data->count;
	list = data->nums;
	while (i < (len - 1))
	{
		swap = 0;
		j = 0;
		while (j < (len - i - 1))
		{
			if (list[j] > list[j + 1])
				ft_swap_num(&list[j], &list[j + 1], &swap);
			j++;
		}
		if (swap == 0)
			break ;
		i++;
	}
}

void	ft_index(t_data *data, t_node **stack)
{
	int		i;
	int		j;
	t_node	*head;

	i = 0;
	j = 0;
	head = *stack;
	ft_sort_num(data);
	while (j < data->count)
	{
		while (*stack)
		{
			if ((*stack)->value == data->nums[i])
				(*stack)->index = i;
			*stack = (*stack)->next;
		}
		*stack = head;
		i++;
		j++;
	}
}
