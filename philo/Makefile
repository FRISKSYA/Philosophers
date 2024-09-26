# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
ADDRESSCHECK = -fsanitize=address
INCLUDES = -I$(HEADERS_DIRECTORY)
PTHREAD = -pthread

# Directories
SRCS_DIR = ./src
HEADERS_DIRECTORY = ./include
OBJS_DIR = ./obj

# Source files (list .c files without path)
SRCS = main.c\
		utils.c\
		validate_input.c\
		ft_atoi.c\
		ft_isdigit.c\
		init_data.c\
		cleanup.c\
		eat_dinner.c\
		time.c\
		getter_setter.c\
		synchro_utils.c\
		write.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# Rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created successfully$(RESET)"

sanitize: $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(ADDRESSCHECK) $(PTHREAD) $(OBJS) -o $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created successfully$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJS_DIR) was created$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)$(RESET)\c"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(NAME): $(RED)$(OBJS_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

