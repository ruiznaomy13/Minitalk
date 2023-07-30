# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:27:04 by ncastell          #+#    #+#              #
#    Updated: 2023/07/30 01:24:12 by ncastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER     = server
NAME_CLIENT     = client

SRCS_SERVER     = server.c
SRCS_CLIENT     = client.c

INCLUDE = -I./ -I needs/printf
OBJ_DIR = obj
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

RUTAS   = needs/printf/libftprintf.a

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

${OBJ_DIR}/%.o : %.c Makefile
	@mkdir -p ${OBJ_DIR}
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${addprefix ${OBJ_DIR}/, ${SRCS_SERVER:.c=.o}}
	@${MAKE} -sC needs/printf
	@${CC} ${CFLAGS} $^ ${RUTAS} -o $@
	
${NAME_CLIENT}: ${addprefix ${OBJ_DIR}/, ${SRCS_CLIENT:.c=.o}}
	@${MAKE} -sC needs/printf
	@${CC} ${CFLAGS} $^ ${RUTAS} -o $@
	@echo "$(GREEN)Todo ha sido compilado \n$(NC)"

clean:
	@${MAKE} -s clean -C needs/printf
	@rm -rf ${OBJ_DIR}
	@echo "$(RED)Se ha limpiado correctamente\n$(NC)"
	
fclean: clean
	@${MAKE} -s fclean -C needs/printf
	@rm -f ${NAME_SERVER}
	@rm -f ${NAME_CLIENT}
	
re: fclean all

.PHONY: all clean fclean re
