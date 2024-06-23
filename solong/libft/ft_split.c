/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:42:38 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/29 13:06:57 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int	w;
	int	i;
	int	flag;

	w = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (s[i] != c && flag)
		{
			flag = 0;
			w++;
		}
		i++;
	}
	return (w);
}

static int	*get_start(char const *s, char c)
{
	int	*nums;
	int	i;
	int	n;
	int	flag;

	i = 0;
	n = 0;
	flag = 1;
	nums = malloc((words(s, c) + 1) * sizeof(int));
	if (!nums)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (s[i] != c && flag)
		{
			flag = 0;
			nums[n] = i;
			n++;
		}
		i++;
	}
	nums[n] = -1;
	return (nums);
}

static size_t	ft_wordlen(const char *s, char sep)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static char	**reserva(int opt, int size)
{
	char	**ptr;

	if (opt == 0)
	{
		ptr = malloc(sizeof(char *));
		if (!ptr)
			return (0);
		ptr[0] = NULL;
	}
	else
	{
		ptr = malloc(sizeof(char *) * size);
		if (!ptr)
			return (0);
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	int		*starts;

	i = 0;
	if (!words(s, c))
		ret = reserva(0, words(s, c) + 1);
	else
		ret = reserva(1, words(s, c) + 1);
	if (!ret)
		return (NULL);
	starts = get_start(s, c);
	while (i < words(s, c))
	{
		ret[i] = ft_substr(s, starts[i], ft_wordlen(&s[starts[i]], c));
		i++;
	}
	free(starts);
	ret[i] = NULL;
	return (ret);
}
/* 
int	main(void)
{
	//get_end("--hola----que--",'-');
	//char	**pals = ft_split("aa---hola----que----tal----a-a--eb", '-');
	char	**pals = ft_split("hello!", ' ');
	while (*pals)
	{
		printf("%s\n", *pals);
		//free(*pals);
		pals++;
	}
	//free(pals);
	
	return (0);
} */