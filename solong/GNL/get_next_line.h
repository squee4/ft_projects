/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:10:26 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/07/16 21:21:10 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_get_data(int fd, char *strg);
char	*ft_to_break(char *strg);
char	*ft_hold_rest(char *strg);

void	*ft_gnlcalloc(size_t count, size_t size);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_gnlstrchr(char *s, char c);
int		ft_gnlstrlen(char *s);
char	*ft_free(char **str);

#endif