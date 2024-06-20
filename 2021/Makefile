
CXXFLAGS = -Wall -Wextra -g -O0 -std=gnu++20

all: 01a 01b 02a 02b 03a 03b 04a 04b 05a 05b 06a 06b 07a 07b 08a 08b 09a 09b

.SUFFIXES: .C .cxx .c++
COMPILE.cxx := $(COMPILE.cpp)
LINK.cxx = : $(LINK.cxx)

.cxx:
	$(LINK.C) $^ $(LOADLIBES) $(LDLIBS) -o $@

