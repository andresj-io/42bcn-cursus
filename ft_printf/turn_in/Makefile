# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andresj <andresj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/07/23 05:41:39 by andresj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the archived library
NAME = libftprintf.a

# Libraries to link with
LIBRARIES = libft/libft.a

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror -I.

# The name of the source files
SOURCES = ft_printf.c \
	ft_printf_char.c \
	ft_printf_flags.c \
	ft_printf_hex.c \
	ft_printf_numbers.c \
	ft_printf_parsef.c \
	ft_printf_writes.c \
	libft \
	libftprintf.h

# Extracted object files
$(EXT_OBJ): $(LIBRARIES:.a=.o)
	ar -x $(LIBRARIES)

# This creates a list of object files from the source files
OBJECTS = $(SOURCES:%.c=%.o)

$(NAME): $(OBJECTS) $(EXT_OBJ)
	ar rcs $@ $^

default: all

all: $(NAME)

# Remove the object files
clean:
	rm -f $(OBJECTS) $(EXT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re