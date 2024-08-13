/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:48:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 09:44:09 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isnumeric(int c)
{
	return (c > 47 && c < 58);
}

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
			if (!ptr[i][j])
				return (0);
		}
		while (ptr[i][j])
		{
			if (!ft_isnumeric(ptr[i][j]))
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

void	ft_fill(int *nums, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("* %d *\n", nums[i]);
		i++;
	}
}
