NAME = get_next_line

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

CC = gcc 

SRCS = get_next_line.c get_next_line_utils.c main.c 
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c 

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus: ${BONUS_OBJS}
		${CC} ${CFLAGS} ${BONUS_OBJS} -o ${NAME}
	
san: ${OBJS}
		${CC} ${CFLAGS} -g -fsanitize=address -fno-omit-frame-pointer ${OBJS} -o ${NAME}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


.PHONY:		all clean fclean re
