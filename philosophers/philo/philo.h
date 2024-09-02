/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:52 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/02 20:49:57 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

typedef struct s_table
{
	int	count;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	eat_times;
}	t_table;

int	ft_atoi(const char *str);

#endif