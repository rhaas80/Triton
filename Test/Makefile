## Set this, with the order running from most advanced to most basic
SUBLIBS = ../Objects ../PostNewtonian ../Utilities


## This is a basic executables makefile; the lines below shouldn't need much tweaking.
include ../MachineDef

VPATH = $(SUBLIBS)
SUFFIXES += .d
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:%.cpp=%)
IFLAGS:=$(SUBLIBS:%=-I%)
LFLAGS:=$(SUBLIBS:%=-L%)
lFLAGS:=$(SUBLIBS:../%=-l%)
LIBDEPS:=$(SUBLIBS:../%=lib%.so)

.PHONY: sublibs $(SUBLIBS) gitignore

all: sublibs $(EXECUTABLES) | gitignore

gitignore:
	@$(ECHO) .gitignore $(EXECUTABLES) | tr ' ' '\n' > .$@.tmp
	@test -f .$@ \
	  && ($(DIFF) .$@ .$@.tmp > .$@.diff; \
	      (test -s .$@.diff && (mv .$@.tmp .$@) || ($(RM) .$@.tmp)); \
	      $(RM) .$@.diff) \
	  || (mv .$@.tmp .$@)

clean:
	-$(RM) *.d $(EXECUTABLES) .gitignore

realclean:
	-$(RM) *.d $(EXECUTABLES) .gitignore

$(EXECUTABLES): % : %.cpp %.d $(LIBDEPS)
	$(C++LINK) -Wl,-rpath,$(CURDIR)/../lib $(C++FLAGS) $*.cpp $(IFLAGS) $(LFLAGS) $(lFLAGS) -o $@

%.d : %.cpp
	@$(MAKEDEPEND) $(IFLAGS) -MT '$* $*.d' -MF $*.d $*.cpp

sublibs: $(SUBLIBS)

$(SUBLIBS):
	@$(MAKE) -C $@

lib%.so:
	@$(MAKE) -C ../$(subst lib,,$(basename $@)) $@

-include $(EXECUTABLES:=.d)
