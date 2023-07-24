# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/07/24 11:33:20 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories to organize files
DIROBJS = ./objs/
DIRTEST = ./tests/
DIRLIBFT = ./libft/

# The name of the archived library
NAME = libftprintf.a

# Libraries to link with
LIBFT = $(DIRLIBFT)libft.a
PRINTLIB = ft_printf.h

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror -I.

RM = rm -f
AR = ar rcs

# The name of the source files
SOURCES = ft_printf.c \
	ft_printf_char.c \
	ft_printf_flags.c \
	ft_printf_hex.c \
	ft_printf_numbers.c \
	ft_printf_parsef.c \
	ft_printf_writes.c \

# Extracted object files
$(EXT_OBJ): $(LIBRARY:.a=.o)
	ar -x $(LIBRARY)

# This creates a list of object files from the source files
OBJECTS = $(addprefix $(DIROBJS), $(SOURCES:%.c=%.o))

$(DIROBJS):
	mkdir -p $(DIROBJS)

$(DIROBJS)%.o : $(DIRSRC)%.c $(PRINTLIB)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(DIROBJS) $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

default: all

all: $(NAME)

# Remove the object files
clean:
	$(RM) $(OBJECTS) $(EXT_OBJ)
	$(RM) $(addprefix $(DIROBJS), $(notdir$(OBJECTS)))

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(LIBFT):
	make -C $(DIRLIBFT) all

test: $(DIRTEST)test.c $(NAME)
	$(CC) $(CFLAGS) -o $@ $< $(NAME)

%.o: %.c $(PRINTLIB) $(EXT_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re libft