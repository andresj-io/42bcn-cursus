# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/07/24 12:52:18 by ajacome-         ###   ########.fr        #
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

$(DIROBJS)%.o : %.c $(PRINTLIB) $(EXT_OBJ)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(DIROBJS) $(OBJECTS) $(EXT_OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECTS) $(EXT_OBJ)

default: all

all: $(NAME)

# Remove the object files
clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXT_OBJ)
	$(RM) -r $(DIROBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(LIBFT):
	make -C $(DIRLIBFT) all

test: $(DIRTEST)test.c $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o ./tests/$@ $< $(OBJECTS) $(LIBFT)

# %.o: %.c $(PRINTLIB) $(EXT_OBJ)
# 	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re libft