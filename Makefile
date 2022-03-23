
SRCS_1	= client.c

SRCS_2	= server.c

SRCS_1B= client_bonus.c

SRCS_2B	= server_bonus.c

OBJS_1	= ${SRCS_1:.c=.o}

OBJS_2	= ${SRCS_2:.c=.o}

OBJS_1B	= ${SRCS_1B:.c=.o}

OBJS_2B	= ${SRCS_2B:.c=.o}

CFLAGS	=  -Wall -Werror -Wextra

NAME_1	= client

NAME_2	= server

NAME_1B	= client_bonus

NAME_2B	= server_bonus

RM		= rm -f

GC		= gcc

FLAGS	= -Wall -Wextra -Werror


all:		${NAME_1} ${NAME_2}

${NAME_1}:	${OBJS_1}
			${GC} ${FLAGS} ${OBJS_1}  -o ${NAME_1}

${NAME_2}:	${OBJS_2}
			${GC} ${FLAGS} ${OBJS_2} -o ${NAME_2}

bonus:		${NAME_1B} ${NAME_2B}

${NAME_1B}:	${OBJS_1B}
			${GC} ${FLAGS} ${OBJS_1B}  -o ${NAME_1B}

${NAME_2B}:	${OBJS_2B}
			${GC} ${FLAGS} ${OBJS_2B}  -o ${NAME_2B}


clean:	
			${RM} ${OBJS_1} ${OBJS_2} ${OBJS_1B} ${OBJS_2B}

fclean:		clean
			${RM} ${NAME_1} ${NAME_2} ${NAME_1B} ${NAME_2B}

re:			fclean all



