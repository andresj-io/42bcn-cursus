# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/08/01 10:57:10 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories to organize files
objects_dir = ./objs/
test_dir = ./tests/
libft_dir = ./libft/

# The name of the archived library
NAME = libftprintf.a

# Libraries to link with
libft = $(libft_dir)libft.a
print_head = ft_printf.h

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror
# -I is a preprocessor flag, not a compiler flag
CPPFLAGS	:= -I include/ -MMD -MP

RM = rm -f
AR = ar rcs

# The name of the source files
SOURCES = ft_printf.c \
	ft_printf_char.c \
	ft_printf_flags.c \
	ft_printf_hex.c \
	ft_printf_numbers.c \
	ft_printf_writes.c \

# This creates a list of object files from the source files
OBJ = $(addprefix $(objects_dir), $(SOURCES:%.c=%.o))

$(objects_dir)%.o : %.c $(objects_dir) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

default:	all

all:		$(NAME)

$(NAME): $(libft) $(objects_dir) $(OBJ)
	cp $(libft) $(NAME)
	$(AR) $(NAME) $(OBJ)

# Make libft
$(libft):
	make -C $(libft_dir) all

$(objects_dir):
	mkdir -p $(objects_dir)

# Remove the object files
clean:
	make -C $(libft_dir) clean
	$(RM) -r $(objects_dir)

fclean: clean
	make -C $(libft_dir) fclean
	$(RM) $(NAME)

re: fclean all

test: $(test_dir)test.c $(OBJ) $(libft)
	$(CC) $(CFLAGS) -o ./tests/$@ $< $(OBJ) $(libft)

.PHONY: all clean fclean re libft