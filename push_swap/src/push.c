/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:31:37 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/13 21:13:46 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	tmp = *src;
	if (!*src)
		return ;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}