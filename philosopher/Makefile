CC= gcc
NAME= philo
DATE=$(shell date | sed 's/ /_/g')
GFLAGS= -Werror -Wextra -Wall  
SRCS= $(wildcard srcs/*.c)
OBJS= $(SRCS:*.c=.o)
SRCS_TEST= $(wildcard unit_test/*.c)
OBJS_TEST= $(SRCS_TEST:*.c=.o)
NOP= 5 #number_of_philosophers
TTD= 4000 #time_to_die
TTE= 4000 #time_to_eat
TTS= 4000 #time_to_sleep 

GITCOM=
OS = $(shell uname)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAM E)
	
run:$(OBJS)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME)
	./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
endif

test: $(OBJS_TEST)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS) -fsanitize=address $(OBJS_TEST) -o test_unit 
	./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	$(CC)  $(OBJS_TEST) -o $(NAME)
	valgrind --leak-check=full --log-file=filename  -s ./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
endif

clean:
	rm -f test_unit
	cd srcs && rm -f *.o 

fclean: clean
	rm -f $(NAME)

all: fclean $(NAME)

git: fclean
	cd ..
	git add .
	git commit -m $(NAME)/$(DATE)/$(GITCOM)
	git push origin work

copy:
	cd .. && cd 42-katas/philosopher && rm -rf *
	cp -rf * ../42-katas/philosopher