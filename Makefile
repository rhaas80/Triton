SUBDIRS = Objects PostNewtonian Utilities Routines Test

all:
	@$(MAKE) -C Test
	@$(MAKE) -C Routines

clean:
	$(RM) bin/*
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done
# 	@for d in Objects PostNewtonian Utilities Test Routines; do (cd $$d; $(MAKE) clean ); done
# 	@-for d in Objects PostNewtonian Utilities Routines Test; do (cd $$d; $(MAKE) clean ); done

realclean:
	$(RM) bin/*
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done
