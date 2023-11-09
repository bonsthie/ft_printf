CC = clang
CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRC_DIR = src
OBJ_DIR = obj
LIBDIR = ./libft
INC_DIR = -I./includes -I./libft
LDFLAGS = -L$(LIBDIR) -lft  # Add this line for linking with libft
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)
NAME = ft_printf

GREEN = \033[0;32m
NO_COLOR = \033[0m

all: libft $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(GREEN)-----------Linking $@------------$(NO_COLOR)"
	@$(CC) -o $@ $(OBJ) $(LDFLAGS)  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBDIR)

clean:
	@echo -e "$(GREEN)------------Cleaning objects------------$(NO_COLOR)"
	@rm -f $(OBJ) $(DEP)
	@rm -rf $(OBJ_DIR)

cleanlib :
	@echo -e "$(GREEN)-----------Cleaning libft file----------$(NO_COLOR)"
	@$(MAKE) -C $(LIBDIR) fclean

fclean: clean cleanlib
	@echo -e "$(GREEN)----------Cleaning executable----------$(NO_COLOR)"
	@rm -f $(NAME)


re: fclean all

-include $(DEP)

.PHONY: all clean fclean re libft cleanlib



