/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:48:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 20:12:14 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_numeric_args(char **ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i][j] == '+' || ptr[i][j] == '-')
		{
			j++;
			if (ptr[i][j] == '<')
				return (0);
		}
		while (ptr[i][j])
		{
			if (!ft_isdigit(ptr[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	*ft_convert(char **ptr)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	while (ptr[i])
		i++;
	nums = malloc(sizeof(int) * i);
	j = 0;
	while (j < i)
	{
		nums[j] = ft_atoi(ptr[j]);
		j++;
	}
	return (nums);
}

int	ft_unique(int *nums)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (nums[i] && nums[j])
	{
		while (nums[j])
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_atoi_magic(const char *str)
{
	int	num;
	int	sign;
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
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}
