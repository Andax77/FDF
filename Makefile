# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anhuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 12:47:26 by anhuang           #+#    #+#              #
#    Updated: 2017/12/18 18:24:46 by anhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = src
SRC_NAME = main.c\
		   ft_keyboard.c
OBJ_PATH = obj
LDFLAGS = -L libft/
CFLAGS = -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Werror -Wextra
RM = rm -f

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(LDFLAGS) $(CFLAGS) $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create FdF"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|   was summoned  |"
	@echo "[=================]"

clean:
	RM $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	printf '\033[31m[ ✔ ] %s\n\033[0m'
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean: clean
	RM $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m'
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re, norme
