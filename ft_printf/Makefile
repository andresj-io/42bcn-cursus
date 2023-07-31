# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/07/31 18:46:31 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories to organize files
OBJ_DIR = ./objs/
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
OBJ = $(addprefix $(OBJ_DIR), $(SOURCES:%.c=%.o))

$(OBJ_DIR)%.o : %.c $(OBJ_DIR) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

default:	all

all:		$(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

# Make libft
$(LIBFT):
	make -C $(DIRLIBFT) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Remove the object files
clean:
	make -C $(DIRLIBFT) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make -C $(DIRLIBFT) fclean
	$(RM) $(NAME)

re: fclean all

test: $(DIRTEST)test.c $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o ./tests/$@ $< $(OBJ) $(LIBFT)

.PHONY: all clean fclean re libft