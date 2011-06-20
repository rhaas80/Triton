SOURCES = $(wildcard *.cpp)

RM = /bin/rm
CC = g++
OPT = -O3
IFLAGS = -I../Utilities
CFLAGS = -c -Wall

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libDataAnalysis

clean:
	$(RM) -rf *.o *.d libDataAnalysis.a

.cpp.o:
	$(CC) $(OPT) $(CFLAGS) $(IFLAGS) $< -o $@

%.d: %.cpp
	@set -e; $(RM) -f $@; \
	$(CC) -MM $(IFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) -f $@.$$$$

-include $(EXECUTABLES:=.d)

libDataAnalysis: $(SOURCES)
	@$(RM) -f $@
	@ar cr $@.a $(SOURCES:.cpp=.o)
