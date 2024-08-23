/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:20:29 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 01:03:59 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_both_possitive(int a, int b, t_data *data)
{
	while (a > 0 && b > 0)
	{
		ft_rotate_double(&data->s_a, &data->s_b, 1);
		a--;
		b--;
	}
	while (a > 0)
	{
		ft_rotate(&data->s_a, 1);
		a--;
	}
	while (b > 0)
	{
		ft_rotate(&data->s_b, 2);
		b--;
	}
	ft_push_a(data, 1);
}

void	ft_both_negative(int a, int b, t_data *data)
{
	while (a < 0 && b < 0)
	{
		ft_rev_rotate_double(&data->s_a, &data->s_b, 1);
		a++;
		b++;
	}
	while (a < 0)
	{
		ft_rev_rotate(&data->s_a, 1);
		a++;
	}
	while (b < 0)
	{
		ft_rev_rotate(&data->s_b, 2);
		b++;
	}
	ft_push_a(data, 1);
}

void	ft_different(int a, int b, t_data *data)
{
	while (a > 0)
	{
		ft_rotate(&data->s_a, 1);
		a--;
	}
	while (a < 0)
	{
		ft_rev_rotate(&data->s_a, 1);
		a++;
	}
	while (b > 0)
	{
		ft_rotate(&data->s_b, 2);
		b--;
	}
	while (b < 0)
	{
		ft_rev_rotate(&data->s_b, 2);
		b++;
	}
	ft_push_a(data, 1);
}

void	ft_move(int a, int b, t_data *data)
{
	if (a >= 0 && b >= 0)
		ft_both_possitive(a, b, data);
	else if (a <= 0 && b <= 0)
		ft_both_negative(a, b, data);
	else
		ft_different(a, b, data);
}
