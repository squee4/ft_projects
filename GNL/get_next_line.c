/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:54:46 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/14 16:55:03 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (storage)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	if ((storage && !ft_gnlstrchr(storage, '\n')) || !storage)
		storage = ft_get_data(fd, storage);
	if (!storage)
		return (ft_free(&storage));
	line = ft_to_break(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_hold_rest(storage);
	return (line);
}

char	*ft_get_data(int fd, char *strg)
{
	int		rbyte;
	char	buffer[BUFFER_SIZE + 1];

	buffer[0] = '\0';
	if (!strg)
		strg = (char *)ft_gnlcalloc(sizeof(char), 1);
	rbyte = 1;
	while (rbyte > 0 && !ft_gnlstrchr(buffer, '\n'))
	{
		rbyte = read(fd, buffer, BUFFER_SIZE);
		if (rbyte < 0)
		{
			free(strg);
			strg = NULL;
			return (NULL);
		}
		buffer[rbyte] = 0;
		strg = ft_strjoin_free(strg, buffer);
		if (!strg)
			return (NULL);
	}
	return (strg);
}

char	*ft_to_break(char *strg)
{
	int		i;
	char	*ret;

	i = 0;
	if (!strg[i])
		return (NULL);
	while (strg[i] && strg[i] != '\n')
		i++;
	if (strg[i])
		ret = ft_gnlcalloc(sizeof(char), i + 2);
	else
		ret = ft_gnlcalloc(sizeof(char), i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (strg[i] && strg[i] != '\n')
	{
		ret[i] = strg[i];
		i++;
	}
	if (strg[i])
		ret[i++] = '\n';
	ret[i] = 0;
	return (ret);
}

char	*ft_hold_rest(char *strg)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (strg[i] && strg[i] != '\n')
		i++;
	if (strg[i])
		i++;
	if ((ft_gnlstrlen(strg) - i) <= 0)
		return (ft_free(&strg));
	ret = ft_gnlcalloc(sizeof(char), ft_gnlstrlen(&strg[i]) + 1);
	if (!ret)
		return (free(strg), NULL);
	j = 0;
	while (strg[i + j])
	{
		ret[j] = strg[i + j];
		j++;
	}
	ret[j] = 0;
	ft_free(&strg);
	return (ret);
}
