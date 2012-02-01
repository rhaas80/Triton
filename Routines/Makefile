## Set this, with the order running from most advanced to most basic
SUBLIBS = ../WaveformManip ../Objects ../PostNewtonian ../Utilities


## This is a basic executables makefile; the lines below shouldn't need much tweaking.
include ../MachineDef

VPATH = $(SUBLIBS)
SUFFIXES += .d
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:%.cpp=%)
BINEXECUTABLES = $(SOURCES:%.cpp=../bin/%)
IFLAGS:=$(SUBLIBS:%=-I%)
LFLAGS:=$(SUBLIBS:%=-L%)
lFLAGS:=$(SUBLIBS:../%=-l%)
LIBDEPS:=$(SUBLIBS:../%=lib%.so)

.PHONY: sublibs $(SUBLIBS) gitignore

all: sublibs $(EXECUTABLES) | gitignore

gitignore:
	@$(ECHO) .gitignore MakefileForUseInExternalDirectories $(EXECUTABLES) | tr ' ' '\n' > .$@.tmp
	@test -f .$@ \
	  && ($(DIFF) .$@ .$@.tmp > .$@.diff; \
	      (test -s .$@.diff && (mv .$@.tmp .$@; cp .$@ ../bin/) || ($(RM) .$@.tmp)); \
	      $(RM) .$@.diff) \
	  || (mv .$@.tmp .$@; cp .$@ ../bin/)

clean:
	-$(RM) *.d $(EXECUTABLES) $(BINEXECUTABLES) .gitignore ../bin/.gitignore

realclean:
	-$(RM) *.d $(EXECUTABLES) $(BINEXECUTABLES) .gitignore ../bin/.gitignore

$(EXECUTABLES): % : %.cpp %.d $(LIBDEPS)
	$(C++) $(C++FLAGS) $*.cpp $(IFLAGS) $(LFLAGS) $(lFLAGS) -o $@
	@$(LN) ../Routines/$@ ../bin/

%.d : %.cpp
	@$(MAKEDEPEND) $(IFLAGS) -MT '$* $*.d' -MF $*.d $*.cpp

sublibs: $(SUBLIBS)

$(SUBLIBS):
	@$(MAKE) -C $@

lib%.so:
	@$(MAKE) -C ../$(subst lib,,$(basename $@)) $@

-include $(EXECUTABLES:=.d)
