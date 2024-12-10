CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = srcs/serveur.c srcs/utils/string_utils.c srcs/utils/bit_utils.c
CLIENTSRC =	srcs/client.c srcs/utils/string_utils.c srcs/utils/bit_utils.c



TXT1 = "HELLO"
TXT2 = "WORLD"
TXT3 = "Connard"


all: ${NAME_S} ${NAME_C}

#run server
s: $(NAME_S)
	@./${NAME_S}
	@echo Démarage du serveur ${PID}

#run client
c: $(NAME_C)
	time ./${NAME_C} $$(pgrep -n serveur) ${TXT1} ${TXT2} ${TXT3}
#kill serveur
k:
	@pgrep -n serveur | xargs kill -SIGTERM
	@echo Serveur is runnig.

r: k all s
#Serveur
$(NAME_S) : 
	@${CC} ${CFLAGS} ${SERVEURSRC} -L./libftprintf -lftprintf -L./libft -lft  -o ${NAME_S}
#Client
$(NAME_C) : 
	${CC} ${CFLAGS} ${CLIENTSRC} -L./libftprintf -lftprintf -L./libft -lft  -o ${NAME_C}

$(NAME) : ${NAME_C} ${NAME_S}


clean: k
	rm -f *.o
	rm -rf *.dSYM
	rm -f unit_test/test
	
fclean: clean	
	rm -f ${NAME_C}
	rm -f ${NAME_S}

re: fclean all

gdev:
	cd .. && git add . && git commit -m minitalk && git push

move:
	cp -rf * ../../minitalk
	cd ../../ && cd minitalk/
	git add . && git commit -m minitalk && git push

test:
	${CC} ${CFLAGS} unit_test/test_unit.c unit_test/test_utils.c  srcs/utils/string_utils.c srcs/utils/bit_utils.c -L./libftprintf -lftprintf -L./libft -lft -o unit_test/test
	./unit_test/test

.PHONY: gdev clean all c s k test move
