check_PROGRAMS = checklibnet
checklibnet_SOURCES = checklibnet-main.c
LIBNET_CFLAGS =
LIBNET_LIBS = -lnet
checklibnet_CFLAGS = $(LIBNET_CFLAGS)
checklibnet_LDADD = $(LIBNET_LIBS)
EXTRA_DIST = README.html autogen.sh
#----------------------------------------
bin_PROGRAMS = printmac
printmac_SOURCES = printmacaddr/main.c
printmac_CFLAGS = $(LIBNET_CFLAGS)
printmac_LDADD = $(LIBNET_LIBS)

