/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:58:56 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/23 23:33:32 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

void	*ft_gnlcalloc(size_t count, size_t size)
{
	size_t	i;
	int		*ret;

	i = 0;
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	while (i < (count * size))
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * (ft_gnlstrlen(s1) + ft_gnlstrlen(s2) + 1));
	if (!ret)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	free(s1);
	s1 = NULL;
	return (ret);
}

int	ft_gnlstrchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s && !s[i] && !(char)c)
		return (1);
	return (0);
}

int	ft_gnlstrlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
