include ../MachineDefs

SOURCES = $(wildcard *.cpp)

IFLAGS = -I../Utilities

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libPostNewtonian

clean:
	-$(RM) *.o *.d libPostNewtonian.a

.cpp.o:
	$(C++) $(C++FLAGS) -c $(IFLAGS) $< -o $@

%.d: %.cpp
	@set -e; $(RM) $@; \
	$(MAKEDEPEND) $(IFLAGS) $< > $@.$$$$; \
	$(SED) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

-include $(SOURCES:.cpp=.d)

libPostNewtonian: $(SOURCES)
	@$(RM) $@
	@$(AR) $(ARFLAGS) $@.a $(SOURCES:.cpp=.o)
