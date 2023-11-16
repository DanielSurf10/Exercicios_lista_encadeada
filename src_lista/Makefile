# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 09:12:36 by danbarbo          #+#    #+#              #
#    Updated: 2023/11/16 09:26:25 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= ../linked_list.a
CC		= cc
FLAGS	= -Wall -Wextra -Werror -c
INCLUDE	= ..
SRC		= ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c
OBJ		= ${SRC:%.c=obj/%.o}

all: ${NAME}
${NAME}: ${OBJ}

obj/%.o: %.c
	$(shell if [ ! -d obj ]; then mkdir -p obj; fi)
	${CC} ${FLAGS} -I ${INCLUDE} $< -o $@
	@ar rcs ${NAME} $@

clean:
	rm -rf obj

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
