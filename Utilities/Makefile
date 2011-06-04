include ../MachineDefs

SOURCES = $(wildcard *.cpp)

all: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o) libUtilities

clean:
	-$(RM) `ls *.o | grep -v NoiseCurves` *.d libUtilities.a

realclean:
	-$(RM) *.o *.d libUtilities.a

.cpp.o:
	$(C++) $(C++FLAGS) -c $(IFLAGS) $< -o $@

%.d: %.cpp
	@set -e; $(RM) $@; \
	$(MAKEDEPEND) $< > $@.$$$$; \
	$(SED) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

-include $(SOURCES:.cpp=.d)

libUtilities: $(SOURCES)
	@$(RM) $@
	@$(AR) $(ARFLAGS) $@.a $(SOURCES:.cpp=.o)
