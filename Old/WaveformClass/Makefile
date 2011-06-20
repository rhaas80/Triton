SUBDIRS = DataAnalysis Waveforms PostNewtonian Utilities Routines Test

all:
	@$(MAKE) -C Routines

mostlyclean:
	$(RM) -f bin/*
	@-for d in Waveforms PostNewtonian Utilities Routines Test; do (cd $$d; $(MAKE) clean ); done

clean:
	$(RM) -f bin/*
	@-for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done
