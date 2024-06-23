/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:09 by ijerruz-          #+#    #+#             */
/*   Updated: 2023/11/30 14:19:13 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c > 31 && c < 127))
		return (1);
	return (0);
}

/*
int main(void)
{
    char letra;

    letra = '5';
    printf("%d", ft_isprint(letra));
    return (0);
}*/