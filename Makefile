
NAME 			= so_long

SRCS_LIST		=	main.c \
						parsing.c \
						checkmap.c \
						gnl.c \
						ft_itoa.c \
						gnl_utils.c \
						window.c \
						fillwindow.c \
						gameplay.c \
						error.c \
						window_management.c

SRCS_LIST_BONUS	=	main.c \
						parsing.c \
						checkmap.c \
						ft_itoa.c \
						gnl.c \
						../bonus_files/check_xpm_bonus.c \
						../bonus_files/animation_bonus.c \
						../bonus_files/window_init_bonus.c \
						gnl_utils.c \
						window.c \
						error.c \
						fillwindow.c \
						gameplay.c

FOLDER			= srcs

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

SRCS_BONUS		= $(addprefix ${FOLDER}/, ${SRCS_LIST_BONUS})

OBJS			= ${SRCS:.c=.o}

OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

HEADER			= header

OBJDIR			= obj

CC				= gcc

CFLAGS 			= -Wall -Wextra -Werror

RM				= rm -rf

LINK			= ar rc 

MYLIB 			= mylib.a

PATH_MLX_LINUX 	= ./mlx/

MLX_LINUX		= ./mlx/libmlx_Linux.a

all:		${NAME}

%.o: %.c
			${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

$(NAME):	${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o ${NAME}	
			mkdir -p ${OBJDIR} && mv ${OBJS} ${OBJDIR}

clean:
			${RM} ${OBJS} ${OBJS_BONUS} ${OUT} ${OBJDIR}

fclean:		clean
			${RM} ${NAME} ${MYLIB}

bonus:		${OBJS_BONUS}
			${LINK} ${MYLIB} ${OBJS_BONUS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o $(NAME)
			mkdir -p ${OBJDIR} && mv ${OBJS_BONUS} ${OBJDIR}

valgrind:	${NAME}
			valgrind \
			--leak-check=full --tool=memcheck \
			--show-reachable=yes \
			--track-fds=yes \
			--errors-for-leak-kinds=all \
			--show-leak-kinds=all \
			./${NAME} maps/map1.ber

re:			fclean all

rebonus:	fclean bonus

.PHONY: 	all clean fclean re rebonus bonus valgrind

# -g3 -fsanitize=address