SRCS		= $(wildcard ./srcs/*.c ./srcs/*/*.c)

OBJS		= ${SRCS:.c=.o}

NAME		= cub3D

MLX_PATH	= ./mlx_linux/
MLX_NAME	= $(MLX_PATH)libmlx_Linux.a

INC		= ./inc/

CC		= gcc -Wall -Werror -Wextra -g
RM		= rm -f

CFLAGS		= -lm -lmlx -lXext -lX11

all:		${NAME}

.c.o:	
		${CC} -I${INC} -I${MLX_PATH} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		make -C ${MLX_PATH}
		${CC} ${OBJS} ${MLX_NAME} -L${MLX_PATH} -I${INC} -I${MLX_PATH} ${CFLAGS} -o${NAME}

clean:	
		make clean -C ${MLX_PATH}
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
