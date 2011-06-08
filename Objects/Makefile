include ../MachineDefs

SOURCES = $(wildcard *.cpp)

IFLAGS = -I../PostNewtonian -I../Utilities

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libObjects

clean:
	-$(RM) *.o *.d libObjects.a

.cpp.o:
	$(C++) $(C++FLAGS) -c $(IFLAGS) $< -o $@

%.d: %.cpp
	@set -e; $(RM) -f $@; \
	$(MAKEDEPEND) $(IFLAGS) $< > $@.$$$$; \
	$(SED) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

-include $(SOURCES:.cpp=.d)

libObjects: $(SOURCES)
	@$(RM) $@
	@$(AR) $(ARFLAGS) $@.a $(SOURCES:.cpp=.o)
