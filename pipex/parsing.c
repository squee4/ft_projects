/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:32:01 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/11 03:26:42 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	ft_parsing(t_data *data, char **argv, char **envp, int n)
{
	int	cmdno;

	cmdno = n + 1;
	data->args = ft_get_args(argv[cmdno]);
	if (*data->args != NULL && ft_strchr(*data->args, '/'))
		data->cmd = data->args[0];
	else if (*data->args != NULL)
		data->cmd = ft_search_command(data->args, envp);
	else
		data->cmd = NULL;
}

char	**ft_append_str(char **ptr, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	while (ptr[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (ptr[i])
	{
		tmp[i] = ft_strdup(ptr[i]);
		i++;
	}
	tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	return (tmp);
}

char	**ft_get_args(char *str)
{
	char	**mainarg;
	char	**aux;
	char	**ret;

	if (!str)
		return (ft_calloc(1, sizeof(char **)));
	if (ft_strchr(str, '\''))
	{
		aux = ft_split(str, '\'');
		mainarg = ft_split(aux[0], ' ');
		ret = ft_append_str(mainarg, aux[1]);
		ft_free_stuff(aux, 0);
		ft_free_stuff(mainarg, 0);
		return (ret);
	}
	else
		return (ft_split(str, ' '));
}

char	*ft_search_command(char **args, char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;
	char	*exe;

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
		exe = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (access(exe, F_OK | X_OK) == 0)
			return (ft_free_stuff(paths, 0), exe);
		free(exe);
	}
	return (ft_free_stuff(paths, 0), NULL);
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
		ptr = NULL;
	}
	else
	{
		if (data->args)
			ft_free_stuff(data->args, 0);
		if (data->cmd)
			free(data->cmd);
	}
}
