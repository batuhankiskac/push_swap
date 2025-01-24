# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 20:00:51 by bkiskac           #+#    #+#              #
#    Updated: 2025/01/24 12:37:18 by bkiskac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	src\push.c \
	src\swap.c \
	src\rotate.c \
	src\reverse_rotate.c \
	src\push.c \
	src\error_handle.c \
	src\sort_three.c \
	src\sort_stacks.c \
	src\init_a_to_b.c \
	src\init_b_to_a.c \
	src\stack_utils_1.c \
	src\stack_utils_2.c \
	src\stack_utils_3.c \
	src\stack_init.c

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
