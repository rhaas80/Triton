## Set this, with the order running from most basic to most advanced
IFLAGS = -I../Utilities -I../PostNewtonian -I../Objects



## This is a basic source- and library-building makefile; the lines below shouldn't need much tweaking
THISDIR:=$(shell basename `pwd`)
include ../MachineDef

GIT_REVISION:=$(shell git rev-parse HEAD)

VPATH = $(IFLAGS:-I../%=%)
SUFFIXES += .d

LFLAGS:=$(IFLAGS:-I%=-L%)
lFLAGS:=$(IFLAGS:-I../%=-l%)

# .PHONY: all

all:

# all: realtarget
# 	@:

# realtarget: _WaveformObjects.so _SWSHs.so
# 	@:

# clean:
# 	-$(RM) WaveformObjects_wrap.{o,cxx} PyGW/WaveformObjects.py{,c} PyGW/_WaveformObjects.so SWSHs_wrap.{o,cxx} SWSHs.py{,c} _SWSHs.so

# realclean:
# 	-$(RM) WaveformObjects_wrap.{o,cxx} PyGW/WaveformObjects.py{,c} PyGW/_WaveformObjects.so SWSHs_wrap.{o,cxx} SWSHs.py{,c} _SWSHs.so

# PyGW : _WaveformObjects.so

# _WaveformObjects.so : WaveformObjects.i ../Utilities/libUtilities.so ../PostNewtonian/libPostNewtonian.so ../Objects/libObjects.so
# 	${SWIG} -c++ -python -outdir PyGW WaveformObjects.i
# 	@:
# 	$(C++) -DSWIG -c $(IFLAGS) -fPIC `python-config --cflags | perl -pe 's/ -Wstrict-prototypes//'` \
# 		-I/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/numpy/core/include/ \
# 		WaveformObjects_wrap.cxx
# 	@:
# 	$(C++LINK) -Wl,-rpath,$(CURDIR)/../lib -DSWIG $(SHARED) \
# 		`python-config --ldflags | perl -pe 's#/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python##'` \
# 		$(LFLAGS) $(lFLAGS) WaveformObjects_wrap.o -o PyGW/_WaveformObjects.so

# SWSHs : _SWSHs.so

# _SWSHs.so : SWSHs.i
# 	${SWIG} -c++ -python SWSHs.i
# 	@:
# 	$(C++) -DSWIG -c $(IFLAGS) -fPIC `python-config --cflags | perl -pe 's/ -Wstrict-prototypes//'` \
# 		-I/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/numpy/core/include/ \
# 		SWSHs_wrap.cxx
# 	@:
# 	$(C++LINK) -Wl,-rpath,$(CURDIR)/../lib -DSWIG $(SHARED) \
# 		`python-config --ldflags | perl -pe 's#/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python##'` \
# 		$(LFLAGS) $(lFLAGS) SWSHs_wrap.o -o _SWSHs.so

-include $(SOURCES:.cpp=.d)
