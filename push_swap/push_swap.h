/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:41:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/09 22:45:40 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				target;
	int				cost;
	struct t_node	*next;
} t_node;

int		ft_isnumeric(int c);
int		ft_numeric_args(char **ptr);
void	ft_fill(int *nums, int len);
int		ft_unique(int *nums);
int		*ft_convert(char **ptr);

#endif
