NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = \
	ft_printf.c ft_itohexstr.c ft_uitoa.c ft_put.c ft_put2.c \
	libft/ft_strlen.c libft/ft_itoa.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(NAME)
	make clean
	./a.out

.PHONY = all clean fclean re test