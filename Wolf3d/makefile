#retirer le dossier SDL2 dans ~/.brew/Cellar/sdl2 & sdl_image

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ \
	   ./include/SDL2 \
	   ./libft/ \
#		/Users/$(shell id -un)/.brew/Cellar/sdl2/2.0.8/include/ \
#		/Users/$(shell id -un)/.brew/Cellar/sdl2_image/2.0.4/ \

LIB_PATH = SDL2-2.0.0 \
	   SDL2_image-2.0.0

NAME = wolf3d
CC = gcc -g
CFLAGS =  #-fsanitize=address -Werror -Wextra -Wall
CFLAGS_SDL2 = $(shell sdl2-config --cflags --libs)

line = @echo "\033[31m*****************************************************\033[0m"
complete = @echo "\033[36mComplete:\033[0m"
	cleaning = @echo "\033[33mCleaning complete\033[0m"
	ok = [\033[0;32mOK\033[0m]

SRC_NAME = main.c \
	clr.c \
	hook.c \
	autres.c \
	map.c \
	print.c \
	ecran.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(addprefix -l, $(LIB_PATH))
LIBFT = ./libft/libft.a 

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(line)
	@echo "Launching Makefile for Libft.."
	@make -C ./libft
	$(line)
	@echo "Building the wolf.."
	@echo "$(ok)  Compiling sources into a program.."
	@$(CC) $(CFLAGS) $(OBJ) $(INC) -L lib $(LIB) -o $(NAME) $(LIBFT)
	$(line)
	@echo "Wolf3d is ready to run !"
#	@say -v "Alex" "Wolf 3D is ready to run !"

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir obj

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "[\033[92m..\033[0m] Compiling $< into object file.."
	@tput cuu1;tput el;
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(ok)  Compiling $< into object file.."

clean: 
	$(line)
	@echo "Cleaning process for Libft engaged.."
	@make clean -C ./libft
	$(cleaning)
	$(line)
	@echo "Cleaning process for wolf3d engaged.."
	@rm -rf $(OBJ_PATH)
	$(cleaning)
	$(line)

fclean: clean
	@echo "Cleaning library and program.."
	@echo "Removing program named wolf3d.."
	@rm -f $(NAME)
	@make fclean -C ./libft
	$(cleaning)
	$(line)

re: fclean all

swp: 
	@rm $(SRC_PATH)$(addsuffix .swp, $(addprefix ., *.c))
	@rm ./includes/.wolf.h.swp
	@rm .makefile.swp
