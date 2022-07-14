# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:35:19 by amateo-r          #+#    #+#              #
#    Updated: 2021/11/08 14:35:21 by amateo-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://harm-smits.github.io/42docs/libs/minilibx/introduction.html

#	SOURCES
SRC			=	./src/scripts/exceptions_manager.c \
				./src/scripts/sl_utils_00.c \
				./src/scripts/map.c \
				./src/scripts/key_manager.c \
				./src/scripts/player.c \
				./src/scripts/main.c

SRC_BONUS	=	

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

#	LIBS

LIBFT		=	$(LIBFT_PATH)/libft.a
LIBFT_PATH	=	./include/libft

GNL			=	$(GNL_PATH)/gnl.a
GNL_PATH	=	./include/get_next_line

PRINTF		= $(PRINTF_PATH)/libftprintf.a
PRINTF_PATH	= ./include/ft_printf

MLX			=	$(MLX_PATH)/libmlx.a
MLX_PATH	=	./include/mlx

#	COMPILER
NAME		=	so_long.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
RM			=	rm -f
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

all:		makelib makegnl makeprintf makemlx $(NAME)

bonus:		

%.o%.c: $(LIBFT) $(MLX) $(GNL)
	$(CC) $(CFLAGS) $<	-o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(MLX) $(LIBFT) $(GNL) $(PRINTF) -o	$(NAME)

makelib:
			@make -C $(LIBFT_PATH)
makemlx:
			@make -C $(MLX_PATH)
makegnl:
			@make -C $(GNL_PATH)
makeprintf:
			@make -C $(PRINTF_PATH)
norme:
			@echo "---- SRC ----"
			norminette ./src
			@echo "---- INCLUDE ----"
			norminette ./include/libft

clean:
			@make -C $(LIBFT_PATH) clean
			@make -C $(MLX_PATH) clean
			@make -C $(GNL_PATH) clean
			@make -C $(PRINTF_PATH) clean
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean:		clean
			$(RM) $(NAME) $(LIBFT) $(GNL) $(PRINTF)

re:			fclean all

.PHONY:	clean
