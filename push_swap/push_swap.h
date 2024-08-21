/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:41:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/21 19:22:03 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
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
	int		size_a;
	int		size_b;
	t_node	*s_a;
	t_node	*s_b;
} t_data;

//parsing
int		ft_numeric_args(t_data *data);
int		ft_atoi_magic(const char *str, t_data *data);
int		ft_unique(t_data *data);
int		*ft_convert(t_data *data);

//init
t_node	*ft_new_node(int value, t_data *data);
void	ft_add_node_top(t_node **stack, t_node *new);
void	ft_stack_a(t_data *data);
void	ft_index(t_data *data, t_node **stack);
void	ft_set_pos(t_node **stack);
void	ft_sort_a(t_node **a, t_data *data);

//push_swap
void	ft_fill_b(t_node **a, t_node **b, t_data *data);

//error
void	ft_error(char *msg, t_data *data);
void	ft_free_stack(t_node **node);

//movements
void	ft_push(t_node **dest, t_node **src, int p);
void	ft_swap(t_node **stack, int p);
void	ft_rotate(t_node **stack, int p);
void	ft_rev_rotate(t_node **stack, int p);
void	ft_swap_double(t_node **sa, t_node **sb);
void	ft_rotate_double(t_node **sa, t_node **sb, int p);
void	ft_rev_rotate_double(t_node **sa, t_node **sb);

//debugging
void	ft_print_values(t_node *list);
void	ft_print_indexes(t_node *list);
void	ft_print_pos(t_node *list);

#endif
