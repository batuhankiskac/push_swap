NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -I include

SRCS = src/operations/swap.c \
	   src/operations/push.c \
	   src/operations/rotate.c \
	   src/operations/reverse_rotate.c \
	   src/base_sort.c \
	   src/utils.c \
	   src/main.c \
	   src/stack_init.c \
	   src/stack_utils.c \
	   src/quicksort.c

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

main: all clean

.PHONY: all clean fclean re
