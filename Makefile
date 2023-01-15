CC = g++
LD = g++
PROJECT_NAME = project 

BIN = bin
SRC = src
INCLUDE = include
OBJDIR = obj

SDL2 = -lSDL2 -lSDL2_image

LIBRARIES = $(SDL2)

LANG_STD = c++17

CFLAGS = -std=$(LANG_STD) -Wall -pipe $(LIBRARIES) 
OFLAGS = -c -I/usr/include -I$(INCLUDE)
LFLAGS = $(CFLAGS) -L/usr/lib/

SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%,$(OBJDIR)/%,$(SOURCES:.cpp=.o))



DEBUG = no
PROFILE = no
PEDANTIC = no
OPTIMIZATION = -O3

ifeq ($(DEBUG), yes)
	CFLAGS += -g
	OPTIMIZATION = -O0
endif

ifeq ($(PROFILE), yes)
	CFLAGS += -pg
endif

CFLAGS += $(OPTIMIZATION)

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(BIN)/$(PROJECT_NAME)

$(OBJDIR)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(BIN)/$(PROJECT_NAME)

rebuild: clean all

.PHONY : clean
.SILENT : clean
