/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:57:37 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 01:04:58 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_b_cost(t_node *sb, int *cost, int *targ)
{
	int	total_cost;

	total_cost = INT_MAX;
	while (sb)
	{
		if (sb->tcost < total_cost)
		{
			total_cost = sb->tcost;
			*cost = sb->cost;
			*targ = sb->target;
		}
		sb = sb->next;
	}
}

int	ft_find_a_cost(t_node *sa, int targ_index)
{
	while (sa)
	{
		if (sa->index == targ_index)
			return (sa->cost);
		sa = sa->next;
	}
	return (0);
}

void	ft_last(t_data *data)
{
	t_node	*tmp;
	int		i;

	tmp = data->s_a;
	i = 0;
	while (tmp)
	{
		i++;
		if (tmp->index == 0)
			break ;
		tmp = tmp->next;
	}
	tmp = data->s_a;
	while (tmp->index != 0)
	{
		if (i <= data->count / 2)
			ft_rotate(&data->s_a, 1);
		else if (i > data->count / 2)
			ft_rev_rotate(&data->s_a, 1);
		tmp = data->s_a;
	}
}

void	ft_sorting_algo(t_data *data)
{
	int	a_cost;
	int	b_cost;
	int	target;

	ft_fill_b(data);
	while (data->s_b)
	{
		ft_set_cost(&data->s_a, data->size_a);
		ft_set_cost(&data->s_b, data->size_b);
		ft_set_target_b(&data->s_b, data->s_a);
		ft_set_tcost(&data->s_b, data->s_a);
		ft_find_b_cost(data->s_b, &b_cost, &target);
		a_cost = ft_find_a_cost(data->s_a, target);
		ft_move(a_cost, b_cost, data);
	}
	ft_last(data);
}
