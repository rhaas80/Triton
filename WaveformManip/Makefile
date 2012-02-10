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
	@(make -s lib$(THISDIR).so)

clean:
	-$(RM) *.o *.d lib$(THISDIR).so

realclean:
	-$(RM) *.o *.d lib$(THISDIR).so

%.o : %.cpp
	$(C++) $(C++FLAGS) -c $(IFLAGS) $< -o $@

%.d : %.cpp
	@$(MAKEDEPEND) $(IFLAGS) -MT '$*.o $*.d' -MF $*.d $*.cpp

lib$(THISDIR).so : $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o)
	$(C++) $(SHARED) -o lib$(THISDIR).so $(SOURCES:.cpp=.o)
	@$(LN) ../$(THISDIR)/$@ ../lib/
	$(INSTALL_NAME_TOOL)

-include $(SOURCES:.cpp=.d)
