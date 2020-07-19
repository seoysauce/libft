# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojeong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 22:28:17 by seojeong          #+#    #+#              #
#    Updated: 2020/07/19 16:16:13 by seojeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c

# SRCS_B =
OBJECT	= ${SRCS:.c=.o}
# OBJECT_B = $(SRCS_B:.c=.o)
GCC		= gcc
FLAG	= -Wall -Wextra -Werror
OPTION	= -c

all: ${NAME}

$(NAME): ${OBJECT} libft.h
	ar rc $(NAME) $(OBJECT) libft.h

# bonus: $(OBJECT_B) $(OBJECT) libft.h
	ar rc $(NAME) $(OBJECT_B) $(OBJECT) libft.h

.c.o:
	${GCC} ${FLAG} ${OPTION} $< -o $@

clean:
	rm -f ${OBJECT} $(OBJECT_B)

fclean: clean
	rm -f ${NAME}

re: fclean all
