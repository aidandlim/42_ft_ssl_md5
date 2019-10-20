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
	@$(CC) -c $(SRC_DIR)$(C_FILE) -I $(INC_DIR)
	@mkdir $(OBJ_DIR) && mv $(O_FILE) $(OBJ_DIR)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5

libft:
	@echo "  [   ]  Load $(UNDERLINE)libft$(RESET) function into ft_ssl_md5.\c"
	@$(CC) -c $(LIB_DIR)$(C_FILE) -I $(INC_DIR)
	@mv $(O_FILE) $(OBJ_DIR)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5

printf:
	@echo "  [   ]  Load $(UNDERLINE)ft_printf$(RESET) function into ft_ssl_md5.\c"
	@$(CC) -c $(PRF_DIR)$(C_FILE) -I $(INC_DIR)
	@mv $(O_FILE) $(OBJ_DIR)
	@sleep 0.5
	@echo "\r  [ $(YELLOW)\xE2\x9C\x94$(RESET) ]"
	@echo ""
	@sleep 0.5

link:
	@echo "  [   ]  Link object files into $(UNDERLINE)executable file.$(RESET)\c"
	@gcc -o $(NAME) $(OBJ_DIR)$(O_FILE)
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

t:
	@echo "$(YELLOW)nothing with echo check$(RESET)"
	@echo "hello world" | ./exec md5
	@echo ""
	@echo "hello world" | ./ft_ssl md5
	
	@echo ""
	
	@echo "$(YELLOW)-s check$(RESET)"
	@./exec md5 -s "hello world"
	@echo ""
	@./ft_ssl md5 -s "hello world"

	@echo ""
	
	@echo "$(YELLOW)-r check$(RESET)"
	@./exec md5 -r ./testcase/short
	@echo ""
	@./ft_ssl md5 -r ./testcase/short

	@echo ""
	
	@echo "$(YELLOW)-p check$(RESET)"
	@echo "hello world" | ./exec md5 -p
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -p

	@echo ""
	
	@echo "$(YELLOW)-q check$(RESET)"
	@./exec md5 -q ./testcase/short
	@echo ""
	@./ft_ssl md5 -q ./testcase/short

	@echo ""
	
	@echo "$(YELLOW)-s -r check$(RESET)"
	@echo "hello world" | ./exec md5 -r -s "good morning"
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -s "good morning"

	@echo ""
	
	@echo "$(YELLOW)-r -p check$(RESET)"
	@echo "hello world" | ./exec md5 -r -p
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -p

	@echo ""
	
	@echo "$(YELLOW)-p -q check$(RESET)"
	@echo "hello world" | ./exec md5 -p -q
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -p -q

	@echo ""
	
	@echo "$(YELLOW)-q -s check$(RESET)"
	@echo "hello world" | ./exec md5 -q -s "good evening"
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -q -s "good evening"

	@echo ""
	
	@echo "$(YELLOW)-p -s check$(RESET)"
	@echo "hello world" | ./exec md5 -p -s "good morning"
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -p -s "good morning"

	@echo ""
	
	@echo "$(YELLOW)-r -q check$(RESET)"
	@echo "hello world" | ./exec md5 -r -q ./testcase/short
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -q ./testcase/short

	@echo ""
	
	@echo "$(YELLOW)-r -q -s check$(RESET)"
	@echo "hello world" | ./exec md5 -r -q -s "good evening" ./testcase/short
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -q -s "good evening" ./testcase/short

	@echo ""

	@echo "$(YELLOW)-r -p -s check$(RESET)"
	@echo "hello world" | ./exec md5 -r -p -s "good evening" ./testcase/short
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -p -s "good evening" ./testcase/short
	
	@echo ""

	@echo "$(YELLOW)-s -r -p -q check$(RESET)"
	@echo "hello world" | ./exec md5 -r -p -q -s "good evening" ./testcase/short ./testcase/file errorfile
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -p -q -s "good evening" ./testcase/short ./testcase/file errorfile

	@echo ""

	@echo "$(YELLOW)-s -r -p -q check$(RESET)"
	@echo "hello world" | ./exec md5 -r -p -q -s "good evening" -s "good" hello ./testcase/medium
	@echo ""
	@echo "hello world" | ./ft_ssl md5 -r -p -q -s "good evening" -s "good" hello ./testcase/medium

	@echo ""
	@echo "$(GREEN_BOLD)SHA256$(RESET)"
	@echo ""

	@echo "$(YELLOW)nothing with echo check$(RESET)"
	@echo "hello world" | ./exec sha256
	@echo ""
	@echo "hello world" | ./ft_ssl sha256
	
	@echo ""
	
	@echo "$(YELLOW)-s check$(RESET)"
	@./exec sha256 -s "hello world"
	@echo ""
	@./ft_ssl sha256 -s "hello world"

	@echo ""
	
	@echo "$(YELLOW)-r check$(RESET)"
	@./exec sha256 -r ./testcase/short
	@echo ""
	@./ft_ssl sha256 -r ./testcase/short

	@echo ""
	
	@echo "$(YELLOW)-p check$(RESET)"
	@echo "hello world" | ./exec sha256 -p
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -p

	@echo ""
	
	@echo "$(YELLOW)-q check$(RESET)"
	@./exec sha256 -q ./testcase/short
	@echo ""
	@./ft_ssl sha256 -q ./testcase/short

	@echo ""
	
	@echo "$(YELLOW)-s -r check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -s "good morning"
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -s "good morning"

	@echo ""
	
	@echo "$(YELLOW)-r -p check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -p
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -p

	@echo ""
	
	@echo "$(YELLOW)-p -q check$(RESET)"
	@echo "hello world" | ./exec sha256 -p -q
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -p -q

	@echo ""
	
	@echo "$(YELLOW)-q -s check$(RESET)"
	@echo "hello world" | ./exec sha256 -q -s "good evening"
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -q -s "good evening"

	@echo ""
	
	@echo "$(YELLOW)-p -s check$(RESET)"
	@echo "hello world" | ./exec sha256 -p -s "good morning"
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -p -s "good morning"

	@echo ""
	
	@echo "$(YELLOW)-r -q check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -q ./testcase/short
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -q ./testcase/short

	@echo ""
	
	@echo "$(YELLOW)-r -q -s check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -q -s "good evening" ./testcase/short
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -q -s "good evening" ./testcase/short

	@echo ""

	@echo "$(YELLOW)-r -p -s check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -p -s "good evening" ./testcase/short
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -p -s "good evening" ./testcase/short
	
	@echo ""

	@echo "$(YELLOW)-s -r -p -q check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -p -q -s "good evening" ./testcase/short ./testcase/file errorfile
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -p -q -s "good evening" ./testcase/short ./testcase/file errorfile

	@echo ""

	@echo "$(YELLOW)-s -r -p -q check$(RESET)"
	@echo "hello world" | ./exec sha256 -r -p -q -s "good evening" -s "good" hello ./testcase/medium
	@echo ""
	@echo "hello world" | ./ft_ssl sha256 -r -p -q -s "good evening" -s "good" hello ./testcase/medium

