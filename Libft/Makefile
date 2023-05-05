# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andresj <andresj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:33:54 by andresj           #+#    #+#              #
#    Updated: 2023/05/04 09:05:51 by andresj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-g -Wall -Wextra -Werror

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^ libft.h

test: *.o test.c
	$(CC) $(CFLAGS) -o test test.c *.o

all:
	$(CC) $(CFLAGS) -o $(NAME)

clean:
	rm *.o $@ $^

fclean:

re: