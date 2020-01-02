# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 12:50:22 by fedecomb          #+#    #+#              #
#    Updated: 2018/10/02 16:12:47 by fedecomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = ./includes/ 

NAME = libft.a

CC = gcc

FILE = $(FILE_A) $(FILE_B) $(FILE_C)

FILE_A = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd

FILE_B = lstnew lstdelone lstdel lstadd lstiter lstmap

FILE_C = create_elem convert_base nbr_mots cut_line tsl_to_rvb

FILE_D = get_next_line

FLAGS = -Wall -Wextra -Werror

PRE = $(addprefix ft_,$(FILE))

SRC = $(addsuffix .c ,$(PRE) $(FILE_D))

OBJ = $(addsuffix .o ,$(PRE) $(FILE_D))

OBJ = $(SRC:.c=.o)

INC = $(addprefix -I, $(INC_PATH))

all : $(NAME)

$(NAME): $(OBJ)
	        ar rcs $(NAME) $(OBJ)

%.o: %.c
	        $(CC) -c $(FLAGS) $(SRC) $(INC)

clean :
	        rm -rf $(OBJ)

fclean : clean
	        rm -rf $(NAME)

re : fclean all

.PHONY: re fclean clean all
