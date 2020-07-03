# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojeong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 22:28:17 by seojeong          #+#    #+#              #
#    Updated: 2020/07/03 22:50:06 by seoyoungj        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c
OBJECT	= ${SRCS:.c=.o}
GCC		= gcc
FLAG	= -Wall -Wextra -Werror
OPTION	= -c
HEADER  = includes

all: $(NAME)

$(NAME): ${OBJECT}
	ar rc $(NAME) $(OBJECT)

.c.o:
	${GCC} ${FLAG} ${OPTION} -I ${HEADER} $< -o $@

clean:
	rm -f ${OBJECT}

fclean: clean
	rm -f ${NAME}

re: fclean all
