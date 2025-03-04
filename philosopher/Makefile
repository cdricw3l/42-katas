CC= gcc
NAME= philo
DATE=$(shell date | sed 's/ /_/g')
GFLAGS= -Werror -Wextra -Wall -g 
SRCS= $(wildcard srcs/*.c)
OBJS= $(SRCS:*.c=.o)
SRCS_TEST= $(wildcard unit_test/*.c)
OBJS_TEST= $(SRCS_TEST:*.c=.o)
NOP= 5 #number_of_philosophers
TTD= 4000 #time_to_die
TTE= 4000 #time_to_eat
TTS= 4000 #time_to_sleep 

GITCOM=

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)

v:$(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)

test: $(OBJS_TEST)
	$(CC) $(GFLAGS)  $(OBJS_TEST) -o test_unit 
	valgrind --leak-check=full --log-file=filename  -s ./test_unit
	./test_unit $(NOP) $(TTD) $(TTE) $(TTS)

clean:
	rm -f test_unit
	cd srcs && rm -f *.o 

fclean: clean
	rm -f $(NAME)

all: fclean $(NAME)

git: fclean
	git add .
	git commit -m $(NAME)/$(DATE)/$(GITCOM)
	git push origin work

copy:
	cd .. && cd 42-katas/philosopher && rm -rf *
	cp -rf * ../42-katas/philosopher