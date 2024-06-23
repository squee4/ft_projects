# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 16:10:56 by ijerruz-          #+#    #+#              #
#    Updated: 2024/03/10 22:24:10 by ijerruz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= solong.a
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code
MLX_DIR = ./MLX42/build
MLX		:= $(MLX_DIR)/libmlx42.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS	:= -I$(LIBFT) -I$(MLX)
MLX_FLAGS	:= -ldl -pthread -lm
SRCS	:= main_solong.c

OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libft:
	@make -C $(LIBFT_DIR)

libmlx:
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft