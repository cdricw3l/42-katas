CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = srcs/serveur.c srcs/utils/utils_1.c srcs/utils/utils_2.c
CLIENTSRC =	srcs/client.c srcs/utils/utils_1.c srcs/utils/utils_2.c

SERVEURIBJS = ${SERVEURSRC:srcs/*.c=.o}
CLIENTOBJS = ${CLIENTSRC:srcs/*.c=.o}


TXT1="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, "
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
