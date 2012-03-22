## Set this, with the order running from most basic to most advanced
IFLAGS = -I../../Utilities -I../../PostNewtonian -I../../Objects



## This is a basic source- and library-building makefile; the lines below shouldn't need much tweaking
THISDIR:=$(shell basename `pwd`)
include ../../MachineDef

GIT_REVISION:=$(shell git rev-parse HEAD)

VPATH = $(IFLAGS:-I../../%=%)
SUFFIXES += .d

LFLAGS:=$(IFLAGS:-I%=-L%)
lFLAGS:=$(IFLAGS:-I../../%=-l%)

.PHONY: all

all: realtarget
	@:

realtarget: _WignerD.so
	@:

clean:
	-$(RM) WignerD_wrap.{o,cxx} WignerD.py{,c} _WignerD.so

realclean:
	-$(RM) WignerD_wrap.{o,cxx} WignerD.py{,c} _WignerD.so

Test : _WignerD.so

_WignerD.so : WignerD.i
	swig -c++ -python WignerD.i
	@:
	$(C++) -DSWIG -c $(IFLAGS) `python-config --cflags | perl -pe 's/ -Wstrict-prototypes//'` \
		-I/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/numpy/core/include/ \
		WignerD_wrap.cxx
	@:
	$(C++LINK) -Wl,-rpath,$(CURDIR)/../../lib -DSWIG $(SHARED) \
		`python-config --ldflags | perl -pe 's#/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python##'` \
		$(LFLAGS) $(lFLAGS) WignerD_wrap.o -o _WignerD.so

-include $(SOURCES:.cpp=.d)
