SRCS = push_swap.c error.c parse.c sort.c utils.c moves.c moves2.c moves3.c radix_sort.c 
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a
CFLAGS = -Werror -Wall -Wextra 
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)  $(LIBFT)
	gcc $(CFLAGS) -o push_swap $(OBJS) $(LIBFT)


$(LIBFT):
	@make -C libft

clean:
	rm -rf *.o
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re