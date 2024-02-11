NAME = Webserver
CC = c++
CC += -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
EXTRA_CFLAGS = -std=c++98

SRC = main.cpp 

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	c++ ${CFLAGS} ${EXTRA_CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	${CC}  ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

push : 
	git add .
	git commit -m "webserver"
	git push