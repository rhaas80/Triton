SUBDIRS = Objects PostNewtonian Utilities Test
# SUBDIRS = Objects PostNewtonian Utilities Routines Test

all:
	@$(MAKE) -C Routines

clean:
	$(RM) -f bin/*
	@-for d in Objects PostNewtonian Utilities Test; do (cd $$d; $(MAKE) clean ); done
# 	@-for d in Objects PostNewtonian Utilities Routines Test; do (cd $$d; $(MAKE) clean ); done

realclean:
	$(RM) -f bin/*
	@-for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done
