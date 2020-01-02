# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 12:50:22 by fedecomb          #+#    #+#              #
#    Updated: 2018/04/11 15:04:06 by fedecomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FILE = $(FILE_A) $(FILE_B) $(FILE_C)

FILE_A = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd

FILE_B = lstnew lstdelone lstdel lstadd lstiter lstmap

FILE_C = create_elem convert_base nbr_mots 

FLAGS = -Wall -Wextra -Werror

PRE = $(addprefix ft_,$(FILE))

SRC = $(addsuffix .c ,$(PRE))

OBJ = $(addsuffix .o ,$(PRE))

INC = libft.h

all : $(NAME)

$(NAME) :
		$(CC) -c $(SRC) $(FLAGS) -I $(INC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
