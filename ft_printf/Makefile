CC = cc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs
NAME =  libftprintf.a

LIBFT_PATH = lib/libft.a

LIB_FILE = 	ft_isset.o ft_toupper.o 
LIBFT_F = srcs/ft_isset.o srcs/ft_toupper.o 
SRCS = ${wildcard srcs/*.c}

OBJS = ${SRCS:srcs/%.c=srcs/%.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -xv ${LIBFT_PATH} ${LIB_FILE} && mv  *.o srcs/
	${AR} ${NAME} ${OBJS} ${LIBFT_F}

clean:
	rm -f srcs/*.o && rm -f srcs/*.out

fclean: clean
	rm -f ${NAME}
	rm -f print_test
	rm -f test

re: fclean all


###### LIBFT ####################################################
LIBFT = libft.a
SRCS_LIBFT = ${wildcard ../libft/*c}
CMD = make bonus
LIBC =  make fclean
OBJS_LIBFT = ${SRCS_LIBFT:.c=.o}

lib: ${OBJS_LIBFT}
	rm -f lib/${LIBFT}
	cd ../libft && rm -f ${LIBFT} && ${LIBC} && ${CMD} && cp -f ../libft/${LIBFT} ../printf/lib && ${LIBC}

##################################################################

###### DEV #######################################################

NAME_TEST = test
#
SRCS_DEV =	${wildcard srcs/*.c}
LIBRARY= -L./lib -lft
OBJS_DEV = ${SRCS_DEV:.c=.o}

test: ${OBJS_DEV}
	${CC} ${CFLAGS}	${SRCS_DEV} ${LIBRARY} -o ${NAME_TEST}
	./${NAME_TEST}

t: test

tc: clean fclean
	rm -f ${NAME_TEST}

#################################################################

###### git #####################################################


gdev:
	git add .
	git commit -m ${NAME}
	git push origin master

.phony: all clean fclean re tc t test lib