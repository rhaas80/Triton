SUBDIRS = Objects PostNewtonian Utilities Routines Test

all:
	@$(MAKE) -C Test
	@$(MAKE) -C Routines

clean:
	$(RM) bin/*
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d clean ); done

realclean:
	$(RM) bin/*
	@for d in $(SUBDIRS); do ($(MAKE) -C $$d realclean ); done

allclean: realclean
