UNAME = $(shell uname)

CXX = g++

SRC_DIR = src
INC_DIR = include
OBJ_DIR = .obj

CXXFLAGS = -Wall -Wextra -Werror -std=gnu++11
IFLAGS = -I${INC_DIR}
DFLAGS = -MMD -MP
LFLAGS = -lSDL2

ifneq ("${DEBUG}", "")
	CXXFLAGS += ${DEBUG}
endif

OBJS = $(patsubst %.cpp,${OBJ_DIR}/%.o,\
	   main.cpp \
	   Maze.cpp \
	   Sdl.cpp \
	   )
DEPS = $(OBJS:.o=.d)

NAME = maze
ifeq (${UNAME}, MS-Windows)
	NAME = maze.exe
endif

.SILENT: all
.PHONY: all

all: ${NAME}

-include ${DEPS}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${IFLAGS} ${DFLAGS} -o $@ ${OBJS} ${LFLAGS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp | ${OBJ_DIR}
	${CXX} ${CXXFLAGS} ${IFLAGS} ${DFLAGS} -o $@ -c $<

${OBJ_DIR}:
	mkdir -p $(sort $(dir ${OBJS}))

.PHONY: clean
clean:
	rm -rf ${OBJ_DIR}

.PHONY: fclean
fclean: clean
	rm -f ${NAME}

.SILENT: re
.PHONY: re
re: fclean
	make --no-print-directory
