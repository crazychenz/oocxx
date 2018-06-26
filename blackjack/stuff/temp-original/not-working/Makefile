#REDIRECTION := 2>&1 /dev/null
REDIRECTION := >/dev/null
FLAGS := -Wall -Werror
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cc)
# Filter out ConsoleUI since it needs to be included in all
# compilation units for its class member templates.
OBJECTS = $(filter-out main.o ui-main.o,$(SOURCES:%.cc=%.o))

all: ui-main

main: $(OBJECTS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -o main main.cc $^ $(REDIRECTION)

ui-main: $(OBJECTS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -o ui-main ui-main.cc $^ $(REDIRECTION)

%.o : %.cc $(HEADERS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -c -o $@ $< $(REDIRECTION)

clean:
	@echo [ CLEANING WORKSPACE ]
	@rm -rf *.o main ui-main html latex $(REDIRECTION)

docs:
	@echo [ BUILDING DOCS ]
	@doxygen $(REDIRECTION)

