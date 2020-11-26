NAME = get_next_line

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

CC = clang 

SRCS = get_next_line.c get_next_line_utils.c main.c 

TEST = get_next_line_utils.c test.c main.c 

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

san: ${OBJS}
		${CC} ${CFLAGS} -g -fsanitize=address -fno-omit-frame-pointer ${OBJS} -o ${NAME}

test: ${TEST}
	${CC} ${CFLAGS} ${TEST} -o ${NAME}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


.PHONY:		all clean fclean re
