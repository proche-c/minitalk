
SRCS_1	= client.c utils.c

SRCS_2	= server.c utils.c

OBJS_1	= ${SRCS_1:.c=.o}

OBJS_2	= ${SRCS_2:.c=.o}

CFLAGS	=  -Wall -Werror -Wextra

NAME_1	= client

NAME_2	= server

RM		= rm -f

GC		= gcc

FLAGS	= -Wall -Wextra -Werror -I${PATH}

LIBFT	= libft/libft.a

PATH	= /libft


all:		${NAME_1} ${NAME_2}

${NAME_1}:	${OBJS_1}
			${GC} ${FLAGS} ${OBJS_1}  -o ${NAME_1}

${NAME_2}:	${OBJS_2}
			${GC} ${FLAGS} ${OBJS_2} -o ${NAME_2}


clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME_1} ${NAME_2}

re:			fclean all



