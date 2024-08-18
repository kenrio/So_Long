# **************************************** #
# VARIABLES


NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror


# **************************************** #
# SOURCES


SRC_FILES			= ${addprefix src/, \
					main \
					utils \
					map_init \
					map_init_utils \
					allocate \
					free \
					exit \
					game_init \
					game_events \
					game_events_utils \
					draw }

PRINTF_SRC_FILES	= ${addprefix ft_printf/, \
					ft_printf \
					ft_printf_putchar \
					ft_printf_puthex \
					ft_printf_putptr \
					ft_printf_putstr \
					ft_printf_putuint }

GNL_SRC_FILES		= ${addprefix gnl/, \
					get_next_line \
					get_next_line_utils }

OBJ_FILES			= ${addsuffix .o, ${SRC_FILES}}
PRINTF_OBJ_FILES	= ${addsuffix .o, ${PRINTF_SRC_FILES}}
GNL_OBJ_FILES		= ${addsuffix .o, ${GNL_SRC_FILES}}


# **************************************** #
# LIBRARIES & FRAMEWORKS


MLX_PATH	= minilibx/

LFLAGS		= -Lminilibx -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd


# **************************************** #
# RULES


all: ${NAME}

${NAME}: ${OBJ_FILES} ${PRINTF_OBJ_FILES} ${GNL_OBJ_FILES}
	make -C ${MLX_PATH}
	${CC} ${CFLAGS} $^ ${LFLAGS} -o ${NAME}

debug: ${OBJ_FILES} ${PRINTF_OBJ_FILES} ${GNL_OBJ_FILES}
	make -C ${MLX_PATH}
	${CC} -g ${CFLAGS} $^ ${LFLAGS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Iminilibx -Iincludes -c $< -o $@

clean:
	rm -f ${OBJ_FILES} ${PRINTF_OBJ_FILES} ${GNL_OBJ_FILES}
	make -C ${MLX_PATH} clean

fclean: clean
	rm -f ${NAME}

re: fclean all


# **************************************** #
# PHONY


.PHONY: all clean fclean re

