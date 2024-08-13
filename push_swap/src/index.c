/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:29:24 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 09:47:34 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b, int *swp)
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
				ft_swap(&list[j], &list[j + 1], &swap);
			j++;
		}
		if (swap == 0)
			break ;
		i++;
	}
}

void	ft_index(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_sort_num(data);
	while (data->nums[i])
	{
		while (data->s_a[j])
		{
			if (data->s_a[j]->value == data->nums[i])
				data->s_a[j]->index = i;
			j++;
		}
		j = 0;
		i++;
	}
}
