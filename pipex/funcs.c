/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:22:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/06/25 18:30:53 by ijerruz-         ###   ########.fr       */
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
	data->args1 = ft_get_args(argv[2], data);
	/* if (data->args1 && data->args1[1] && !ft_strncmp(data->args1[1], "spc", 3))
		data->cmd1 = data->args1[0];
	else  */
	if (data->args1 && *data->args1 && ft_strchr(*data->args1, '/'))
		data->cmd1 = data->args1[0];
	else
		data->cmd1 = ft_get_path(data->args1, envp);
	data->args2 = ft_get_args(argv[3], data);
	/* if (data->args2 && data->args2[1] && !ft_strncmp(data->args2[1], "spc", 3))
		data->cmd2 = data->args2[0];
	else  */
	if (data->args2 && *data->args2 && ft_strchr(*data->args2, '/'))
		data->cmd2 = data->args2[0];
	else
		data->cmd2 = ft_get_path(data->args2, envp);
	if (!*data->args1 && !*data->args2)
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
		if (data->args2)
			free(data->args2);
		if (data->cmd1)
			free(data->cmd1);
		if (data->cmd2)
			free(data->cmd2);
	}
}

char	**ft_get_args(char *str, t_data *data)
{
	/* int		i;
	int		len;
	char	**aux;

	if (!str)
		return (ft_calloc(1, sizeof(char *)));
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != 32)
			break;
		if (i == len)
		{
			aux = malloc(sizeof(char *) * 3);
			if (!aux)
				ft_error_handler("Malloc error\n", data);
			aux[0] = ft_strdup(str);
			aux[1] = ft_strdup("spc");
			aux[2] = 0;
			return (aux);
		}
		i++;
	} */
	(void) data;
	return (ft_split(str, ' '));
}

char	*ft_get_path(char **cmd, char **envp)
{
	int		i;
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
		if (cmd[0])
			ret = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(ret, X_OK) == 0)
			return (ft_free_stuff(paths, 0), ret);
	}
	if (ret)
		free(ret);
	return (ft_free_stuff(paths, 0), NULL);
}
