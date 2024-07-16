/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:25:25 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/16 21:52:53 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	map_is_square(char **map)
{
	int	i;
	int j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (map[0][max])
		max++;
	while (map[i])
	{
		while (map[i][j])
		{
			if (j > max)
				return (0);
			j++;
		}
		if (i > max)
			return (0);
		i++;
	}
	return (1);
}
