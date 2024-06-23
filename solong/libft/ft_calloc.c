/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:02:32 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/02/09 01:42:32 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	int		*ret;

	i = 0;
	ret = malloc(count * size);
	if (ret == 0)
		return (ret);
	while (i < (count * size))
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
