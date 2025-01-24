# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 20:00:51 by bkiskac           #+#    #+#              #
#    Updated: 2025/01/24 20:14:10 by bkiskac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	src/push.c \
	src/swap.c \
	src/rotate.c \
	src/reverse_rotate.c \
	src/error_handle.c \
	src/sort_three.c \
	src/sort_stacks.c \
	src/init_nodes_a.c \
	src/init_nodes_b.c \
	src/stack_utils_1.c \
	src/stack_utils_2.c \
	src/stack_utils_3.c \
	src/stack_init.c

BONUS_SRCS = bonus/checker.c \
	bonus/checker_utils.c \
	bonus/push_bonus.c \
	bonus/swap_bonus.c \
	bonus/rotate_bonus.c \
	bonus/reverse_rotate_bonus.c \
	bonus/error_handle_bonus.c \
	bonus/sort_three_bonus.c \
	bonus/sort_stacks_bonus.c \
	bonus/init_nodes_a_bonus.c \
	bonus/init_nodes_b_bonus.c \
	bonus/stack_utils_1_bonus.c \
	bonus/stack_utils_2_bonus.c \
	bonus/stack_utils_3_bonus.c \
	bonus/stack_init_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) # Hem zorunlu hem bonus .o dosyalarını sil
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) # Zorunlu ve bonus çalıştırılabilir dosyaları sil
	make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re
