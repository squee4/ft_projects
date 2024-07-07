/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/07 19:09:25 by ijerruz-         ###   ########.fr       */
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

int	ft_fill_data(t_data *data, char **argv, char **envp)
{
	data->args1 = ft_get_args(argv[2]);
	if (*data->args1 != NULL && ft_strchr(*data->args1, '/'))
		data->cmd1 = data->args1[0];
	else if (*data->args1 != NULL)
		data->cmd1 = ft_get_cmd(data->args1, envp);
	data->args2 = ft_get_args(argv[3]);
	if (*data->args2 != NULL && ft_strchr(*data->args2, '/'))
		data->cmd2 = data->args2[0];
	else if (*data->args2 != NULL)
		data->cmd2 = ft_get_cmd(data->args2, envp);
	if (*data->args1 == NULL && *data->args2 == NULL)
		return (1);
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
		if (data->cmd1)
			free(data->cmd1);
		if (data->cmd2)
			free(data->cmd2);
		if (data->args2)
			free(data->args2);
	}
}

char	**ft_get_args(char *str)
{
	char	**ret;
	char	**mainarg;
	char	**aux;

	if (!str)
		return (ft_calloc(1, sizeof(char **)));
	if (ft_strchr(str, '\''))
	{
		aux = ft_split(str, '\'');
		mainarg = ft_split(aux[0], ' ');
		ret = ft_append_str(mainarg, aux[1]);
		ft_free_stuff(aux, 0, 0, 0);
		ft_free_stuff(mainarg, 0, 0, 0);
	}
	else
		ret = ft_split(aux[0], ' ');
	return (ret);
}

char	*ft_get_cmd(char **args, char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;
	char	*ret;

	if (args[0][0] == 0)
		return (NULL);
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
		ret = ft_strjoin(tmp, args[0]);
		if (access(ret, X_OK) == 0)
			return (free(tmp), ft_free_stuff(paths, 0, 0, 0), ret);
	}
	return (free(ret), ft_free_stuff(paths, 0, 0, 0), NULL);
}
