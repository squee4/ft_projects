/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:21 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/07 22:02:33 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

int	ft_append_str(char **ptr, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	while (ptr[i])
		i++;
}

void	ft_parent_proc(t_data *data, char **envp)
{
	close(data->tube[1]);
	dup2(data->tube[0], STDIN_FILENO);
	close(data->tube[0]);
	dup2(data->fd_out, STDOUT_FILENO);
	close(data->fd_out);
	if (ft_strchr(data->cmd2, '/') && access(data->cmd2, F_OK) == -1)
		ft_error_handler("File or directory does not exist\n", data, 1, 1);
	else if (!ft_strchr(data->cmd2, '/') && access(data->cmd2, F_OK) == -1)
		ft_error_handler("Command not found\n", data, 1, 1);
	if (access(data->cmd2, X_OK) == -1)
		ft_error_handler("No execution permission", data, 1, 1);
	execve(data->cmd2, data->args2, envp);
	ft_error_handler("ERROR. Command not executed!\n", data, 1, 1);
}

void	ft_child_proc(t_data *data, char **envp)
{
	close(data->tube[0]);
	dup2(data->fd_in, STDIN_FILENO);
	close(data->fd_in);
	dup2(data->tube[1], STDOUT_FILENO);
	close(data->tube[1]);
	if (ft_strchr(data->cmd1, '/') && access(data->cmd1, F_OK) == -1)
		ft_error_handler("Such file or directory does not exist\n", data, 1, 1);
	else if (!ft_strchr(data->cmd1, '/') && access(data->cmd1, F_OK) == -1)
		ft_error_handler("Command not found\n", data, 1, 1);
	if (access(data->cmd1, X_OK) == -1)
		ft_error_handler("No execution permission", data, 1, 1);
	execve(data->cmd1, data->args1, envp);
	ft_error_handler("ERROR. Command not executed!\n", data, 1, 1);
}

void	ft_pipex(t_data *data, char **envp)
{
	if (pipe(data->tube) == -1)
		ft_error_handler("Pipe error", data, 1, 1);
	data->child = fork();
	if (data->child == -1)
		ft_error_handler("Fork error", data, 1, 1);
	if (data->child == 0)
		ft_child_proc(data, envp);
	else
		ft_parent_proc(data, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 5)
	{
		data.fd_in = open(argv[1], O_RDONLY);
		data.fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (data.fd_in == -1 || data.fd_out == -1)
		{
			close(data.fd_in);
			close(data.fd_out);
			ft_error_handler("File error\n", &data, 1, 1);
		}
		
		if (ft_fill_data(&data, argv, envp))
			ft_error_handler("No commands given\n", &data, 1, 1);
		ft_pipex(&data, envp);
	}
	else
		write(1, "Wrong argument count\n", 21);
	return (0);
}
