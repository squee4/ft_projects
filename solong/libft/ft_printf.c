/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:09:03 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/03/10 22:33:04 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_select_format(char c, int ret, va_list argptr)
{
	if (c == 'c')
		ret += ft_putchar(va_arg(argptr, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(argptr, char *));
	else if (c == 'p')
	{
		ret += ft_putstr("0x");
		ret += ft_putnbr_unsigned(va_arg(argptr, unsigned long),
				"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr_base(va_arg(argptr, int), "0123456789", 10);
	else if (c == 'u')
		ret += ft_putnbr_unsigned(va_arg(argptr, unsigned int), "0123456789");
	else if (c == 'x')
		ret += ft_putnbr_unsigned(va_arg(argptr, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		ret += ft_putnbr_unsigned(va_arg(argptr, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(char const *s, ...)
{
	va_list	argptr;
	int		i;
	int		total;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(argptr, s);
	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == '%')
			total += ft_select_format(s[++i], 0, argptr);
		else
		{
			write(1, &s[i], 1);
			total++;
		}
		i++;
	}
	va_end(argptr);
	return (total);
}
