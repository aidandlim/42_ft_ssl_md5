NAME = ft_ssl

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = sources/
OBJ_DIR = objects/
INC_DIR = ./includes
LIB_DIR = resources/libft/
PRF_DIR = resources/printf/

C_FILE = *.c
O_FILE = *.o

GREEN_BOLD = \033[1;34m
WHITE_BOLD = \033[1;37m
YELLOW = \033[0;32m
UNDERLINE = \033[1;4;37m
RESET = \033[0;37m

all: $(NAME)

$(NAME): clean src libft printf link
	
src:
	@echo ""
	@echo "$(GREEN_BOLD)FT_SSL > $(WHITE_BOLD)Welcome! The compiling process is initializing.$(RESET)"
	@echo ""
	@echo "  [   ]  Compile the $(UNDERLINE)ft_ssl_md5$(RESET).\c"
	@$(CC) $(FLAGS) -c $(SRC_DIR)$(C_FILE) -I $(INC_DIR)
	@mkdir $(OBJ_DIR) && mv $(O_FILE) $(OBJ_DIR)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5

libft:
	@echo "  [   ]  Load $(UNDERLINE)libft$(RESET) function into ft_ssl_md5.\c"
	@$(CC) $(FLAGS) -c $(LIB_DIR)$(C_FILE) -I $(INC_DIR)
	@mv $(O_FILE) $(OBJ_DIR)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5

printf:
	@echo "  [   ]  Load $(UNDERLINE)ft_printf$(RESET) function into ft_ssl_md5.\c"
	@$(CC) $(FLAGS) -c $(PRF_DIR)$(C_FILE) -I $(INC_DIR)
	@mv $(O_FILE) $(OBJ_DIR)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5

link:
	@echo "  [   ]  Link object files into $(UNDERLINE)executable file.$(RESET)\c"
	@gcc $(FLAGS) -o $(NAME) $(OBJ_DIR)$(O_FILE)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5
	@echo "$(GREEN_BOLD)FT_SSL > $(WHITE_BOLD)It has been completed. Enjoy :)$(RESET)"
	@echo ""

clean: 
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette ./sources/*.c
	norminette ./includes/*.h
	norminette ./resources/libft/*.c
	norminette ./resources/printf/*.c
