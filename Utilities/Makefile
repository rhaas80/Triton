SOURCES = $(wildcard *.cpp)

RM = /bin/rm
CC = g++
OPT = -O3
CFLAGS = -c

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libUtilities

clean:
	$(RM) -rf *.o *.d libUtilities.a

.cpp.o:
	$(CC) $(OPT) $(CFLAGS) $(IFLAGS) $< -o $@

%.d: %.cpp
	@set -e; $(RM) -f $@; \
	$(CC) -MM $(IFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) -f $@.$$$$

-include $(EXECUTABLES:=.d)

libUtilities: $(SOURCES)
	@$(RM) -f $@
	@ar cr $@.a $(SOURCES:.cpp=.o)
