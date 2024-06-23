/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:21:40 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/03/10 22:03:48 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*ft_write(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_hold_rest(char *text)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(text) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (text[i])
	{
		tmp[j] = text[i];
		i++;
		j++;
	}
	free(text);
	return (tmp);
}

char	*ft_get_return(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
		i--;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_get_line(int fd, char *text)
{
	char	*buf;
	int		read_bytes;

	if (!text)
		text = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		free(text);
		return (0);
	}
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buf, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			return (NULL);
		}
		buf[read_bytes] = 0;
		text = ft_write(text, buf);
	}
	free(buf);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (text)
			free(text);
		text = NULL;
		return (NULL);
	}
	text = ft_get_line(fd, text);
	if (!text)
	{
		return (NULL);
	}
	line = ft_get_return(text);
	text = ft_hold_rest(text);
	return (line);
}
