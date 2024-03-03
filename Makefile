# -DLX_LEGACY
ARCH = -m64
DEFINES = -DDEBUG -DHAVE_NCURSESW_NCURSES_H -D_FILE_OFFSET_BITS=64
CFLAGS =  -fPIC -O0 -std=c99 -Wall -ggdb3 -Iinclude 
CC = gcc $(ARCH)

DLLDIR = dll/

DLLS =	$(DLLDIR)lib2ine.so $(DLLDIR)doscalls.so \
	$(DLLDIR)msg.so $(DLLDIR)nls.so $(DLLDIR)quecalls.so

all: $(DLLS) hello testtls
	./hello

hello: $(DLLS)
	$(CC) -c -Iinclude hello.c
	$(CC) -o hello hello.o -Wl,-rpath,dll dll/msg.so  dll/lib2ine.so

testtls: $(DLLS)
	$(CC) -c -Iinclude testtls.c
	$(CC) -o testtls testtls.o -Wl,-rpath,dll dll/doscalls.so  dll/lib2ine.so

lib2ine/lib2ine.o:
	$(CC) $(DEFINES) -D_2ine_EXPORTS $(CFLAGS) -o lib2ine/lib2ine.o -c lib2ine/lib2ine.c

doscalls/doscalls.o:
	$(CC) $(DEFINES) -D_doscalls_EXPORTS $(CFLAGS) -o doscalls/doscalls.o -c doscalls/doscalls.c

msg/msg.o:
	$(CC) $(DEFINES) -D_msg_EXPORTS $(CFLAGS) -o msg/msg.o -c msg/msg.c

nls/nls.o:
	$(CC) $(DEFINES) -D_nls_EXPORTS $(CFLAGS) -o nls/nls.o -c nls/nls.c

quecalls/quecalls.o:
	$(CC) $(DEFINES) -D_quecalls_EXPORTS $(CFLAGS) -o quecalls/quecalls.o -c quecalls/quecalls.c


$(DLLDIR)lib2ine.so: lib2ine/lib2ine.o
	$(CC)  -fPIC -shared -Wl,-soname,lib2ine.so -o $(DLLDIR)lib2ine.so lib2ine/lib2ine.o -lpthread

$(DLLDIR)doscalls.so: doscalls/doscalls.o
	$(CC)  -fPIC -shared -Wl,-soname,doscalls.so -o $(DLLDIR)doscalls.so doscalls/doscalls.o -lpthread

$(DLLDIR)msg.so: msg/msg.o
	$(CC)  -fPIC -shared -Wl,-soname,msg.so -o $(DLLDIR)msg.so msg/msg.o -lpthread

$(DLLDIR)nls.so: nls/nls.o
	$(CC)  -fPIC -shared -Wl,-soname,nls.so -o $(DLLDIR)nls.so nls/nls.o -lpthread

$(DLLDIR)quecalls.so: quecalls/quecalls.o
	$(CC)  -fPIC -shared -Wl,-soname,quecalls.so -o $(DLLDIR)quecalls.so quecalls/quecalls.o -lpthread


clean:
	rm $(DLLS)
	rm hello hello.o
	rm testtls testtls.o
	rm doscalls/doscalls.o lib2ine/lib2ine.o msg/msg.o
	rm nls/nls.o quecalls/quecalls.o

#gcc -DDEBUG -DHAVE_NCURSESW_NCURSES_H -D_2ine_EXPORTS -D_FILE_OFFSET_BITS=64 -fPIC -O0 -std=c99 -Wall -ggdb3 -m32 -MD -MT -D_2ine_EXPORTS -c ../lib2ine.c
#gcc -m32 -fPIC -shared -Wl,-soname,lib2ine.so -o lib2ine.so -Wl,-rpath,/home/jsteve/src/2ine lib2ine.o -lpthread



