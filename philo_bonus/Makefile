# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 20:21:15 by hait-hsa          #+#    #+#              #
#    Updated: 2023/04/09 17:40:44 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_check_argv_bonus.c \
		structs_fill_bonus.c \
		ft_atoi_bonus.c \
		time_hanlder_bonus.c \
		memory_free_bonus.c \
		philo_bonus.c \
		processes_routine_bonus.c \
		has_died_bonus.c \
		check_and_spawn_process_bonus.c \

OBJS = 		${SRC:.c=.o}

NAME =		philo_bonus

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