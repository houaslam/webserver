NAME = Webserver
CXX = c++
CXX += -fsanitize=address -g3
CXXFLAGS = -Wall -Wextra -Werror
EXTRA_CFLAGS = -std=c++98

SRC = srcs/main.cpp \
	  srcs/server.cpp \
	  srcs/webserver.cpp \
	  srcs/client.cpp \
	  srcs/outils.cpp \
	  srcs/response.cpp \
	  srcs/request.cpp

CNF += confFile/parse.cpp \
		confFile/confUtils.cpp \
		confFile/serverParse.cpp \
		srcs/configSrcs/config.cpp \
		srcs/configSrcs/servers.cpp \
		srcs/configSrcs/locations.cpp \

OBJ = ${SRC:.cpp=.o} ${CNF:.cpp=.o}

all : ${NAME}

# all :
# 	c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 srcs/server.cpp srcs/webserver.cpp main.cpp  -o server
# 	c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98  srcs/client.cpp  -o client

%.o : %.cpp %.hpp 
	c++ ${CXXFLAGS} ${EXTRA_CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	${CXX}  ${OBJ} -o ${NAME}

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