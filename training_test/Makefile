CC=gcc
GFLAGS= -Werror -Wall -Wextra -fsanitize=address 
SRCS= $(wildcard *.c)
OBJS= $(SRCS: *.c=.o)
NAME= filter

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)
	

clean:
	rm -f *.o 

fclean: clean
	rm -f $(NAME)
