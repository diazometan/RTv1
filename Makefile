# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgyles <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 10:25:27 by rgyles            #+#    #+#              #
#    Updated: 2019/02/20 11:48:53 by rgyles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC_FOLDER = sources/

LIBFT_FOLDER = libft

LIBFT = $(LIBFT_FOLDER)/libft.a

MLX_FOLDER = minilibx_macos

MLX = $(MLX_FOLDER)/libmlx.a

FLAGS = -Wall -Wextra #-Werror

SRC = main.c\
	  create_img.c\
	  key_press.c

OBJ = $(addprefix $(SRC_FOLDER), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) -framework OpenGL -framework Appkit

$(MLX):
	make -C $(MLX_FOLDER)

$(LIBFT):
	make -C $(LIBFT_FOLDER)

.c.o:
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT_FOLDER) clean
	make -C $(MLX_FOLDER) clean

fclean:
	/bin/rm $(NAME)
	make -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all clean fclean re
