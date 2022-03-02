SRCS	=	./algorithms/ft_algorithm.c ./algorithms/ft_five_less.c ./algorithms/ft_hundred.c \
			./algorithms/ft_radix.c ./algorithms/ft_three_less.c \
			./moves/ft_px.c ./moves/ft_rrx.c ./moves/ft_rx.c ./moves/ft_sx.c \
			ft_error.c ./outils/ft_outils1.c ./outils/ft_outils2.c \
			ft_stack_a.c ft_stack_b.c main.c

NAME	=	push_swap

DIRLIBFT =  ./ft_libft/libft.a

MAKELIBFT = cd ./ft_libft/ && ${MAKE}

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${MAKELIBFT}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${DIRLIBFT}

clean:
			${RM} ${OBJS}
			${MAKELIBFT} clean

fclean:		clean
			${RM} ${NAME}
			${MAKELIBFT} fclean

re:			fclean ${NAME}

.PHONY:		all clean fclean re
