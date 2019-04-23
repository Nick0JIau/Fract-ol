# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 17:03:31 by ntrusevi          #+#    #+#              #
#    Updated: 2019/03/07 14:33:15 by ntrusevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

SRC = main.c fractals.c fractals1.c fractals2.c features.c features1.c mouse.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_INC = $(LIBFT_DIR)

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

CC_FLAGS = -Wall -Wextra -Werror -O2
CC = gcc -g
OGL = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OGL) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[0;32m Fractol compiled \033[0m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADERS_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	@echo "\033[0;32m Object files fractol removed \033[0m"

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "\033[0;32m Fractol removed \033[0m"

re: fclean all

.PHONY: all clean fclean re
