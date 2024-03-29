RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = gcc
NAME = philo

DIR_S = srcs
DIR_I = incs
DIR_O = obj

ifndef DEBUG
	CFLAGS = -Wall -Werror -Wextra -pthread -Ofast
else
	CFLAGS = -Wall -Werror -Wextra -pthread -Ofast -g -fsanitize=leak
endif

INCS = -I $(DIR_I)

SRCS = eat.c actions.c forks.c main.c philos.c routine.c threads.c time.c utils.c

OBJS =  ${SRCS:%.c=${DIR_O}/%.o}

all: ${NAME}

${NAME}: ${OBJS} ${DIR_I}/${NAME}.h
	@echo "${BLUE}Compiling ${NAME}${END}"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} 
	@echo "${GREEN}Done!${END}"

${OBJS}: ${DIR_O}/%.o: ${DIR_S}/%.c
	@mkdir -p ${DIR_O}
	@echo "${BLUE}Compiling $<${END}"
	@${CC} ${CFLAGS} ${INCS} -c $< -o $@

bonus: ${NAME}

clean:
	@echo "${RED}Removing objs${END}"
	@rm -rf obj
	@echo "${GREEN}Done!${END}"

fclean: clean
	@echo "${RED}Removing ${NAME}${END}"
	@rm -rf ${NAME}
	@echo "${GREEN}Done!${END}"

re: fclean all

debug: fclean
	@$(MAKE) DEBUG=1 all

.PHONY: all clean fclean re bonus debug