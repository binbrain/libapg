ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_CFLAGS = -c -D_GNU_SOURCE -O2 -ggdb3 --std=gnu99 -fPIC $(CFLAGS) -ggdb
lib_LTLIBRARIES = libapg.la
libapg_la_SOURCES =     src/bloom.c src/convert.c src/apg.h src/apg.c\
			src/convert.h src/errors.c src/errs.h src/owntypes.h\
			src/pronpass.c\
			src/pronpass.h src/randpass.c src/randpass.h\
			src/restrict.c src/restrict.h src/rnd.c src/rnd.h smbl.h\
			src/cast/cast.h src/cast/cast_sboxes.h src/sha/sha.c\
			src/sha/sha.h src/cast/cast.c\
libapg_la_LDFLAGS= -lcrypto
include_HEADERS = src/apg.h
