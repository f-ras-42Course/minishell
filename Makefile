# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/09/05 13:47:11 by fras          #+#    #+#                  #
#    Updated: 2023/11/16 12:33:25 by juvan-to      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include -I/usr/local/opt/readline/include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f

ifdef DEBUG
CFLAGS += -g -D DEBUG=-1
MLX42_DEBUG = -DDEBUG=1
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif


# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L/usr/local/opt/readline/lib -lreadline $(INCLUDE)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MAKE) directories
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCLUDE)

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p
	@mkdir -p build

# Cleaning
clean:
	@$(RM) -r obj
	@$(RM) -r build

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Debugging
debug:
	$(MAKE) DEBUG=1 

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Info Message
message:
	@echo "\033[92m$(EXECUTABLE) is ready for usage!\033[0m"
.PHONY:	all clean fclean re