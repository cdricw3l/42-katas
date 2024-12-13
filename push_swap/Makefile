CC=cc
GFLAGS= -Wall -Werror -Wextra -fsanitize=address -g 
LIB= -L./libft -lft -L./libftprintf -lftprintf 
SRCS=$(wildcard srcs/*.c)
OBJS=$(SRCS:.c=.o)
NAME=push_swap
DATE=$(shell date | sed 's/ /_/g')

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) ${LIB} -o $(NAME)

clean:
	rm -rf *.out
	rm -rf *.dSYM
	cd srcs && rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd test && rm -rf test.dSYM
	cd test && rm -rf test

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

copy-swap:
	cd .. && cd 42-katas && rm -rf push_swap
	cd .. && cp -rf push_swap 42-katas
	
#### test ###
#$(CC) $(GFLAGS) test/$(testunit).c -Llib -lft -lftprintf -o $(testunit) 

test:
	$(CC) $(GFLAGS) test/*.c srcs/push_swap_utils.c -Llib -lft -lftprintf -o test/test
	
check:
	test/checker_Mac42 $(ARGS) 

exam:
	$(CC) $(GFLAGS) test/exercice_exam.c -Llib -lft -lftprintf -o test/exam
	test/exam

.PHONY: re all clean fclean test lib exam check test ft_printf ft lib gdev libftupdate