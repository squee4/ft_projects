/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:22 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/06 16:21:43 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	philo[200];
	t_philo	*p;
	int		i;

	if ((argc == 5 || argc == 6) && ft_valid_args(argv + 1, 0, 0))
	{
		ft_serve_table(&table, argv + 1);
		ft_create_philos(philo, &table);
		//ft_start_routine(philo);
	}
	//ft_join_philos(philo);
	ft_finish(&table, philo);
	return (0);
}
