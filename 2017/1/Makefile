
CXXFLAGS = -Wall -Wextra -g -O3 -std=gnu++14

#all: Palindromes copy-constructors

.SUFFIXES: .C .cxx .c++
COMPILE.cxx := $(COMPILE.cpp)
LINK.cxx = : $(LINK.cxx)

.cxx:
	$(LINK.C) $^ $(LOADLIBES) $(LDLIBS) -o $@

