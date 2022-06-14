SRC			=	ft_strlen.c \
				ft_strncmp.c \
				ft_strffnotof.c

OBJ			=	${SRC:.c=.o}

NAME		=	libft.a

CC			=	gcc -c

AR			=	ar rc

RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} $<	-o ${<:.c=.o}

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
