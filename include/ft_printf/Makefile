SRC			=	./ft_printf.c \
				./ft_eval.c \
				./flag_handlers.c \
				./ft_writers.c \
				./ft_writer_d.c \
				./ch_handler.c \
				./ft_writer_c.c \
				./ft_writer_per.c \
				./ft_writer_p.c \
				./ft_writer_x.c \
				./ft_writer_u.c

SRC_BONUS	=	

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

LIBFT		=	$(LIBFT_PATH)/libft.a
LIBFT_PATH	=	../libft

NAME		=	libftprintf.a

CC			=	gcc -c

AR			=	ar rc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

%.o%.c: $(LIBFT)
			$(CC) $(CFLAGS) $<	-o $@

all:		$(NAME)

bonus:		

$(NAME):	$(OBJ)
			cp $(LIBFT) $(NAME)
			ar rc $(NAME) $(OBJ)

norme:
			@echo "---- INCLUDE ----"
			norminette ./include
			@echo "---- SRC ----"
			norminette ./src
			@echo "---- LIBFT ----"
			norminette ./libft

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re m clean
