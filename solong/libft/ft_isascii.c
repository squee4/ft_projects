/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:45:49 by ijerruz-          #+#    #+#             */
/*   Updated: 2023/11/30 14:19:05 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c < 128))
		return (1);
	return (0);
}

/*
int main(void)
{
    char letra;

    letra = '5';
    printf("%d", ft_isascii(letra));
    return (0);
}*/