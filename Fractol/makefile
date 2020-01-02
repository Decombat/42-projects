# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 13:18:57 by fedecomb          #+#    #+#              #
#    Updated: 2018/12/19 16:05:22 by fedecomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ \
		   ./minilibx/ \
		   ./libft/

X = /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11
NAME = fractol
CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCL = -I $(X)
FLAGS_MLX = -framework OpenGl -framework AppKit

line = @echo "\033[31m*****************************************************\033[0m"
complete = @echo "\033[36mComplete:\033[0m"
	cleaning = @echo "\033[33mCleaning complete\033[0m"
	ok = [\033[0;32mOK\033[0m]

SRC_NAME = main.c \
		print.c \
		parse.c \
		new.c \
		event_init.c \
		event_mouse.c \
		event_keyboard.c \

INC_NAME = fractol.h

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = -L ./minilibx -lmlx ./libft/libft.a 
HED = $(addprefix ./includes/, $(INC_NAME))

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HED)
	$(line)
	@echo "Launching Makefile for Libft.."
	@make -C ./libft
	$(line)
	@echo "Launching Makefile for Minilibx.."
	@make -C ./minilibx
	$(complete)
	$(line)
	@echo "Building fractol.."
	@echo "$(ok)  Compiling sources into a program.."
	@$(CC) $(CFLAGS) $(OBJ) $(INCL) $(INC) -lpthread $(FLAGS_MLX) -o $(NAME) $(LIB)
	$(line)
	@echo "Fractol is ready to run !"

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "[\033[92m..\033[0m] Compiling $< into object file.."
	@tput cuu1;tput el;
	@$(CC) $(CFLAGS) $(INCL) $(INC) -o $@ -c $<
	@echo "$(ok)  Compiling $< into object file.."

clean: 
	$(line)	
	@echo "Cleaning process for Minilibx engaged.."
	@make clean -C ./minilibx
	$(cleaning)
	$(line)
	@echo "Cleaning process for Libft engaged.."
	@make clean -C ./libft
	$(cleaning)
	$(line)
	@echo "Cleaning process for fractol engaged.."
	@rm -rf $(OBJ_PATH)
	$(cleaning)
	$(line)

fclean: clean
	@echo "Cleaning library and program.."
	@echo "Removing program named fractol.."
	@rm -f $(NAME)
	@make fclean -C ./libft
	$(cleaning)
	$(line)

re: fclean all

run : all
	./fractol

swp: 
	@rm $(SRC_PATH)$(addsuffix .swp, $(addprefix ., *.c))
	@rm ./includes/.fractol.h.swp
	@rm .makefile.swp
