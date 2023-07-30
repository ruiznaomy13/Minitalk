# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 19:16:59 by ncastell          #+#    #+#              #
#    Updated: 2023/07/29 23:21:38 by ncastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER 	= inc/ft_printf.h
MKFL	= Makefile
NAME 	= libftprintf.a

OBJ_DIR	= obj/

SRC 	= src/ft_printf.c src/ft_put_char.c src/ft_put_str.c \
		src/ft_put_nums.c src/ft_put_hex.c src/ft_put_pointer.c

RM 		= rm -rf
MP		= mkdir -p

CFLAGS 	= -Werror -Wall -Wextra -W -O3 -Ofast 

LIBC 	= ar -rcs

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP	= $(addsuffix .d, $(basename $(OBJ)))

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} ${CFLAGS} -MMD -I ./ -c $< -o $@

all:
	@$(MAKE) $(NAME)

-include ${DEP}
$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ) $(OBJ_DIR)

fclean:
	@$(MAKE) clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
