# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andresj <andresj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/05/16 08:09:37 by andresj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the executable
EXE = test
# The name of the archived library
NAME = libft.a
# Frontend program when linking
CC = cc
# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror
# Libraries to link with
LIBS = libft.h
# The name of the source files
SOURCES = ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_iscases.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c  \
					ft_putstr_fd.c  \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					test.c
# This creates a list of object files from the source files
OBJECTS = $(SOURCES:%.c=%.o)

#.PHONY: all clean fclean re

$(NAME): $(OBJECTS) $(LIBS)
	ar rcs $@ $<
# The first target, this will be the default target if none is specified
default: all
# This target tells "make" to make the "all" target
all: $(NAME)
# Target to clean up after use
clean:
	rm -f $(OBJECTS)  # Remove the object files
	rm -f $(EXE)      # Remove the executable file

fclean:
	rm -f $(NAME)

re: fclean all

%.o: %.c $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

# This will link the executable from the object files
$(EXE): $(OBJECTS) $(LIBS) test.c
	$(CC) $(CFLAGS) $(OBJECTS)  -o $(EXE) 


bonus:
