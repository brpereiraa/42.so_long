# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 09:44:26 by brunolopes        #+#    #+#              #
#    Updated: 2023/12/07 10:22:04 by brpereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
RM = rm -fr

SRCS = src/main.c src/map.c src/checker.c src/key_handler.c src/sprites.c src/clean_exit.c

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
		${MAKE} --no-print-directory -C ./libft
		cp libft/libft.a .
		${MAKE} --no-print-directory -C ./mlx
		${CC} ${OBJS} libft.a ${MLXFLAGS} -o ${NAME} 

clean:
	${MAKE} --no-print-directory clean -C ./libft
	rm -fr ${OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ./libft
		rm -fr libft.a
		rm -fr ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clear fclean re

.SILENT: