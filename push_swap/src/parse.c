/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:48:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/21 19:15:55 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_numeric_args(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->arg[i])
	{
		if (data->arg[i][j] == '+' || data->arg[i][j] == '-')
		{
			j++;
			if (data->arg[i][j] == '<')
				ft_error("Non valid args included\n", data);
		}
		while (data->arg[i][j])
		{
			if (!ft_isdigit(data->arg[i][j]))
				ft_error("Error. Non valid args included\n", data);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	*ft_convert(t_data *data)
{
	int		i;
	int		*nums;

	i = 0;
	while (data->arg[i])
		i++;
	data->count = i;
	nums = malloc(sizeof(int) * i);
	if (!nums)
		ft_error("Int malloc error\n", data);
	i = 0;
	while (i < data->count)
	{
		nums[i] = ft_atoi_magic(data->arg[i], data);
		i++;
	}
	return (nums);
}

int	ft_unique(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (data->count == 2)
		return (1);
	while (i < data->count - 1)
	{
		while (j < data->count)
		{
			if (data->nums[i] == data->nums[j])
				ft_error("Error. Repeated values introduced\n", data);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_atoi_magic(const char *str, t_data *data)
{
	long	num;
	long	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num * sign) < (-__INT_MAX__ - 1) || (num * sign) > __INT_MAX__)
			ft_error("Number out of range\n", data);
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return ((int)(num * sign));
}
