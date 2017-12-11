.PHONY: default all clean astyle atom zip

SDL_CFLAGS := $(shell sdl-config --cflags)
SDL_LIBS := $(shell sdl-config --libs)

SCREEN_DIR	:= ./Screen
SCENE_DIR   := ./Scene

CC	:= g++
CFLAGS	:= -W -Wall -ansi -pthread -std=c++14  $(SDL_CFLAGS)
LDFLAGS	:=

INCLS	:= -I. -I$(SCREEN_DIR) -I$(SCENE_DIR)
LIBS	:= $(SDL_LIBS)

TARGET	:= main

CPP_FILES	:= $(wildcard *.cpp  $(SCREEN_DIR)/*.cpp $(SCENE_DIR)/*.cpp)
HPP_FILES	:= $(wildcard *.hpp  $(SCREEN_DIR)/*.hpp $(SCENE_DIR)/*.hpp)
O_FILES	:= $(CPP_FILES:%.cpp=%.o)

default: all

all: $(TARGET)

# Documentation on Automatics Variables:
# https://www.gnu.org/software/make/manual/make.html#Automatic-Variables

$(TARGET): $(O_FILES) Makefile
	$(CC) $(LDFLAGS) $(O_FILES) $(LIBS) -o $@

$(O_FILES): %.o: %.cpp Makefile $(HPP_FILES)
	$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

### Begin inclusion part

# Documentation on processing include directives
# https://www.gnu.org/software/make/manual/make.html#Include

main.dep: $(CPP_FILES) $(HPP_FILES)
	gcc -MM -std=c++14 -pthread $(INCLS) $^ > main.dep

include main.dep

# End inclusion part

clean:
	-rm -f $(O_FILES) main.dep
	-find . -type f -iname '*.orig' -delete

astyle:
	astyle $(CPP_FILES) $(HPP_FILES)

atom: astyle clean
	open -a atom $(CPP_FILES) $(HPP_FILES) Makefile

zip: astyle clean
	zip -r ../raytracing.zip Makefile *.?pp Screen/*.?pp Scene/object.hpp Scene/camera.hpp
