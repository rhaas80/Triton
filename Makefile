LIBDIRS:= Utilities PostNewtonian Objects WaveformManip
EXECDIRS:= Routines
SUBDIRS:= $(LIBDIRS) $(EXECDIRS)

all:
	@for d in $(EXECDIRS); do ($(MAKE) -C $$d); done

libs:
	@for d in $(LIBDIRS); do ($(MAKE) -C $$d); done

clean:
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d clean ); done
	@$(MAKE) -C Python clean

realclean:
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d realclean ); done
	@$(MAKE) -C Python realclean

allclean: realclean
