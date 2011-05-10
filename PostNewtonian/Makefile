SOURCES = $(wildcard *.cpp)

RM = /bin/rm
CC = g++
OPT = -O3
CFLAGS = -c -Wall
IFLAGS = -I../Utilities

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libPostNewtonian

clean:
	$(RM) -rf *.o *.d libPostNewtonian.a

.cpp.o:
	$(CC) $(OPT) $(CFLAGS) $(IFLAGS) $< -o $@ -pg -g

%.d: %.cpp
	@set -e; $(RM) -f $@; \
	$(CC) -MM $(IFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) -f $@.$$$$

-include $(EXECUTABLES:=.d)

libPostNewtonian: $(SOURCES)
	@$(RM) -f $@
	@ar cr $@.a $(SOURCES:.cpp=.o)
