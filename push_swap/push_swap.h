/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:41:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 23:38:16 by ijerruz-         ###   ########.fr       */
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
	int				pos;
	struct s_node	*next;
} t_node;

typedef struct s_data
{
	char	**arg;
	int		*nums;
	int		count;
	t_node	*s_a;
	t_node	*s_b;
} t_data;

int		ft_isnumeric(int c);
int		ft_numeric_args(char **ptr);
void	ft_fill(int *nums, int len);
int		ft_unique(int *nums);
int		*ft_convert(char **ptr);
void	ft_stack_a(t_node **stack, int *nums, int len);
void	ft_index(t_data *data, t_node **stack);
void	ft_set_pos(t_node **stack);
void	ft_push(t_node **dest, t_node **src);
void	ft_swap(t_node **stack);
void	ft_rotate(t_node **stack);
void	ft_rev_rotate(t_node **stack);

//debugging
void	ft_print_values(t_node *list);
void	ft_print_indexes(t_node *list);
void	ft_print_pos(t_node *list);

#endif
