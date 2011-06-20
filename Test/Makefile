## Set this, with the order running from most advanced to most basic
SUBLIBS = ../Objects ../PostNewtonian ../Utilities


## This is a basic executables makefile; the lines below shouldn't need much tweaking.
include ../MachineDefs

VPATH = $(SUBLIBS)
SUFFIXES += .d
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:%.cpp=%)
IFLAGS:=$(SUBLIBS:%=-I%)
LFLAGS:=$(SUBLIBS:%=-L%)
lFLAGS:=$(SUBLIBS:../%=-l%)
LIBDEPS:=$(SUBLIBS:../%=lib%.a)

.PHONY: sublibs $(SUBLIBS) svnignore

all: sublibs $(EXECUTABLES) | svnignore

svnignore:
	@$(ECHO) .svnignore $(EXECUTABLES) | tr ' ' '\n' > .$@.tmp
	@test -f .$@ \
	  && ($(DIFF) .$@ .$@.tmp > .$@.diff; \
	      (test -s .$@.diff && (mv .$@.tmp .$@; svn propset svn:ignore . -F .svnignore) || ($(RM) .$@.tmp)); \
	      $(RM) .$@.diff) \
	  || (mv .$@.tmp .$@; svn propset svn:ignore . -F .svnignore)

clean:
	-$(RM) *.d $(EXECUTABLES) .svnignore

realclean:
	-$(RM) *.d $(EXECUTABLES) .svnignore

$(EXECUTABLES): % : %.cpp %.d $(LIBDEPS)
	$(C++) $(C++FLAGS) $*.cpp $(IFLAGS) $(LFLAGS) $(lFLAGS) -o $@
	@$(LN) $@ ../bin/

%.d : %.cpp
	@$(MAKEDEPEND) $(IFLAGS) -MT '$* $*.d' -MF $*.d $*.cpp

sublibs: $(SUBLIBS)

$(SUBLIBS):
	@$(MAKE) -C $@

lib%.a:
	@$(MAKE) -C ../$(subst lib,,$(basename $@)) $@

-include $(EXECUTABLES:=.d)
