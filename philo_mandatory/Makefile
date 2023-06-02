# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 20:21:15 by hait-hsa          #+#    #+#              #
#    Updated: 2023/04/09 17:39:49 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_check_argv.c \
		structs_fill.c \
		threads_routine.c \
		time_hanlder.c \
		ft_atoi.c \
		memory_free.c \
		main_thread.c \
		philo.c \

OBJS = 		${SRC:.c=.o}

NAME =		philo

CFLAGS =	-Wall -Wextra -Werror -pthread

CC =		cc

RM =		rm -rf

all : ${NAME}

${NAME} : ${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
			${RM} ${OBJS}

fclean : clean
			${RM} ${NAME}
re : fclean all

.PHONY:		all re clean fclean