/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:29:51 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/24 17:13:36 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		newlen;

	i = 0;
	newlen = 0;
	while (s1[i++])
		newlen++;
	i = 0;
	while (s2[i++])
		newlen++;
	ret = (char *)malloc(sizeof(char) * (newlen + 1));
	i = -1;
	j = -1;
	if (!ret)
		return (0);
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = 0;
	return (ret);
}
