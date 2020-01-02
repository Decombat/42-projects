SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ \
	   ./minilibx/ \
	   ./libft/includes/

NAME = fdf
CC = gcc -g
CFLAGS = -Werror -Wextra -Wall

complete = @echo "\033[36mComplete:\033[0m"
cleaning = @echo "\033[33mCleaning complete\033[0m"
ok = [\033[0;35mOK\033[0m]

SRC_NAME = main.c \
	   parse.c \
	   hook.c \
  	   traceur.c \
	   p_iso.c \
	   autres.c \
	   erreur.c \
	   color.c 	\
	   new.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = -L ./minilibx -lmlx ./libft/libft.a 

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "*****************************************************"
	@echo "Launching Makefile for Libft.."
	@make -C ./libft
	@echo "*****************************************************"
	@echo "Launching Makefile for Minilibx.."
	@make -C ./minilibx
	$(complete)
	@echo "*****************************************************"
	@echo "Building fdf.."
	@echo "$(ok)  Compiling sources into a program.."
	@$(CC) $(CFLAGS) $(OBJ) $(INC) -framework OpenGL -framework AppKit -o $(NAME) $(LIB)
	@echo "*****************************************************"
	@echo "Your fdf is ready to run !"

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "[\033[92m..\033[0m] Compiling $< into object file.."
	@tput cuu1;tput el;
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(ok)  Compiling $< into object file.."

clean: 
	@echo "*****************************************************"
	@echo "Cleaning process for Minilibx engaged.."
	@make clean -C ./minilibx
	$(cleaning)
	@echo "*****************************************************"
	@echo "Cleaning process for Libft engaged.."
	@make clean -C ./libft
	$(cleaning)
	@echo "*****************************************************"
	@echo "Cleaning process for fdf engaged.."
	@rm -rf ./objs
	$(cleaning)
	@echo "*****************************************************"

fclean: clean
	@echo "Cleaning library and program.."
	@echo "Removing program named fdf.."
	@rm -f $(NAME)
	@make fclean -C ./libft
	$(cleaning)
	@echo "*****************************************************"

re: fclean all
