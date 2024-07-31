# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 16:10:56 by ijerruz-          #+#    #+#              #
#    Updated: 2024/07/31 03:27:48 by ijerruz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:=  -Wall -Werror -Wextra \
	-Wunreachable-code -Ofast \
	-g #-fsanitize=address,undefined

MLX_DIR = ./MLX42/build
MLX		= $(MLX_DIR)/libmlx42.a
LINK	= -ldl -lglfw -pthread -lm

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS	:= -I$(LIBFT) -I$(MLX)

SRCS	:= main_solong.c \
	GNL/get_next_line.c GNL/get_next_line_utils.c \
	src/parsing.c src/map_check.c src/start_data.c src/open_window.c \
	src/images.c src/hooks.c\

OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(HEADERS) $(LINK) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft