# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andresj <andresj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/08/06 17:36:34 by andresj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** formating ************************************* #
c_black		= \033[0;30m
c_red		= \033[0;31m
c_green		= \033[0;32m
c_yellow	= \033[0;33m
c_blue		= \033[0;34m
c_purple	= \033[0;35m
c_cyan		= \033[0;36m
c_white		= \033[1;37m
c_reset		= \033[0m

# **************************** directories *********************************** #
objects_dir = ./obj/
test_dir = ./tests/

# **************************** variables ************************************* #
# The name of the archived library
NAME = test
BUFFER_SIZE = 42

# Header files
gnl_head = get_next_line.h
test_head = test.h

header_files = .#$(gnl_head) $(test_head)

# The name of the source files
src = \
test.c \
get_next_line.c \
get_next_line_utils.c \

test_src = \
test.c \

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror
# -I is a preprocessor flag, not a compiler flag
CPPFLAGS = -I $(header_files) -MMD -MP
BUFFER = -D BUFFER_SIZE=$(BUFFER_SIZE)

# This creates a list of object files from the source files
objects = $(addprefix $(objects_dir), $(src:%.c=%.o))

dependacies = $(objects:.o=.d)

# **************************** rules ***************************************** #
all: no_buffer

# Set dependancy for all object files from the libft.h header file
$(objects): $(gnl_head)

# Creates the obj directory to store object and dependancy files
$(objects_dir):
	@echo "$(c_blue)Created directory: $(c_reset)/obj/"
	@mkdir -p $(objects_dir)

# Compile object files from soruce files
$(objects_dir)%.o: %.c Makefile | $(objects_dir)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

no_buffer: $(objects_dir) $(objects) Makefile
	@$(CC) $(CFLAGS) $(CPPFLAGS) *.c -o $(test_dir)$@
	@echo "$(c_blue)Compiled using default $(c_reset)BUFFER_SIZE"

buffer: $(objects_dir) $(objects) Makefile
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(BUFFER) *.c -o $(test_dir)$@
	@echo "$(c_blue)Compiled using $(c_reset)BUFFER_SIZE = $(c_yellow)$(BUFFER_SIZE) $(c_reset)"

.PHONY: all clean fclean re buffer

clean:
	@echo "$(c_blue)Deleting object files and dependacies...$(c_reset)"
	@rm -rf $(objects_dir)

fclean: clean
	@echo "$(c_blue)Deleting archived library...$(c_reset)"
	@rm -rf $(NAME)

re: fclean all

# Include the generated dependency files
-include $(dependacies)

test_objects = $(addprefix $(test_dir)$(objects_dir), $(test_src:%.c=%.o))

$(test_objects): $(test_dir)$(include_dir)$(head)

$(test_dir)$(objects_dir)%.o: %.c Makefile | $(test_dir)$(objects_dir)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# buffer: $(test_dir)$(objects_dir) $(objects_dir) $(objects) Makefile
# 	@echo "$(c_blue)Compiled using $(c_reset)BUFFER_SIZE = $(c_yellow)$(BUFFER_SIZE) $(c_reset)"
# 	@$(CC) $(CFLAGS) $(CPPFLAGS) $(BUFFER) -o $(test_dir)$@ $< $(objects)

$(test_dir)$(objects_dir):
	@echo "$(c_blue)Created directory: $(c_reset)tests/obj/"
	@mkdir -p $(test_dir)$(objects_dir)

# test: $(test_dir)$(test_src) $(objects_dir) $(objects)
# 	@$(CC) $(CFLAGS) -I $(test_dir)$(test_head) -o $(test_dir)$@ $< $(objects)
# 	@echo "$(c_yellow)Starting test: $(c_reset)"
# 	@./tests/test