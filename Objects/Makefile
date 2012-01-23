## Set this, with the order running from most basic to most advanced
IFLAGS = -I../Utilities -I../PostNewtonian



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

WaveformObjects_wrap.cxx : WaveformObjects.i $(SOURCES:.cpp=.d) $(SOURCES:.cpp=.o)

WaveformObjects_python : WaveformObjects_wrap.cxx lib$(THISDIR).so
	swig -c++ -python WaveformObjects.i
	$(C++) -c $(IFLAGS) `python-config --cflags` Waveform.cpp WaveformObjects_wrap.cxx 
	$(C++) $(SHARED) `python-config --ldflags` ../Utilities/libUtilities.so ../PostNewtonian/libPostNewtonian.so Waveform.o WaveformObjects_wrap.o -o _WaveformObjects.so

-include $(SOURCES:.cpp=.d)
