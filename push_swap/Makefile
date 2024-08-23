NAME	:= push_swap
NAME_BONUS	:= checker
CFLAGS	:=  -Wall -Werror -Wextra \
	#-g -fsanitize=address,undefined \
	#-Wunreachable-code -Ofast 

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS	:= -I$(LIBFT)

SRCS	:= src/main.c src/init.c src/parse.c src/create_struc.c \
			src/index.c  src/fill_b.c src/is_sorted.c src/error.c \
			src/push.c src/swap.c src/rotate.c src/rev_rotate.c \
			src/cost.c src/target.c src/tcost.c src/algo.c src/move.c \
			

OBJS	:= ${SRCS:.c=.o}

SRCS_BONUS	:= src/checker.c src/init.c src/parse.c src/create_struc.c \
			src/index.c  src/fill_b.c src/is_sorted.c src/error.c \
			src/push.c src/swap.c src/rotate.c src/rev_rotate.c \
			src/cost.c src/target.c src/tcost.c src/algo.c src/move.c \
			src/get_next_line.c src/get_next_line_utils.c 

OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}

all: libft $(NAME)

bonus: libft $(NAME) $(NAME_BONUS)

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) $(LINK) -o $(NAME)
	
$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(HEADERS) $(LINK) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(LIBFT)

re: fclean all

rebonus: fclean bonus

.PHONY: all, clean, fclean, re, bonus, rebonus, libft