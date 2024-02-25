NAME = Webserver
CC = c++
CC += -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
EXTRA_CFLAGS = -std=c++98

SRC = main.cpp \
	  srcs/server.cpp \
	  srcs/webserver.cpp \
	  srcs/client.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}
# all :
# 	c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 srcs/server.cpp srcs/webserver.cpp main.cpp  -o server
# 	c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98  srcs/client.cpp  -o client

%.o : %.cpp
	c++ ${CFLAGS} ${EXTRA_CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	${CC}  ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}
	rm -rf client server

fclean : clean
	rm -rf ${NAME}

re : fclean all

push : 
	git add .
	git commit -m "webserver"
	git push