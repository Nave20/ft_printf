NAME = libft.a

SOURCES =	\
	printf.c	\
	printf.h

BONUS =	\

OBJS	=	${SOURCES:.c=.o}

B_OBJS	=	${BONUS:.c=.o}

HEADER	=	libft.h

LIB = libft.a

NAME	=	libftprintf.a

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

%.o	:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${LIB} ${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

${LIB} :
	make -C libft/

bonus	:
	@make SRCS="${SRCS} ${BNS}"

clean	:
	rm -f ${OBJS} ${B_OBJS}
	make clean -C libft/

fclean	:	clean
	rm -f ${NAME} ${B_OBJS}
	make fclean -C libft/

re	:	fclean all

.PHONY	:	all clean fclean re bonus