#REDIRECTION := 2>&1 /dev/null
REDIRECTION := >/dev/null
FLAGS := -Wall -Werror
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:%.cc=%.o)

all: docs main

main: $(OBJECTS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -o main $^ $(REDIRECTION)

%.o : %.cc $(HEADERS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -c -o $@ $< $(REDIRECTION)

clean:
	@echo [ CLEANING WORKSPACE ]
	@rm -rf *.o main html latex $(REDIRECTION)

docs:
	@echo [ BUILDING DOCS ]
	@doxygen $(REDIRECTION)
