CC = gcc 
GFLAGS= -Werror -Wall -Wextra -I./include -g

NAME= so_long
NAME_TEST= so_long_test
#srcs/hook/manage_hook.c \

SRCS =	src/gnl/get_next_line_utils.c \
		src/gnl/get_next_line.c \
		src/hook_managment/hook_manager.c \
		src/error_managment/error_layer.c \
		src/memory_managment/memory_cleaner.c \
		src/initialisation/1_init.c \
		src/initialisation/2_get_map.c \
		src/initialisation/3_check_map.c \
		src/initialisation/4_check_valide_way.c \
		src/image_loader/1_start_img_loader.c \
		src/image_loader/2_path_loader.c \
		src/image_loader/3_image_loader.c \
		src/image_layer/image_layer.c \
		src/utils.c \
#src/main.c \

LIB= -Llib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibft -lft
#srcs/main.c 

SRCS_TEST = unit_test/unit_test.c ${SRCS}
LIB2= -Llibft -lft

MAP=

OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) -fsanitize=address -g $(OBJS) $(LIB) -o $(NAME)


clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_TEST}
	rm  -f filename

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

testv: $(OBJS) $(OBJS_TEST)
	$(CC) $(GFLAGS) $(OBJS_TEST) $(LIB) -o $(NAME_TEST)
	valgrind --leak-check=full  --leak-resolution=high --track-origins=yes --show-leak-kinds=all --log-file=filename --num-callers=500 -s ./$(NAME_TEST) map/map2.ber

test: $(OBJS) $(OBJS_TEST)
	$(CC) $(GFLAGS) -fsanitize=address -g $(OBJS_TEST) $(LIB) -o $(NAME_TEST)

run: $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) $(LIB) -o $(NAME)
	valgrind --leak-check=full  --leak-resolution=high --track-origins=yes --show-leak-kinds=all --log-file=filename --num-callers=500 -s ./so_long map/map1.ber

.PHONY: re all clean fclean so_long copy libft test run $(NAME) $(NAME_TEST)
