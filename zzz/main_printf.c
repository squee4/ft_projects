/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:40:15 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/03/11 14:20:35 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// cspdiuxX%
	printf("Char\n");
	printf("Original -> %c\n", 'a');
	ft_printf("Crafted -> %c\n", 'a');
	printf("----------\n");
	
	printf("Str\n");
	printf("Original -> %s\n", "hola");
	ft_printf("Crafted -> %s\n", "hola");
	printf("----------\n");

	char	awebo;
	awebo = 64;
	printf("Pointer\n");
	printf("Original -> %p\n", &awebo);
	ft_printf("Crafted -> %p\n", &awebo);
	printf("----------\n");

	printf("Double\n");
	printf("Original -> %d\n", 256);
	ft_printf("Crafted -> %d\n", 256);
	printf("----------\n");

	printf("Int\n");
	printf("Original -> %i\n", -128);
	ft_printf("Crafted -> %i\n", -128);
	printf("----------\n");

	printf("Unsigned\n");
	printf("Original -> %u\n", 9856985);
	ft_printf("Crafted -> %u\n", 9856985);
	printf("----------\n");

	printf("Hexa minus\n");
	printf("Original -> %x\n", 8777555);
	ft_printf("Crafted -> %x\n", 8777555);
	printf("----------\n");

	printf("Hexa mayus\n");
	printf("Original -> %X\n", 8777555);
	ft_printf("Crafted -> %X\n", 8777555);
	printf("----------\n");

	printf("Percent\n");
	printf("Original -> %%\n");
	ft_printf("Crafted -> %%\n");
	printf("----------\n");
	
	// Print a list of numbers.
	int numbers[] = {1, 2, 3, 4, 5};
	for (unsigned long i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
		ft_printf("%d\n", numbers[i]);
}