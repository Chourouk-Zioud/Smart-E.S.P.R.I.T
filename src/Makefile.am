## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = 3b6g1

3b6g1_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	admin.c admin.h \
	menu.c menu.h \
	stock.c stock.h \
	agent.c agent.h \
	rec.c rec.h \
	capteur.c capteur.h

3b6g1_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

