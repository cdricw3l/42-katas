NAME= so_long
NAME_BONUS= so_long_bonus


CC = gcc

GFLAGS= -Werror -Wall -Wextra -I./include/ -g
GFLAGS_BONUS= -Werror -Wall -Wextra -I./include/bonus -g

COM=

SRCS =	src/gnl/get_next_line_utils.c \
		src/gnl/get_next_line.c \
		src/hook_managment/hook_manager.c \
		src/exit_managment/error_layer.c \
		src/exit_managment/memory_cleaner.c \
		src/initialisation/1_init.c \
		src/initialisation/2_get_map.c \
		src/initialisation/3_check_map.c \
		src/initialisation/4_check_valide_way.c \
		src/image_loader/1_start_img_loader.c \
		src/image_loader/2_path_loader.c \
		src/image_loader/3_image_loader.c \
		src/image_layer/image_layer.c \
		src/utils/display_utils.c \
		src/utils/xy_utils.c \
		src/main.c \

SRCS_BONUS= src_bonus/gnl/get_next_line_utils_bonus.c \
			src_bonus/gnl/get_next_line_bonus.c \
			src_bonus/hook_managment/hook_manager_bonus.c \
			src_bonus/hook_managment/fight.c \
			src_bonus/hook_managment/counter.c \
			src_bonus/hook_managment/push_obj.c \
			src_bonus/exit_managment/error_layer_bonus.c \
			src_bonus/exit_managment/memory_cleaner_bonus.c \
			src_bonus/initialisation/1_init_bonus.c \
			src_bonus/initialisation/2_get_map_bonus.c \
			src_bonus/initialisation/3_check_map_bonus.c \
			src_bonus/initialisation/4_check_valide_way_bonus.c \
			src_bonus/image_loader/1_start_img_loader_bonus.c \
			src_bonus/image_loader/2_path_loader_bonus.c \
			src_bonus/image_loader/3_image_loader_bonus.c \
			src_bonus/image_layer/image_layer_bonus.c \
			src_bonus/image_layer/frame_layer.c \
			src_bonus/image_layer/static_image_monster_layer.c \
			src_bonus/utils/display_utils_bonus.c \
			src_bonus/utils/xy_utils_bonus.c \
			src_bonus/utils/utils_bonus.c \
			src_bonus/main_bonus.c \

LIB= -Llib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibft -lft -Llib/printf -lftprintf

SRCS_TEST =  ${SRCS}

OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cd lib/mlx_linux && ./configure && cd ..
	@cd libft && make bonus && cd ..
	@$(CC) $(GFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus: $(OBJS_BONUS)
	@cd lib/mlx_linux && ./configure && cd ..
	@cd libft && make bonus && cd ..
	$(CC) $(GFLAGS_BONUS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)

bonusv: $(OBJS_BONUS)
	$(CC) $(GFLAGS_BONUS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)
	valgrind --leak-check=full --log-file=filename ./$(NAME_BONUS) map/bonus_map/map2_bonus.ber

test: $(OBJS)
	$(CC) $(GFLAGS) -fsanitize=address  $(OBJS) $(LIB) -o $(NAME_TEST)
t: 
	$(CC) $(GFLAGS)   src_bonus/test.c $(LIB) -o $(NAME_TEST)

testv: $(OBJS) 
	$(CC) $(GFLAGS)  $(OBJS) $(LIB) -o $(NAME_TEST)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME_TEST) map/standard_map/map3.ber

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f ${NAME}
	rm  -f filename

re: clean fclean ${NAME}

gdev:
	git add .
	git commit -m ${COM}
	git push

.PHONY: re all clean fclean so_long copy libft test run $(NAME) $(NAME_TEST)
