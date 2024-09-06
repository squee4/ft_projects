/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:52 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/06 15:34:45 by ijerruz-         ###   ########.fr       */
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
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_times;
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
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_times;
	long			last_meal;
	int				meals_taken;
	t_table			*table;
}	t_philo;

// PARSING
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_valid_args(char **argv, int i, int j);

// START
void	ft_serve_table(t_table *table, char **argv);
void	ft_create_philos(t_philo *philo, t_table *table);

//EXEC
void*	ft_routine(void *vphilo);
int		ft_lock_unlock(pthread_mutex_t *w, pthread_mutex_t *f1,
pthread_mutex_t *f2, int mode);
void	ft_act(long start, int id, int action, long pause);


//TIME
long	ft_get_time(void);
int		ft_usleep(long ms);

// ERROR
void	ft_finish(t_table *table, t_philo philo[]);

#endif
