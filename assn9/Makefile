#REDIRECTION := 2>&1 /dev/null
MAINBIN := assn9
PROJECTNAME := Assignment 9
REDIRECTION := >/dev/null
FLAGS := -Wall -Werror
HEADERS := $(wildcard *.h)
SOURCES := $(wildcard *.cc)
OBJECTS := $(filter-out main.o brute.o,$(SOURCES:%.cc=%.o))

# Style command stuff
STYLEFLAGS := -z2 -n -s4
STYLED = astyle $2 $(STYLEFLAGS) $1 | grep -v ^Unchanged

help:
	@echo
	@echo Targets:
	@echo docs - Build doxygen documentation
	@echo $(MAINBIN) - Build the primary binary target
	@echo clean - Cleanup the workspace
	@echo style - Style the code with astyle
	@echo all - Build docs and $(MAINBIN)
	@echo

all: docs $(MAINBIN)

.PHONY: style
style: $(SOURCES) $(HEADERS)
	@echo [ STYLING CODE ]
	@astyle $(STYLEFLAGS) $^

$(MAINBIN): $(OBJECTS)
	@if [ ! -z "$$(which astyle)" ]; then \
	  if [ ! -z "$$($(call STYLED,$(HEADERS) $(SOURCES),--dry-run))" ]; \
	  then \
	    echo "WARNING: Detected style issues. Run 'make style' to fix."; \
	  fi \
	fi
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -o $(MAINBIN) main.cc $(OBJECTS) $(REDIRECTION)

%.o : %.cc $(HEADERS)
	@echo G++ $@
	@g++ $(FLAGS) -std=c++11 -c -o $@ $< $(REDIRECTION)

clean:
	@echo [ CLEANING WORKSPACE ]
	@rm -rf *.o $(MAINBIN) html latex $(REDIRECTION)

html:
	@mkdir html

docs: html
	@echo [ BUILDING DOCS ]
	@cp *.png ./html/ 2>/dev/null ; true
	@cp *.mov ./html/ 2>/dev/null ; true
	@( \
	    cat Doxyfile | \
	    echo PROJECT_NAME=\"$(PROJECTNAME)\" \
	) | \
	doxygen - $(REDIRECTION)

zip:
	zip -r assignment8_vagriesti.zip *vcxproj* *.cc *.h html latex *.mov \
	    *.wmv *.png Makefile Doxyfile

