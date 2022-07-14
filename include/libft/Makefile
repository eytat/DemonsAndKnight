SRC			=	ft_strlen.c \
				ft_strncmp.c \
				ft_strffnotof.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_digits.c \
				ft_digits_base.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_calloc.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_substr.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_memset.c \
				ft_putnbr_base.c \
				ft_uitoa.c

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
