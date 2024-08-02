# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 11:04:20 by ade-fran          #+#    #+#              #
#    Updated: 2024/03/31 11:04:23 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

CFLAGS			=	-Wall -Wextra -Werror -I ${INCLD_DIR} -pthread -g

CC				=	cc

COLOUR_GREEN	=	\033[0;32m

YELLOW			=	\033[0;33m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SOURCES_PATH	=	src/

SOURCES_MAIN	= 	main.c \

SOURCES_INIT 	=	init/init_data.c \
					init/init_philos.c \

SOURCES_PHILO	=	philo_routine/philo_main.c \
					philo_routine/eat.c \
					philo_routine/sleep.c \
					philo_routine/think.c \
					philo_routine/check_end.c \
					philo_routine/death.c \
					philo_routine/end.c \

SOURCES_TIME	=	time_func/time_func.c \

SOURCES_ERRORS	=	errors/errors.c \

SOURCES_UTILS	=	utils/utils.c	\


# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJECTS_PATH	=	objs/

OBJECTS			=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_MAIN:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_INIT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_PHILO:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_TIME:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_ERRORS:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_UTILS:.c=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./inc/

INCLD			=	${INCLD_DIR}philo.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  ${NAME}

${NAME}: ${OBJECTS} ${INCLD}
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}
	@echo "${COLOUR_GREEN}\33[2K\nPhilo compiled\n${COLOUR_END}"

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@ && printf "\33[2K\r${YELLOW}Compiling philo :${COLOUR_END} $@"

clean:
	@rm -rf ${OBJECTS_PATH}

fclean:
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME}
	@echo "${COLOUR_GREEN}Philo cleaned\n${COLOUR_END}"

re: fclean all

.PHONY: fclean clean all re
