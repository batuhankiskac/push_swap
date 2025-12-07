NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

SRCS = src/operations/swap.c \
	   src/operations/push.c \
	   src/operations/rotate.c \
	   src/operations/reverse_rotate.c \
	   src/execute_push.c \
	   src/planner_a.c \
	   src/planner_b.c \
	   src/greedysort.c \
	   src/utils.c \
	   src/main.c \
	   src/stack_init.c \
	   src/stack_utils.c

BONUS_SRCS = checker_src/checker.c \
			 src/operations/swap.c \
			 src/operations/push.c \
			 src/operations/rotate.c \
			 src/operations/reverse_rotate.c \
			 src/utils.c \
			 src/stack_init.c \
			 src/stack_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C ./libft

re: fclean all

main: all clean

.PHONY: all clean fclean re main bonus
