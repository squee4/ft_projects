/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:59 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/12 17:08:52 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_set_death(t_philo *philo)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->write_lock);
	timestamp = ft_get_time() - philo->table->start_time;
	if (philo->table->death == 0)
	{
		philo->table->death = 1;
		printf("[%ld] %d died\n", timestamp, philo->id);
	}
	pthread_mutex_unlock(&philo->table->write_lock);
}

int	ft_usleep(long ms, t_philo *philo)
{
	long	start;

	start = ft_get_time();
	if (ms == 0)
		return (0);
	while ((ft_get_time() - start) < ms)
	{
		pthread_mutex_lock(&philo->table->write_lock);
		if (philo->table->death == 1)
		{
			pthread_mutex_unlock(&philo->table->write_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->write_lock);
		if ((ft_get_time() - philo->last_meal) >= philo->t_die)
		{
			ft_set_death(philo);
			return (1);
		}
		usleep(500);
	}
	return (0);
}
