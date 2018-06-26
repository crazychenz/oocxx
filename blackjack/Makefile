#REDIRECTION := 2>&1 /dev/null
MAINBIN := blackjack
PROJECTNAME := Blackjack Assignment
REDIRECTION := >/dev/null
FLAGS := -Wall -Werror
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cc)
OBJECTS = $(filter-out main.o,$(SOURCES:%.cc=%.o))

help:
	@echo
	@echo Targets:
	@echo docs - Build doxygen documentation
	@echo $(MAINBIN) - Build the primary binary target
	@echo clean - Cleanup the workspace
	@echo all - Build docs and $(MAINBIN)
	@echo

all: docs $(MAINBIN)

$(MAINBIN): $(OBJECTS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -o $(MAINBIN) main.cc $^ $(REDIRECTION)

%.o : %.cc $(HEADERS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -c -o $@ $< $(REDIRECTION)

clean:
	@echo [ CLEANING WORKSPACE ]
	@rm -rf *.o $(MAINBIN) html latex $(REDIRECTION)

docs:
	@echo [ BUILDING DOCS ]
	@mkdir html ; cp blackjack-class-diagram.png ./html/
	@( \
	    cat Doxyfile | \
	    echo PROJECT_NAME=\"$(PROJECTNAME)\" \
	) | \
	doxygen - $(REDIRECTION)

zip:
	zip -r v_agriesti_blackjack.zip *.cc *.h html latex *.txt *.png Makefile Doxyfile
