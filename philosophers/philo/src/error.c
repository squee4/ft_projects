/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:56:19 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/09/09 19:15:38 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_finish(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->write_lock);
	while (i < table->count)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
}
