# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojeong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 22:28:17 by seojeong          #+#    #+#              #
#    Updated: 2020/08/12 17:16:42 by seojeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECT	= ${SRCS:.c=.o}
OBJECT_B = $(SRCS_B:.c=.o)
GCC		= gcc
FLAG	= -Wall -Wextra -Werror
OPTION	= -c
INCS	= .

all: ${NAME}

$(NAME): ${OBJECT}
	ar rc $(NAME) $(OBJECT)

bonus: $(NAME) $(OBJECT_B)
	ar rc $(NAME) $(OBJECT_B)

.c.o:
	${GCC} ${FLAG} ${OPTION} $< -o ${<:.c=.o} -I ${INCS}

clean:
	rm -f $(OBJECT) $(OBJECT_B)

fclean: clean
	rm -f $(NAME) $(bonus)

re: fclean all

.PHONY: all bonus clean fclean re .c.o
