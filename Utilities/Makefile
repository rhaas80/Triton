### This directory is the basic directory, with no dependencies
# ## Set this, with the order running from most basic to most advanced
# #IFLAGS = 


## This is a basic source- and library-building makefile; the lines below shouldn't need much tweaking
THISDIR:=$(shell basename `pwd`)
include ../MachineDef

VPATH = $(IFLAGS:-I../%=%)
SUFFIXES += .d

SOURCES = $(wildcard *.cpp)

.PHONY: all

all: realtarget
	@:

#$(SOURCES:.cpp=.d) 
realtarget: $(SOURCES:.cpp=.o)
	@(make -s lib$(THISDIR).so)

clean:
	-$(RM) `ls *.o | grep -v SWSHs` *.d lib$(THISDIR).so

realclean:
	-$(RM) *.o *.d lib$(THISDIR).so

%.o : %.cpp
# 	$(C++) $(C++FLAGS) -c $(IFLAGS) $< -o $@ ### This directory is the basic directory, with no dependencies
	$(C++) $(C++FLAGS) -c $< -o $@

%.d : %.cpp
	@$(MAKEDEPEND) $(IFLAGS) -MT '$*.o $*.d' -MF $*.d $*.cpp

# $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o)
lib$(THISDIR).so :
	$(C++) $(SHARED) -o lib$(THISDIR).so $(SOURCES:.cpp=.o)
	$(LN) ../$(THISDIR)/$@ ../lib/
	$(INSTALL_NAME_TOOL)

-include $(SOURCES:.cpp=.d)
