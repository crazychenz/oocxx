FLAGS := -Wall -Werror
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:%.cc=%.o)

all: main docs

main: $(OBJECTS)
	g++ $(FLAGS) -std=c++11 -o main $^

%.o : %.cc $(HEADERS)
	g++ $(FLAGS) -std=c++11 -c -o $@ $<

clean:
	rm -rf *.o main html latex

docs:
	doxygen
