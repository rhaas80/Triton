## Set these variables as appropriate
SUBLIBS = ../Utilities ../PostNewtonian ../Objects
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:%.cpp=%)


## This is a basic makefile; the lines below shouldn't need much tweaking.
.PHONY: sublibs $(SUBLIBS)
RM = /bin/rm
CC = g++
OPT = -O3
CFLAGS = -c
WFLAGS = -w
#-Wall
IFLAGS:=$(SUBLIBS:%=-I%)
LFLAGS:=$(SUBLIBS:%=-L%)
lFLAGS:=$(SUBLIBS:../%=-l%)

all: sublibs $(EXECUTABLES)

-include $(EXECUTABLES:=.d)

clean:
	$(RM) -f *.d $(EXECUTABLES)

$(EXECUTABLES): % : %.cpp
	$(CC) $(OPT) $(WFLAGS) $*.cpp $(IFLAGS) $(LFLAGS) $(lFLAGS) -o $@ -pg -g
	@$(CC) -MM $(IFLAGS) $*.cpp > $*.d.tmp
	@sed -e 's/.o:/:/'< $*.d.tmp > $*.d
	@$(RM) -f $*.d.tmp
	@ln -sf $@ ../bin

sublibs: $(SUBLIBS)

$(SUBLIBS):
	@$(MAKE) -C $@
