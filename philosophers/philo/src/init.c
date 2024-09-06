/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:15 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/06 16:17:29 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_serve_table(t_table *table, char **argv)
{
	int	i;

	i = 0;
	memset(table, 0, sizeof(t_table));
	table->count = ft_atoi(argv[0]);
	table->t_die = ft_atoi(argv[1]);
	table->t_eat = ft_atoi(argv[2]);
	table->t_sleep = ft_atoi(argv[3]);
	table->death = 0;
	if (argv[4])
		table->eat_times = ft_atoi(argv[4]);
	pthread_mutex_init(&table->write_lock, NULL);
	while (i < table->count)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
	table->start_time = ft_get_time();
}

void	ft_create_philos(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].my_fork = &table->fork[i];
		if (i == 0)
		{
			if (table->count == 1)
				philo[i].r_fork = NULL;
			else
				philo[i].r_fork = &table->fork[table->count - 1];
		}
		else
			philo[i].r_fork = &table->fork[i - 1];
		philo[i].id = i + 1;
		philo[i].count = table->count;
		philo[i].t_die = table->t_die;
		philo[i].t_eat = table->t_eat;
		philo[i].t_sleep = table->t_sleep;
		philo[i].eat_times = table->eat_times;
		philo[i].table = table;
		i++;
	}
}
