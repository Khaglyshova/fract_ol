# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mroland- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 20:29:12 by mroland-          #+#    #+#              #
#    Updated: 2019/05/30 20:29:25 by mroland-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c \
	mandelbrot.c \
	threads.c \
	motion.c \
	julia.c \
	colors.c \
	spider.c \
	burningship.c \

FLAGS = -Wall -Wextra -Werror

INCLUDES = fract_ol.h

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft
	make -C ./libft/ clean
	gcc $(FLAGS) $(SRCS) -I $(INCLUDES) ./libft/libft.a -L minilibx/ -O3 -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all