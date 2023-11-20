CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf
SRCS = ft_printf.c  \
	   ft_strchr.c \
	   ft_strlen.c

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

