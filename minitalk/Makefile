CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g3
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = srcs/serveur.c srcs/utils/string_utils_1.c srcs/utils/string_utils_2.c srcs/utils/bit_utils.c
CLIENTSRC =	srcs/client.c srcs/utils/string_utils_1.c srcs/utils/string_utils_2.c srcs/utils/bit_utils.c

TXT1 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, "
TXT2 = "HELLO WORLD"

OBJSCLI=${CLIENTSRC:.c=.o}
OBJSSER=${SERVEURSRC:.c=.o}

all: ${NAME} 

#run server
s: $(NAME_S)
	@./${NAME_S}
	@echo Démarage du serveur ${PID}

#run client
c: $(NAME_C)
	time ./${NAME_C} $$(pgrep -n serveur) ${TXT1}
#kill serveur
k:
	@pgrep -n serveur | xargs kill -SIGTERM
	@echo Serveur is runnig.

r: k all s

#Serveur
$(NAME_S) : ${OBJSSER}
	${CC} ${CFLAGS} ${SERVEURSRC} -L./libftprintf -lftprintf -o ${NAME_S}
#Client
$(NAME_C) : ${OBJSCLI}
	${CC} ${CFLAGS} ${CLIENTSRC} -L./libftprintf -lftprintf  -o ${NAME_C}

$(NAME) :  ${NAME_S} ${NAME_C}

lib:
	cd libft && make bonus && make clean

clean: k
	rm -f srcs/*.o && rm -f srcs/utils/*.o
	rm -rf *.dSYM
	rm -f unit_test/test
	
fclean: clean	
	rm -f ${NAME_C}
	rm -f ${NAME_S}

re: fclean all

gdevm:
	cd .. && git add . && git commit -m minitalk && git push origin main

gdevt:
	cd .. && git add . && git commit -m minitalk && git push origin test_unit

move:
	cp -rf * ../../minitalk
	cd ../../ && cd minitalk/
	git add . && git commit -m minitalk && git push

test:
	${CC} ${CFLAGS} unit_test/test_unit.c unit_test/test_utils.c  srcs/utils/string_utils.c srcs/utils/bit_utils.c -L./libftprintf -lftprintf -L./libft -lft -o unit_test/test
	./unit_test/test

.PHONY: gdev clean fclean re all c s k test move libft
