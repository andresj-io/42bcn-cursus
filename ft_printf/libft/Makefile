# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/08/01 10:54:27 by ajacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** formating ************************************* #
white = \033[1;37m
black = \033[0;30m
red = \033[0;31m
blue = \033[0;34m
green = \033[0;32m

# **************************** variables ************************************* #
objects_dir = ./obj/
include_dir = include/

# The name of the archived library
NAME = libft.a

# Header files
head = libft.h

# The name of the source files
src = \
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
ft_lltox.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
ft_ltox.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
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
ft_strrev.c \
ft_strtrim.c \
ft_strupper.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_utoa.c \
ft_utox.c \


# Frontend program when linking
CC = gcc

# Flags for compilation
CFLAGS = -g -Wall -Wextra -Werror
# -I is a preprocessor flag, not a compiler flag
CPPFLAGS = -I $(include_dir). -MMD -MP

# This creates a list of object files from the source files
objects = $(addprefix $(objects_dir), $(src:%.c=%.o))

# **************************** RULES ***************************************** #
all: $(NAME)

# Set dependancy for all object files from the libft.h header file
$(objects): $(include_dir)$(head)
# 
$(objects_dir):
	@echo Created /obj/
	@mkdir -p $(objects_dir)

$(objects_dir)%.o: %.c Makefile | $(objects_dir)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(objects_dir) $(objects)
	@echo Archiving:
	ar rcs $@ $(objects)

.PHONY: all clean fclean re

clean:
	rm -rf $(objects_dir)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Include the generated dependency files
-include $(objects:.o=.d)