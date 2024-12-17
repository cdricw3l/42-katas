CC = gcc 
GFLAGS= -Werror -Wall -Wextra
SRCS = srcs/main.c 
NAME= so_long

OBJS = $(SRCS:.c =.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f ${NAME}

re: clean fclean ${NAME}

gdev: copy
	git add .
	git commit -m ${NAME}
	git push

copy:
	cd .. && cd 42-katas && rm -rf ${NAME}
	cd ..  
	cp -rf ${NAME}  ../42-katas/
	cd 	.. && cd  42-katas &&  git add . && git commit -m ${NAME} && git push 

.PHONY: re all clean fclean so_long copy