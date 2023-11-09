CC = clang
CFLAGS = -Wall -Wextra -Werror 
LIBDIR = ./libft
INC_DIR = -I./libft
LDFLAGS = -L$(LIBDIR) -lft
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
NAME = ft_printf.a

GREEN = \033[0;32m
NO_COLOR = \033[0m

all: libft $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(GREEN)-----------Linking $@------------$(NO_COLOR)"
	ar rc $@ $^

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBDIR)

clean:
	@echo -e "$(GREEN)------------Cleaning objects------------$(NO_COLOR)"
	@rm -f $(OBJ) 

cleanlib :
	@echo -e "$(GREEN)-----------Cleaning libft file----------$(NO_COLOR)"
	@$(MAKE) -C $(LIBDIR) fclean

fclean: clean cleanlib
	@echo -e "$(GREEN)----------Cleaning executable----------$(NO_COLOR)"
	@rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re libft cleanlib



