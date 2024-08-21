/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:20:14 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/21 19:18:51 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *msg, t_data *data)
{
	int	msg_len;

	msg_len = ft_strlen(msg);
	write(2, msg, msg_len);
	if (data->arg)
		ft_free_double(data->arg);
	if (data->nums)
		free(data->nums);
	if (data->s_a)
		ft_free_stack(&data->s_a);
	if (data->s_b)
		ft_free_stack(&data->s_b);
	exit(EXIT_FAILURE);
}

void	ft_free_stack(t_node **node)
{
	t_node	*next;
	while (*node)
	{
		next = (*node)->next;
		free(*node);
		*node = next;
	}
}