OS = $(shell uname)
CC = g++
LIBS = -lGLEW -lSDL2
FLAGS = -std=c++11

EXEC = app

ifeq ($(OS),Darwin)
	CC = clang++
	LIBS += -framework OpenGL
	FLAGS += -stdlib=libc++
else
	LIBS += -lGL
endif


SOURCES := $(shell find . -type f -name '*.cpp')
OBJECTS := $(SOURCES:%.cpp=%.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ $(LIBS)


clean:
	rm -f $(OBJECTS)