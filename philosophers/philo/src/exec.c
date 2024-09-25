/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:30:55 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/17 13:09:00 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_act(t_philo *philo, char *msg, long pause)
{
	long	cur_time;

	cur_time = ft_get_time() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->write_lock);
	if (philo->table->death == 0)
		printf("[%ld] %d %s\n", cur_time, philo->id, msg);
	if (!strncmp(msg, "is sleeping", 11))
		ft_unlock(philo);
	pthread_mutex_unlock(&philo->table->write_lock);
	if (ft_usleep(pause, philo))
		return (1);
	return (0);
}

int	ft_zzz(t_philo *philo)
{
	philo->meals_taken++;
	philo->last_meal = ft_get_time();
	if (philo->meals_taken == philo->eat_times)
	{
		pthread_mutex_lock(&philo->table->write_lock);
		philo->table->phinish++;
		if (philo->table->phinish == philo->count)
			philo->table->death = 1;
		pthread_mutex_unlock(&philo->table->write_lock);
	}
	if (ft_act(philo, "is sleeping", philo->t_sleep))
		return (1);
	return (0);
}

void	*ft_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		ft_usleep(p->t_eat, p);
	while (1)
	{
		if (!ft_lock(p))
			break ;
		if (ft_act(p, "is eating", p->t_eat))
		{
			ft_unlock(p);
			break ;
		}
		if (ft_zzz(p))
			break ;
		if (p->count % 2)
		{
			if (ft_act(p, "is thinking", p->t_eat))
				break ;
		}
		else
			ft_act(p, "is thinking", 0);
	}
	return (NULL);
}

void	ft_start_routine(t_philo philo[])
{
	int	i;

	i = 0;
	while (i < philo[0].count)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while (i < philo[0].count)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
