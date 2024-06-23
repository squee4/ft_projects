/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:05:30 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/11 18:41:56 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s) - start;
	}
	ret = (char *)(malloc(sizeof(char) * (len + 1)));
	if (ret == 0)
	{
		return (NULL);
	}
	ft_memcpy(ret, &s[start], len);
	ret[len] = '\0';
	return (ret);
}
