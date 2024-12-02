/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:14:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/02 14:17:44 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	*cmd;
	char	**args;
	int		tube[2];
	pid_t	child;
	pid_t	child2;
}	t_data;

void	ft_arrange_pipes(t_data *data, int mode);
void	ft_free_stuff(char **ptr, t_data *data);
char	**ft_get_args(char *str);
char	*ft_search_command(char **cmd, char **envp);
void	ft_pipex(t_data *data, char **argv, char **envp);
void	ft_first_proc(t_data *data, char **argv, char **envp);
void	ft_last_proc(t_data *data, char **argv, char **envp);
void	ft_error_handler(char *message, t_data *data);
char	**ft_append_str(char **ptr, char *str);
void	ft_check_perms(t_data *data);
void	ft_parsing(t_data *data, char **argv, char **envp, int mode);

#endif