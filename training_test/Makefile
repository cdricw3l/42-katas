CC=gcc
GFLAGS= -Werror -Wall -Wextra  
SRCS= $(wildcard *.c)
OBJS= $(SRCS: *.c=.o)
NAME= filter

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)

run:
	valgrind --leak-check=full  --log-file="filename.txt" ./$(NAME) test

clean:
	rm -f *.o 

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)