THISDIR:=$(shell basename `pwd`)

clean:
	-$(RM) `ls *.o | grep -v SWSHs` *.d lib$(THISDIR).so

realclean:
	-$(RM) *.o *.d lib$(THISDIR).so
