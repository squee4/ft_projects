/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:21 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/06/23 21:45:25 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	ft_parent_proc(t_data *data, char **envp)
{
	close(data->tube[1]);
	dup2(data->tube[0], STDIN_FILENO);
	close(data->tube[0]);
	dup2(data->fd_out, STDOUT_FILENO);
	close(data->fd_out);
	if (ft_strchr(data->cmd2, '/') && access(data->cmd2, F_OK) == -1)
	{
		// mensaje no such file or directory
		//	exit (127);
	}
	else if (!ft_strchr(data->cmd2, '/') && access(data->cmd2, F_OK) == -1)
		// mensaje command not found
		//	exit (127);
	if (access(data->cmd2, X_OK) == -1)
		// mensaje no permiso de ejecucion
		//	exit (126);
	execve(data->cmd2, data->args2, envp); //EJECUTAMOS CMD CON ENVP
}

void	ft_child_proc(t_data *data, char **envp)
{
	close(data->tube[0]); //cerramos el extremo de tube que no vamos a usar
	dup2(data->fd_in, STDIN_FILENO); //asignamos a stdin el input
	close(data->fd_in); //cerramos el fd de input, ahora duplicado
	dup2(data->tube[1], STDOUT_FILENO); //asignamos a stdout la tube[out]
	close(data->tube[1]); //cerramos fd de tube[out] ahora duplicado
	if (ft_strchr(data->cmd2, '/') && access(data->cmd2, F_OK) == -1)
	{
		// mensaje no such file or directory
		//	exit (127);
	}
	else if (!ft_strchr(data->cmd2, '/') && access(data->cmd2, F_OK) == -1)
		// mensaje command not found
		//	exit (127);
	if (access(data->cmd2, X_OK) == -1)
		// mensaje no permiso de ejecucion
		//	exit (126);
	execve(data->cmd1, data->args1, envp); //EJECUTAMOS CMD CON ENVP
	ft_free_stuff(NULL, data);
	exit(1);
}

void	ft_pipex(t_data *data, char **envp)
{
	pipe(data->tube);
	data->child = fork();
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
		if (ft_fill_data(&data, argv, envp))
		{
			

			
		}
		data.fd_in = open(argv[1], O_RDONLY);
		data.fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (data.fd_in == -1 || data.fd_out == -1)
		{
			close(data.fd_in);
			close(data.fd_out);
			write(2, "Erroraso ficherístico mi pana\n", 31);
			exit(EXIT_FAILURE);
    	}
		ft_pipex(&data, envp);
	}
	else
		write(1, "Pipex: wrong arguments\n", 23);
	return (0);
}
