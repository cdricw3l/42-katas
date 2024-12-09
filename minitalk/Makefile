CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = srcs/serveur.c srcs/utils/utils_1.c srcs/utils/utils_2.c
CLIENTSRC =	srcs/client.c srcs/utils/utils_1.c srcs/utils/utils_2.c

SERVEURIBJS = ${SERVEURSRC:srcs/*.c=.o}
CLIENTOBJS = ${CLIENTSRC:srcs/*.c=.o}


TXT1= "hello "
TXT2= "World "

all: ${NAME}

s: $(NAME_S)
	./${NAME_S}
	@echo Démarage du serveur $$(pgrep -n serveur)

c: $(NAME_C)
	time ./${NAME_C} $$(pgrep -n serveur) ${TXT1} ${TXT2}
#pgrep -n serveur | xargs kill -9
	@echo Interuption du serveur $$(pgrep -n serveur)

r: k all s
	
$(NAME_S) : $(SERVEURIBJS)
	${CC} ${CFLAGS} ${SERVEURIBJS} -L./lib -lftprintf -lft  -o ${NAME_S}

$(NAME_C) : $(CLIENTOBJS)
	${CC} ${CFLAGS} ${CLIENTOBJS} -L./lib -lftprintf -lft  -o ${NAME_C}

$(NAME) : ${NAME_C} ${NAME_S}

clean: k
	rm -f *.o
	rm -rf *.dSYM
	rm -f ${NAME_C}
	rm -f ${NAME_S}

re: clean all

gdev:
	cd .. && git add . && git commit -m minitalk && git push

move:
	cp -rf * ../../minitalk
	cd ../../ && cd minitalk/
	git add . && git commit -m minitalk && git push

test:
	${CC} ${CFLAGS} test_unit.c utils_1.c -L./lib -lftprintf -lft -o test
	./test

.PHONY: gdev clean all c s k test move
