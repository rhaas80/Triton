## Set this, with the order running from most basic to most advanced
IFLAGS = -I../Utilities -I../PostNewtonian -I../Objects



## This is a basic source- and library-building makefile; the lines below shouldn't need much tweaking
THISDIR:=$(shell basename `pwd`)
include ../MachineDef

GIT_REVISION:=$(shell git rev-parse HEAD)

VPATH = $(SUBLIBS)
SUFFIXES += .d

LFLAGS:=$(SUBLIBS:%=-L%)
lFLAGS:=$(SUBLIBS:../%=-l%)

.PHONY: all

all: realtarget
	@:

realtarget:
	@(make -s GravitationalWaves_python)

clean:
	-$(RM) GravitationalWaves_wrap.{o,cxx} GravitationalWaves.py{,c} _GravitationalWaves.so

realclean:
	-$(RM) GravitationalWaves_wrap.{o,cxx} GravitationalWaves.py{,c} _GravitationalWaves.so

GravitationalWaves_python : GravitationalWaves.i
	swig -c++ -python GravitationalWaves.i
	:
	$(C++) -c $(IFLAGS) `python-config --cflags | perl -pe 's/ -Wstrict-prototypes//'` \
		-I/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/numpy/core/include/ \
		GravitationalWaves_wrap.cxx
	:
	$(C++) $(SHARED) `python-config --ldflags | perl -pe 's#/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python##'` \
		$(LFLAGS) $(lFLAGS) GravitationalWaves_wrap.o -o _GravitationalWaves.so

-include $(SOURCES:.cpp=.d)
