SOURCES =	\
	ft_printf.c

OBJS	=	${SOURCES:.c=.o}

HEADER	=	ft_printf.h

LIB = libft/libft.a

NAME	=	libftprintf.a

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

%.o	:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} Makefile FORCE
	make bonus -C libft/
	cp libft/libft.a ${NAME}
	ar -rcs ${NAME} ${OBJS}

FORCE:

clean	:
	rm -f ${OBJS}
	make clean -C libft/

fclean	:	clean
	rm -f ${NAME}
	make fclean -C libft/

re	:	fclean all

.PHONY	:	all clean fclean re bonus FORCE