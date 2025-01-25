# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 20:00:51 by bkiskac           #+#    #+#              #
#    Updated: 2025/01/25 12:42:28 by bkiskac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_1 = main.c

SRCS_2 = src/push.c \
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

BONUS_SRCS = bonus/checker.c

OBJS_1 = $(SRCS_1:.c=.o)

OBJS_2 = $(SRCS_2:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_1) $(OBJS_2)
	$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(OBJS_2)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_2) $(LIBFT) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS_1) $(OBJS_2) $(BONUS_OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re
