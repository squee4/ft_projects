# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 12:26:46 by ijerruz-          #+#    #+#              #
#    Updated: 2024/03/13 16:55:23 by ijerruz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for printf

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_printf.c ft_printf_utils.c main_printf.c

# Object files
OBJS = $(SRCS:.c=.o)

# Library name
NAME = libftprintf.a

# Build rule
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created"

# Object file rule
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@rm -f $(OBJS)
	@echo "Object files cleaned"

# Clean and remove library rule
fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed"

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re
