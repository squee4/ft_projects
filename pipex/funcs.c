/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/06/23 21:42:32 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

int	ft_fill_data(t_data *data, char **argv, char **envp)
{
	data->args1 = ft_get_cmd(argv[2]);
	if (ft_strchr(data->args1, '/'))
		data->cmd1 = data->args1[0];
	else
		data->cmd1 = ft_get_path(data->args1, envp);
	data->args2 = ft_get_cmd(argv[3]);
	if (ft_strchr(data->args2, '/'))
		data->cmd2 = data->args2[0];
	else
		data->cmd2 = ft_get_path(data->args2, envp);
	return (0);
}

void	ft_free_stuff(char **ptr, t_data *data)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
			free(ptr[i++]);
		free(ptr);
	}
	else
	{
		if (data->args1)
			free(data->args1);
		if (data->args2)
			free(data->args2);
		if (data->cmd1)
			free(data->cmd1);
		if (data->cmd2)
			free(data->cmd2);
	}
}

char	**ft_get_cmd(char *str)
{
	return (ft_split(str, ' '));
}

char	*ft_get_path(char **cmd, char **envp)
{
	int	i;
	char	**paths;
	char	*tmp;
	char	*ret;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			paths = ft_split(&envp[i][5], ':');
	}
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(ret, X_OK) == 0)
			return (ft_free_stuff(paths, 0), ret);
	}
	return (free(ret), ft_free_stuff(paths, 0), NULL); 
}
