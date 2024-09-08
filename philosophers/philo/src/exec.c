/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:30:55 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/06 16:20:33 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_lock_unlock(pthread_mutex_t *w, pthread_mutex_t *f1,
pthread_mutex_t *f2, int mode)
{
	if (mode && f2)
	{
		pthread_mutex_lock(w);
		pthread_mutex_lock(f1);
		pthread_mutex_lock(f2);
		return (1);
	}
	else if (f2)
	{
		pthread_mutex_unlock(w);
		pthread_mutex_unlock(f1);
		pthread_mutex_unlock(f2);
		return (1);
	}
	return (0);
}

void	ft_act(long start, int id, int action, long pause)
{
	long	cur_time;

	cur_time = ft_get_time() - start;
	if (action == 1)
	{
		printf("[%ld] %d is eating\n", cur_time, id);
		ft_usleep(pause);
	}
	if (action == 2)
	{
		printf("[%ld] %d is sleeping\n", cur_time, id);
		ft_usleep(pause);
	}
	if (action == 3)
	{
		printf("[%ld] %d is thinking\n", cur_time, id);
		ft_usleep(pause);
	}
	if (action == 4)
		printf("[%ld] %d died\n", cur_time, id);
}

void	*ft_routine(void *philo)
{
	t_philo *p;
	long	start;

	p = (t_philo *)philo;
	start = p->table->start_time;
	while (1)
	{
		ft_lock_unlock(&p->table->write_lock, p->my_fork, p->r_fork, 1);
		ft_act(start, p->id, 1, p->t_eat);
		p->last_meal = ft_get_time();
		ft_act(start, p->id, 2, p->t_sleep);
		if ((ft_get_time() - p->last_meal) >= p->t_die)
		{
			ft_lock_unlock(&p->table->write_lock, p->my_fork, p->r_fork, 0);
			ft_act(start, p->id, 4, 0);
			p->table->death = 1;
			break;
		}
		ft_act(start, p->id, 3, p->t_eat);
		ft_lock_unlock(&p->table->write_lock, p->my_fork, p->r_fork, 0);
	}
	return ((void *)0);
}
