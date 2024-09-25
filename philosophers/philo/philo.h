/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:52 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/17 13:02:51 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table
{
	int				death;
	int				count;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				eat_times;
	int				phinish;
	long			start_time;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	fork[200];
}	t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*my_fork;
	pthread_mutex_t	*r_fork;
	int				count;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				eat_times;
	long			last_meal;
	int				meals_taken;
	t_table			*table;
}	t_philo;

// LIB
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);

// PARSING
int		ft_valid_args(char **argv);

// START
void	ft_serve_table(t_table *table, char **argv);
void	ft_create_philos(t_philo *philo, t_table *table);

//EXEC
void	*ft_routine(void *philo);
int		ft_lock(t_philo *philo);
void	ft_unlock(t_philo *philo);
int		ft_act(t_philo *philo, char *msg, long pause);
void	ft_start_routine(t_philo philo[]);

//TIME
long	ft_get_time(void);
int		ft_usleep(long ms, t_philo *philo);

// FINISH
void	ft_finish(t_table *table);

#endif
