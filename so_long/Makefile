CC = gcc 
GFLAGS= -Werror -Wall -Wextra

NAME= so_long
NAME_TEST= so_long_test
#srcs/hook/manage_hook.c \

SRCS =	srcs/main.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		srcs/init/* \
		srcs/utils/* \


SRCS_TEST = srcs/so_long_utils.c srcs/check_params/check_params_1.c  gnl/get_next_line_utils.c gnl/get_next_line.c test_unit/test_unit_check_params/*
LIB= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft 
LIB2= -Llibft -lft

MAP=

OBJS = $(SRCS:.c =.o)
OBJS_TEST = $(SRCS_TEST:.c =.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) -fsanitize=address $(OBJS) $(LIB) -o $(NAME)
	./${NAME} ${MAP}

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_TEST}
	rm filename

re: clean fclean ${NAME}

gdev:
	git add .
	git commit -m ${NAME}
	git push

copy:
	cd .. && cd 42-katas && rm -rf ${NAME}
	cd ..  
	cp -rf ${NAME}  ../42-katas/
	cd 	.. && cd  42-katas &&  git add . && git commit -m ${NAME} && git push 


libft:
	rm -rf libft
	cp -rf ../42-katas/libft .

test:
	$(CC) $(GFLAGS) $(OBJS_TEST) $(LIB) -o $(NAME_TEST)

launch:
	$(CC) $(GFLAGS) $(OBJS) $(LIB) -o $(NAME)
	valgrind --leak-check=full  --leak-resolution=high --track-origins=yes --show-leak-kinds=all --log-file=filename --num-callers=500 -s ./so_long map/map2.ber

.PHONY: re all clean fclean so_long copy libft test
