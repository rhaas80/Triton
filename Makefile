LIBDIRS:= Utilities PostNewtonian Objects
EXECDIRS:= Routines
SUBDIRS:= $(LIBDIRS) $(EXECDIRS)

all:
	@for d in $(EXECDIRS); do ($(MAKE) -C $$d); done

libs:
	@for d in $(LIBDIRS); do ($(MAKE) -C $$d); done

clean:
	$(RM) bin/*
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d clean ); done

realclean:
	$(RM) bin/*
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d realclean ); done

allclean: realclean
