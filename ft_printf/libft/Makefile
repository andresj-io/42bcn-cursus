# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/07/31 18:53:08 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = ./obj/
SRC_DIR = ./src/

# The name of the archived library
NAME = libft.a

# Libraries to link with
HEAD = libft.h

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS 		:= -g -Wall -Wextra -Werror
# -I is a preprocessor flag, not a compiler flag
CPPFLAGS	:= -I include/ -MMD -MP

# The name of the source files
SRC = $(wildcard $(SRC_DIR)/*.c)
SRC = \
ft_utox.c \
ft_utoa.c \
ft_strupper.c \
ft_ltox.c \
ft_lltox.c \
ft_strnstr.c \
ft_strrev.c \
ft_split.c \
ft_strchr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_iscases.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstsize.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putendl_fd.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c 

# This creates a list of object files from the source files
OBJ := $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

default: all

all: $(NAME)

$(OBJ_DIR)%.o: %.c $(OBJ_DIR) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $@ $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
