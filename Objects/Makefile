SOURCES = $(wildcard *.cpp)

RM = /bin/rm
CC = g++
#OPT = -O3
# IFLAGS = -I../Utilities -I../PostNewtonian -I../DataAnalysis
IFLAGS = -I../Utilities
#CFLAGS = -c -Wall

OPT = 
CFLAGS = -c -ggdb -Wall

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libObjects

clean:
	$(RM) -rf *.o *.d libObjects.a

.cpp.o:
	$(CC) $(OPT) $(CFLAGS) $(IFLAGS) $< -o $@

%.d: %.cpp
	@set -e; $(RM) -f $@; \
	$(CC) -MM $(IFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) -f $@.$$$$

-include $(EXECUTABLES:=.d)

libObjects: $(SOURCES)
	@$(RM) -f $@
	@ar cr $@.a $(SOURCES:.cpp=.o)
