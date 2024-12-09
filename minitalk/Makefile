CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = srcs/serveur.c srcs/utils/utils_1.c srcs/utils/utils_2.c
CLIENTSRC =	srcs/client.c srcs/utils/utils_1.c srcs/utils/utils_2.c

SERVEURIBJS = ${SERVEURSRC:srcs/*.c=.o}
CLIENTOBJS = ${CLIENTSRC:srcs/*.c=.o}


TXT1="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."

all: ${NAME}

s: $(NAME_S)
	./${NAME_S}
	@echo Démarage du serveur $$(pgrep -n serveur)

c: $(NAME_C)
	time ./${NAME_C} $$(pgrep -n serveur) ${TXT1}
	
k:
	pgrep -n serveur | xargs kill -9
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
