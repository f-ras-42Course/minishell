# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/09/05 13:47:11 by fras          #+#    #+#                  #
#    Updated: 2023/09/05 13:52:37 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include
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
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJECTS)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(RM) $(NAME)

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