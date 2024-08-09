/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:37:18 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/09 23:50:49 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	char	**ptr;
	int		*tmp;
	int		i;

	i = 0;
	if (argc == 2)
	{
		ptr = ft_split(argv[1], ' ');
		printf("Numeric - %d.\n", ft_numeric_args(ptr));
		tmp = ft_convert(ptr);
		printf("Unique - %d.\n", ft_unique(tmp));
		ft_fill(tmp, 5);
	}
	else if (argc != 1)
	{
		printf("Numeric - %d.\n", ft_numeric_args(argv + 1));
		tmp = ft_convert(argv + 1);
		printf("Unique - %d.\n", ft_unique(tmp));
		ft_fill(tmp, argc - 1);
	}
	else
		write(2, "Wrong argc\n", 11);
}
