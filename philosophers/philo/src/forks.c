/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:48:53 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/17 13:10:02 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_lock(t_philo *philo)
{
	long	start;

	start = philo->table->start_time;
	if (philo->r_fork == NULL)
	{
		printf("[%ld] %d has taken a fork\n", ft_get_time() - start, philo->id);
		usleep(philo->t_die * 1000);
		printf("[%ld] %d died\n", ft_get_time() - start, philo->id);
		return (0);
	}
	if (philo->id == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		ft_act(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->my_fork);
		ft_act(philo, "has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(philo->my_fork);
		ft_act(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->r_fork);
		ft_act(philo, "has taken a fork", 0);
	}
	return (1);
}

void	ft_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->my_fork);
}
