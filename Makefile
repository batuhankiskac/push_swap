# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 20:00:51 by bkiskac           #+#    #+#              #
#    Updated: 2025/01/23 23:38:29 by bkiskac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
	src/error_handle.c \
	src/ft_init_nodes_a.c \
	src/ft_sort_stacks.c \
	src/ft_stack_init.c \
	src/reverse_rotate.c \
	src/stack_utils_1.c \
	src/stack_utils_3.c \
	src/ft_check_sorted.c \
	src/ft_init_nodes_b.c \
	src/ft_sort_three.c \
	src/push.c \
	src/rotate.c \
	src/stack_utils_2.c \
	src/swap.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
