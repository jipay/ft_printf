# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 22:41:52 by jdidier           #+#    #+#              #
#    Updated: 2020/10/17 20:41:06 by jdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME=libftprintf.a

CC=gcc

CFLAGS= -Wall -Wextra -Werror

RM=rm -f

SRCS=ft_memset.c ft_strlen.c ft_isdigit.c  ft_strchr.c ft_strdup.c ft_substr.c \
ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_itoa_base.c \
ft_printf.c ft_printf_parse.c ft_printf_tools.c ft_printf_parse_tools.c \
ft_display_result.c
SRC = $(wildcard *.c)

OBJS=	${SRCS:.c=.o}

BONUS=	${SRCS_BONUS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${BONUS} ${OBJS}
			ar rc ${NAME} ${OBJS} ${BONUS}
			ranlib ${NAME}

clean:
		${RM} ${OBJS} ${BONUS}

fclean: clean
		${RM} ${NAME}

re: fclean all

so :	${OBJS}
		gcc -shared -Wl,-soname,libft.so -o libft.so ${OBJS}

.PHONY: clean fclean re