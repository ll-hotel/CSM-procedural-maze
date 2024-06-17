CXX = g++

SRC_DIR = src/
INC_DIR = include/
OBJ_DIR = .obj/

CXXFLAGS = -Wall -Wextra -Werror
IFLAGS = -I${INC_DIR} -I${SDL_DIR}include/
DFLAGS = -MMD -MP
LFLAGS = -lSDL2

ifneq ("${DEBUG}", "")
	CFLAGS += ${DEBUG}
endif

OBJS = $(patsubst %.cpp,${OBJ_DIR}%.o,\
	   app.cpp \
	   main.cpp \
	   )
DEPS = $(OBJS:.o=.d)

NAME = maze

.SILENT: all
.PHONY: all
all:
	echo 'Choose your OS:'
	echo ' - windows'
	echo ' - linux'

-include ${DEPS}

.PHONY: windows
windows: ${NAME}.exe

.PHONY: linux
linux: ${NAME}

${NAME}.exe: ${OBJS}
	${CXX} ${CXXFLAGS} ${IFLAGS} ${DFLAGS} -o $@ ${OBJS} ${LFLAGS}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${IFLAGS} ${DFLAGS} -o $@ ${OBJS} ${LFLAGS}

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp | ${OBJ_DIR}
	${CXX} ${CXXFLAGS} ${IFLAGS} ${DFLAGS} -o $@ -c $<

${OBJ_DIR}:
	mkdir -p $(sort $(dir ${OBJS}))

.PHONY: clean
clean:
	rm -rf ${OBJ_DIR}

.PHONY: fclean
fclean: clean
ifneq ("$(wildcard ${NAME}.exe)","")
	rm ${NAME}.exe
endif
ifneq ("$(wildcard ${NAME})","")
	rm ${NAME}
endif

.SILENT: re
.PHONY: re
re: fclean all
