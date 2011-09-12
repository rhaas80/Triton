## Set this, with the order running from most basic to most advanced
IFLAGS = -I../Utilities -I../PostNewtonian -I../Objects



## This is a basic source- and library-building makefile; the lines below shouldn't need much tweaking
THISDIR:=$(shell basename `pwd`)
include ../MachineDef

VPATH = $(SUBLIBS)
SUFFIXES += .d

SOURCES = $(wildcard *.cpp)

.PHONY: all

all: realtarget
	@:

realtarget: $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o)

clean:
	-$(RM) *.o *.d lib$(THISDIR).a

realclean:
	-$(RM) *.o *.d lib$(THISDIR).a

%.o : %.cpp
	$(C++) $(C++FLAGS) -c $(IFLAGS) $< -o $@
	@$(AR) $(ARFLAGS) lib$(THISDIR).a $@

%.d : %.cpp
	@$(MAKEDEPEND) $(IFLAGS) -MT '$*.o $*.d' -MF $*.d $*.cpp

lib$(THISDIR).a : realtarget
	@:

-include $(SOURCES:.cpp=.d)
