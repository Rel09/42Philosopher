
CC = gcc
RM = rm -rf
FLAG = -Wall -Wextra -Werror
################################### Main ###################################
NAME = philo
FILES :=	main parser logger

SRCS_DIR = ./
OBJS_DIR = ./obj/
############################# Colors & Prompt ###############################
RED="\033[1;31m";
CYAN="\033[1;36m"
GREEN="\033[1;32m"
ENDCOLOR="\033[0m"
CLEANING := $(GREEN)[+] Cleaning Completed$(ENDCOLOR)
SUCCESS := $(GREEN)[+] $(NAME) Successfully Compiled!$(ENDCOLOR)
############################ Compilation Main ###############################
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@echo $(SUCCESS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAG) -c $< -o $@
	@echo $(CYAN)[-] Compiling: $@$(ENDCOLOR)
################################# Cleaning ##################################
clean:
	@$(RM) $(OBJS)
	@echo $(CLEANING)

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)

re: fclean all
################################## Phony ####################################
.PHONY: all clean fclean re
