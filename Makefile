SHELL := /bin/bash

default: simpletests complicatedtests

clean:
	rm -f test-bin/*

simpletests: test-src/*.c test-src/*.cpp
	mkdir -p test-bin
	for i in test-src/*.c test-src/*.cpp; do $(CC) -lpthread $(CFLAGS) -o test-bin/`basename $$i .c` $$i; done

complicatedtests: test-src/*/*.c test-src/*.cpp
	mkdir -p test-bin
	for i in test-src/*/; do pushd $$i; $(MAKE) -B; popd; cp $$i/`basename $$i` test-bin/`basename $$i`; done
