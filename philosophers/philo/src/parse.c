/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:14:34 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/12 17:25:26 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_valid_args(char **argv)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (write(2, "Error. Invalid character.\n", 26), 0);
			j++;
		}
		tmp = ft_atoi(argv[i]);
		if (tmp < 0 || ((i == 0 || i == 4) && tmp == 0))
			return (0);
		if (i == 0 && tmp > 200)
			return (write(2, "Error. Too many philosophers!.\n", 31), 0);
		if (i != 0 && i != 4 && tmp < 60)
			return (write(2, "Error. Very low value given!.\n", 30), 0);
		i++;
	}
	return (1);
}
