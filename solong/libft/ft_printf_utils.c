/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:57:58 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/03/10 22:35:55 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long nbr, char *base, int base_size)
{
	int	nbr_final[15];
	int	i;
	int	counter;

	if (!nbr)
		return (ft_putchar('0'));
	i = 0;
	counter = 0;
	if (ft_check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			counter += ft_putchar('-');
		}
		while (nbr)
		{
			nbr_final[i] = nbr % base_size;
			nbr = nbr / base_size;
			i++;
		}
		while (--i >= 0)
			counter += ft_putchar(base[nbr_final[i]]);
	}
	return (counter);
}

int	ft_putnbr_unsigned(unsigned long nbr, char *base)
{
	int				size_base;
	unsigned long	nbr_final[100];
	int				i;
	int				counter;

	if (!nbr)
		return (ft_putchar('0'));
	i = 0;
	size_base = 0;
	counter = 0;
	if (ft_check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			counter += ft_putchar(base[nbr_final[i]]);
	}
	return (counter);
}
