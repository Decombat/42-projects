# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 13:58:03 by abiestro          #+#    #+#              #
#    Updated: 2018/04/16 14:49:01 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror
INCLUDES	=	fillit.h
LIBFTPASS= ../libft

SRCS= main.c \
	  parse.c \
	  map.c \
	  shape.c \
	  positions.c \
	  checks.c


OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd $(LIBFTPASS) && $(MAKE)
	gcc -o $(NAME) $(OBJS) $(LIBFTPASS)/libft.a


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	cd $(LIBFTPASS) && $(MAKE) clean
	rm -f $(OBJS)

fclean: clean
	cd $(LIBFTPASS) && rm -rf libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
