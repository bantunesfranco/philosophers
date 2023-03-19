CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address #-g
NAME = philo

DIR_I = incs

SRCS = ${shell find srcs -type f -name "*.c"}
INCS = -I ${DIR_I}

${NAME}: ${SRCS} ${DIR_I}/philo.h
	${CC} ${CFLAGS} ${SRCS} ${INCS} -o ${NAME}

all: ${NAME}

clean:
#rm -rf obj

fclean: clean
	rm -rf ${NAME}

re: fclean all

git:
	git commit
	git push