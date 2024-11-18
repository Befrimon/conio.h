.PHONY: clean install uninstall

clean:
	rm -rf build

install:
	mkdir build
	g++ -c -fPIC conio.cpp -o build/conio.h.o
	g++ -shared -o build/libconio.h.so build/conio.h.o
	cp build/libconio.h.so /usr/lib
	cp conio.h /usr/include

uninstall:
	rm /usr/lib/libconio.h.so
	rm /usr/include/conio.h
