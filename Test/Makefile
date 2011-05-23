## Set these variables as appropriate
SUBLIBS = ../Utilities ../PostNewtonian ../Objects
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:%.cpp=%)


## This is a basic makefile; the lines below shouldn't need much tweaking.
include ../MachineDefs

.PHONY: sublibs $(SUBLIBS)
IFLAGS:=$(SUBLIBS:%=-I%)
LFLAGS:=$(SUBLIBS:%=-L%)
lFLAGS:=$(SUBLIBS:../%=-l%)

all: sublibs $(EXECUTABLES)

-include $(EXECUTABLES:=.d)

clean:
	-$(RM) *.d $(EXECUTABLES)

$(EXECUTABLES): % : sublibs %.cpp
	$(C++) $(C++FLAGS) $*.cpp $(IFLAGS) $(LFLAGS) $(lFLAGS) -o $@
	@$(MAKEDEPEND) $(IFLAGS) $*.cpp > $*.d.tmp
	@$(SED) -e 's/.o:/:/'< $*.d.tmp > $*.d
	@$(RM) -f $*.d.tmp
	@$(LN) $@ ../bin

sublibs: $(SUBLIBS)

$(SUBLIBS):
	@$(MAKE) -C $@
