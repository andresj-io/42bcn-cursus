# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/07/15 18:06:30 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the archived library
NAME = libft.a

# Libraries to link with
HEAD = libft.h

# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror -I.

# The name of the source files
SOURCES = ft_iscases.c \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
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

BONUSSRC = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

# This creates a list of object files from the source files
OBJECTS = $(SOURCES:%.c=%.o)
BONUSOBJECTS = $(BONUSSRC:%.c=%.o)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

default: all

all: $(NAME)

# Remove the object files
clean:
	rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: .bonus

.bonus: $(BONUSOBJECTS) $(OBJECTS)
	ar rcs $(NAME) $(BONUSOBJECTS) $(OBJECTS)
	touch .bonus

%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re