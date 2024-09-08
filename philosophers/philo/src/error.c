/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:56:19 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/06 15:35:10 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_finish(t_table *table, t_philo philo[])
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		//pthread_detach ???
		pthread_join(philo[i].thread);
		i++;
	}
	i = 0;
	pthread_mutex_destroy(&table->write_lock);
	while (i < table->count)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
}
