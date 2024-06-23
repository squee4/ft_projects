/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:14:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/06/23 20:20:22 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	*cmd1;
	char	*cmd2;
	char	**args1;
	char	**args2;
	int		tube[2];
	pid_t	child;
	int		status;
}	t_data;

int		ft_fill_data(t_data *data, char **argv, char **envp);
void	ft_free_stuff(char **ptr, t_data *data);
char	**ft_get_cmd(char *str);
char	*ft_get_path(char **cmd, char **envp);
void	ft_pipex(t_data *data, char **envp);
void	ft_child_proc(t_data *data, char **envp);
//void	ft_parent_proc(t_data *data, char **envp);

#endif