# **************************************** #
# VARIABLES


NAME		= a.out

CC			= cc
CFLAGS		= -Wall -Wextra -Werror


# **************************************** #
# SOURCES


SRC_FILES	= so_long
OBJ_FILES	= ${addsuffix .o, ${SRC_FILES}}


# **************************************** #
# LIBRARIES & FRAMEWORKS


LFLAGS		= -L./minilibx -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd


# **************************************** #
# RULES


all: ${NAME}

${NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LFLAGS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all


# **************************************** #
# PHONY


.PHONY: all clean fclean re

