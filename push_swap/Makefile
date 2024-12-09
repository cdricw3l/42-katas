CC=cc
GFLAGS= -Wall -Werror -Wextra -fsanitize=address -g 
SRCS=$(wildcard srcs/*.c)
OBJS=$(SRCS:.c=.o)
NAME=push_swap
DATE=$(shell date | sed 's/ /_/g')
ARGS=

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -Llib -lft -lftprintf -o $(NAME)

clean:
	cd srcs && rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd test && rm -rf test.dSYM
	cd test && rm -rf test

re: fclean all

gdev:
	git add . && git commit -m $(NAME)/$(DATE) && git push

	
#### test ###
#$(CC) $(GFLAGS) test/$(testunit).c -Llib -lft -lftprintf -o $(testunit) 

test:
	$(CC) $(GFLAGS) test/*.c srcs/push_swap_utils.c -Llib -lft -lftprintf -o test/test
	
check:
	test/checker_Mac42 $(ARGS) 

exam:
	$(CC) $(GFLAGS) test/exercice_exam.c -Llib -lft -lftprintf -o test/exam
	test/exam

.PHONY: re all fclean test