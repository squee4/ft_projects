/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:21 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/11/27 19:30:31 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	ft_pipex(t_data *data, char **argv, char **envp)
{
	if (pipe(data->tube) == -1)
		ft_error_handler("Pipe error", data);
	data->child = fork();
	if (data->child < 0)
		ft_error_handler("Fork error", data);
	if (data->child == 0)
		ft_first_proc(data, argv, envp);
	else
	{
		data->child2 = fork();
		if (data->child2 < 0)
			ft_error_handler("Fork error", data);
		if (data->child2 == 0)
			ft_last_proc(data, argv, envp);
	}
	waitpid(data->child2, NULL, 0);
}

void	ft_last_proc(t_data *data, char **argv, char **envp)
{
	data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_in == -1)
		ft_error_handler("Outfile error", data);
	ft_arrange_pipes(data, 2);
	ft_parsing(data, argv, envp, 2);
	ft_check_perms(data);
	if (*data->args == NULL)
		ft_error_handler("No command 2 given!\n", data);
	else if (execve(data->cmd, data->args, envp) == -1)
		ft_error_handler("ERROR. Command not executed!\n", data);
}

void	ft_first_proc(t_data *data, char **argv, char **envp)
{
	data->fd_in = open(argv[1], O_RDONLY);
	if (data->fd_in == -1)
		ft_error_handler("Infile error", data);
	ft_arrange_pipes(data, 1);
	ft_parsing(data, argv, envp, 1);
	ft_check_perms(data);
	if (*data->args == NULL)
		ft_error_handler("No command 1 given!\n", data);
	else if (execve(data->cmd, data->args, envp) == -1)
		ft_error_handler("ERROR. Command not executed!\n", data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc >= 5)
	{
		if (argv[2][0] == 0 && argv[3][0] == 0)
			ft_error_handler("No commands given!", &data);
		ft_pipex(&data, argv, envp);
	}
	else
		write(1, "Wrong argument count\n", 21);
	return (0);
}
