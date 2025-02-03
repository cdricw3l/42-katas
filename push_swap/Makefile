CC= gcc
GFLAGS= -Wall -Werror -Wextra
LIB= -Llibft -lft -Llibftprintf -lftprintf 
SRCS=$(wildcard srcs/*.c)
OBJS=$(SRCS:.c=.o)
NAME=push_swap
DATE=$(shell date | sed 's/ /_/g')

all: $(NAME)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cd libft && make bonus
	cd ..
	$(CC) $(GFLAGS) $(OBJS) ${LIB} -o $(NAME)

clean:
	rm -rf *.out
	rm -rf *.dSYM
	cd srcs && rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

gdev:
	cd .. && git add .
	git commit -m $(NAME)/$(DATE) 
	git push

lib:
	cd libft && rm -f libft.a  && make bonus && make clean
	cd libftprintf && rm -f libftprintf.a && make

libft-update:
	rm -rf libft
	cp -r ../libft .
	cd libft && make bonus && make clean
	
test:
	$(CC) $(GFLAGS) test/*.c srcs/* ${LIB}  -o test/test
	
check:
	test/checker_Mac42 $(ARGS) 

exam:
	$(CC) $(GFLAGS) test/exercice_exam.c -Llib -lft -lftprintf -o test/exam
	test/exam

.PHONY: re all clean fclean test lib exam check test ft_printf ft lib gdev libftupdate