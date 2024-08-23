/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:41:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/24 00:55:18 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				target;
	int				cost;
	int				tcost;
	struct s_node	*next;
}	t_node;

typedef struct s_data
{
	char	**arg;
	int		*nums;
	int		count;
	int		size_a;
	int		size_b;
	int		alloc;
	t_node	*s_a;
	t_node	*s_b;
}	t_data;

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
void	ft_sort_a(t_node **a, t_data *data);
int		ft_is_sorted(t_node *node);
void	ft_start(int argc, char **argv, t_data *data);

//push_swap
void	ft_fill_b(t_data *data);
void	ft_set_cost(t_node **stack, int size);
void	ft_set_target_b(t_node **stackb, t_node *stacka);
void	ft_set_tcost(t_node **stackb, t_node *stacka);
void	ft_sorting_algo(t_data *data);
void	ft_move(int a, int b, t_data *data);

//error
void	ft_error(char *msg, t_data *data);
void	ft_free_stack(t_node **node);
void	ft_finish(t_data *data);

//movements
void	ft_push_a(t_data *data, int p);
void	ft_push_b(t_data *data, int p);
void	ft_swap(t_node **stack, int p);
void	ft_rotate(t_node **stack, int p);
void	ft_rev_rotate(t_node **stack, int p);
void	ft_swap_double(t_node **sa, t_node **sb, int p);
void	ft_rotate_double(t_node **sa, t_node **sb, int p);
void	ft_rev_rotate_double(t_node **sa, t_node **sb, int p);

//bonus
char	*get_next_line(int fd);

#endif
