all:
	python setup.py install --user

doc:
	@doxygen
	@cd Python && ./doxygen2docstring.py ../xml/index.xml WaveformObjects_Doc.i
