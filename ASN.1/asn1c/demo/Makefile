
all:
	asn1c MyModule.asn1
	cat src/encode-xml.c > converter-sample.c
	make -f Makefile.am.sample

clean:
	rm -f *.o *.c *.h Makefile.am.sample progname
	rm -f converter-example.mk Makefile.am.asn1convert Makefile.am.libasncodec
