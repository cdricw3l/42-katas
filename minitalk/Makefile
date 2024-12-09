CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = serveur.c utils_1.c utils_2.c
CLIENTSRC =	client.c utils_1.c utils_2.c

SERVEURIBJS = ${SERVEURSRC:*.c=.o}
CLIENTOBJS = ${CLIENTSRC:*.c=.o}


TXT1= "hello"
TXT2= "worldd"

PID=
all: ${NAME}

s: $(NAME_S)
	./${NAME_S}
	@echo Démarage du serveur $$(pgrep -n serveur)

c: $(NAME_C)
	time ./${NAME_C} $$(pgrep -n serveur) ${TXT1} ${TXT2} 
k:
	pgrep -n serveur | xargs kill -9
	@echo Interuption du serveur $$(pgrep -n serveur)

r: k all s
	
$(NAME_S) : $(SERVEURIBJS)
	${CC} ${CFLAGS} ${SERVEURIBJS} -o ${NAME_S}

$(NAME_C) : $(CLIENTOBJS)
	${CC} ${CFLAGS} ${CLIENTOBJS} -o ${NAME_C}

$(NAME) : ${NAME_C} ${NAME_S}

clean: k
	rm -f *.o
	rm -rf *.dSYM
	rm -f ${NAME_C}
	rm -f ${NAME_S}

re: clean all

gdev:
	cd .. && git add . && git commit -m minitalk && git push

.PHONY: gdev clean all c s k
