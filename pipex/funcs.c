/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/11 02:25:20 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	ft_error_handler(char *message, t_data *data)
{
	int	msg_len;

	msg_len = ft_strlen(message);
	write(2, message, msg_len);
	ft_free_stuff(0, data);
	exit(EXIT_FAILURE);
}

void	ft_check_perms(t_data *data)
{
	if (data->cmd && ft_strchr(data->cmd, '/') && access(data->cmd, F_OK) == -1)
		ft_error_handler("Such file or directory does not exist\n", data);
	else if (data->cmd && !ft_strchr(data->cmd, '/')
		&& access(data->cmd, F_OK) == -1)
		ft_error_handler("Command not found\n", data);
	if (data->cmd && access(data->cmd, X_OK) == -1)
		ft_error_handler("No execution permission", data);
}

void	ft_arrange_pipes(t_data *data, int mode)
{
	if (mode == 1)
	{
		close(data->tube[0]);
		dup2(data->fd_in, STDIN_FILENO);
		close(data->fd_in);
		dup2(data->tube[1], STDOUT_FILENO);
		close(data->tube[1]);
	}
	else if (mode == 2)
	{
		close(data->tube[1]);
		dup2(data->tube[0], STDIN_FILENO);
		close(data->tube[0]);
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->fd_out);
	}
}
