CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf
SRCS = ft_printf.c  \
	   flag.c \
	   ft_strchr.c \
	   ft_strlen.c \
	   ft_putstr.c \
	   ft_itoa.c \
	   ft_isdigit.c \
	   ft_putchar.c

OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

