SUBDIRS:= Utilities PostNewtonian Objects

all:
	python setup.py install --user

doc:
	@doxygen
	@cd Python && ./doxygen2docstring.py ../xml/index.xml WaveformObjects_Doc.i

clean:
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d clean ); done

realclean:
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d realclean ); done
	@/bin/rm -rf xml/*xml xml/*xslt xml/*xsd

allclean: realclean
