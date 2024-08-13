# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 16:10:56 by ijerruz-          #+#    #+#              #
#    Updated: 2024/08/13 11:26:31 by ijerruz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:=  -Wall -Werror -Wextra \
	#-g -fsanitize=address,undefined \
	#-Wunreachable-code -Ofast 

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS	:= -I$(LIBFT)

SRCS	:= src/main.c src/parse.c src/create_struc.c \
			src/index.c \
			src/print_funcs.c

OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) $(LINK) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft