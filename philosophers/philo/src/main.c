/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:22 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/02 20:48:40 by ijerruz-         ###   ########.fr       */
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
		while (argv[i][j])
		{
			if (argv[i][j])
				return (write(2, "Error. Invalid character.\n", 26), 0);
			j++;
		}
		tmp = ft_atoi(argv[i]);
		if (tmp <= 0)
			return (write(2, "Error. Null or negative number.\n", 32), 0);
		if (i == 0 && tmp > 200)
			return (write(2, "Error. Too many philosophers!.\n", 31), 0);
		if (i != 0 && tmp < 60)
			return (write(2, "Error. Very low value given!.\n", 30), 0);
		j = 0;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	//t_table	table;

	if ((argc == 5 || argc == 6) && ft_valid_args(argv + 1))
	{
		write(1, "OK\n", 3);
	}
	else
		write(2, "ERROR. Wrong number of arguments.\n", 34);
	return (0);
}
