SUBDIRS:= Utilities PostNewtonian Objects Python

all:
	python setup.py install --user

doc:
	@doxygen
	@cd Python && ./doxygen2docstring.py ../xml/index.xml WaveformObjects_Doc.i

clean:
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d clean ); done
	@$(MAKE) -C Python clean

realclean:
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d realclean ); done
	@/bin/rm -rf xml/*xml xml/*xslt xml/*xsd
	@$(MAKE) -C Python realclean

allclean: realclean
