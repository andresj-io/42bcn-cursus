# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/08/01 12:15:53 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** variables ************************************* #
# Directories to organize files
objects_dir = ./objs/
include_dir = include/
test_dir = ./tests/
libft_dir = libft/

# The name of the archived library
NAME = libftprintf.a

# Libraries to link with
libft = libft.a
libft_head = $(libft_dir)$(include_dir)libft.h
print_head = $(include_dir)ft_printf.h

# The name of the source files
src = \
ft_printf.c \
ft_printf_char.c \
ft_printf_flags.c \
ft_printf_hex.c \
ft_printf_numbers.c \
ft_printf_writes.c \

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror
# -I is a preprocessor flag, not a compiler flag
CPPFLAGS = -I $(libft_head) -static -L$(libft_dir) -llibft -MMD -MP

RM = rm -f
AR = ar rcs

# This creates a list of object files from the source files
objects = $(addprefix $(objects_dir), $(src:%.c=%.o))

definitions = $(objects:.o=.d)
# **************************** RULES ***************************************** #
all: $(NAME)

# Set dependancy for all object files from the ft_printf.h header file
$(objects): $(print_head) $(libft_head)

# Creates the obj directory to store object and dependancy files
$(objects_dir):
	@echo Created /obj/
	@mkdir -p $(objects_dir)

# Compile object files from soruce files 
$(objects_dir)%.o: %.c Makefile | $(objects_dir)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Create archive library using libft.a
$(NAME): $(libft_dir)$(libft) $(objects_dir) $(objects)
	ar rcs $@ $^
# $(AR) $(NAME) $(objects)

# Make libft
$(libft):
	cd $(libft_dir) && make all

.PHONY: all clean fclean re libft

# Remove the object files
clean:
	make -C $(libft_dir) clean
	$(RM) -r $(objects_dir)

fclean: clean
	make -C $(libft_dir) fclean
	$(RM) $(NAME)

re: fclean all

# Include the generated dependency files
-include $(definitions)

test: $(test_dir)test.c $(objects) $(libft)
	$(CC) $(CFLAGS) -o ./tests/$@ $< $(objects) $(libft)
