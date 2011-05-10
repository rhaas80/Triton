SOURCES = $(wildcard *.cpp)

RM = /bin/rm
CC = g++
# IFLAGS = -I../Utilities -I../PostNewtonian -I../DataAnalysis
IFLAGS = -I../Utilities
OPT = -O3
CFLAGS = -c -Wall
# OPT = -O3
# CFLAGS = -c

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libObjects

clean:
	$(RM) -rf *.o *.d libObjects.a

.cpp.o:
	$(CC) $(OPT) $(CFLAGS) $(IFLAGS) $< -o $@ -pg -g

%.d: %.cpp
	@set -e; $(RM) -f $@; \
	$(CC) -MM $(IFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) -f $@.$$$$

-include $(EXECUTABLES:=.d)

libObjects: $(SOURCES)
	@$(RM) -f $@
	@ar cr $@.a $(SOURCES:.cpp=.o)
