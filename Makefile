# -DLX_LEGACY
ARCH = -m64 
DEFINES = -DDEBUG -DHAVE_NCURSESW_NCURSES_H -D_FILE_OFFSET_BITS=64
CFLAGS =  -fPIC -O0 -std=c99 -Wall -ggdb3 -Iinclude -fno-stack-protector
#CFLAGS =  -O0 -ggdb3 -Wall -std=gnu99 -pedantic -nostdlib -fomit-frame-pointer -fno-stack-protector -fno-unwind-tables \
#	  -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -ffunction-sections \
#	  -fdata-sections -Iinclude

#CC = i586-linux-gcc
CC = gcc $(ARCH)

#LIBS = emx/lib/io/io.a emx/lib/misc/misc.a emx/lib/str/str.a
LIBS = emx/lib/libc.a

DLLDIR = dll/

DLLS =	$(DLLDIR)lib2ine.so $(DLLDIR)doscalls.so \
	$(DLLDIR)msg.so $(DLLDIR)nls.so $(DLLDIR)quecalls.so

default: $(DLLS) 
	echo "tada"

hello32: $(DLLS)
	$(CC) -c start32.c
	$(CC) -c -fno-stack-protector -fno-builtin -ggdb3 -O0 -Iinclude hello.c
#	i586-linux-ld --as-needed -dynamic-linker /lib/ld-linux.so.2  -pie -m elf_i386 -rpath dll start32.o hello.o dll/msg.so dll/lib2ine.so -o hello32
	i586-linux-ld --as-needed -dynamic-linker /lib/ld-linux.so.2  -pie -m elf_i386 -rpath dll rt0/00_start.o rt0/syscall.o hello.o rt0/_exit.o  $(LIBS) dll/msg.so dll/lib2ine.so -o hello32

hello64: $(DLLS)
	$(CC) -c start.c
	$(CC) $(CFLAGS) -fno-stack-protector -fno-builtin -ggdb3 -O0 -Iinclude -c hello.c
#	$(CC) -c -fno-builtin -ggdb3 -O0 -Iinclude hello.c
	ld --nostdlib  -dynamic-linker /lib64/ld-linux-x86-64.so.2 start.o hello.o -o hello -rpath dll /usr/lib/x86_64-linux-gnu/libc.so
#	ld --nostdlib  -verbose -dynamic-linker /lib64/ld-linux-x86-64.so.2 start.o hello.o -o hello64 -rpath dll emx/lib/libc.a  missinc.o dll/msg.so dll/lib2ine.so
#	ld --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie start.o hello.o -o hello64 \
	-rpath dll dll/msg.so dll/lib2ine.so
#	$(CC) -o hello hello.o -Wl,-rpath,dll dll/msg.so  dll/lib2ine.so
#	$(CC) -o hello hello.o -Wl,-rpath,dll

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
	@rm -f $(DLLS)
	@rm -f hello32 hello64 hello.o start.o start32.o
	@rm -f testtls testtls.o
	@rm -f doscalls/doscalls.o lib2ine/lib2ine.o msg/msg.o
	@rm -f nls/nls.o quecalls/quecalls.o

#gcc -DDEBUG -DHAVE_NCURSESW_NCURSES_H -D_2ine_EXPORTS -D_FILE_OFFSET_BITS=64 -fPIC -O0 -std=c99 -Wall -ggdb3 -m32 -MD -MT -D_2ine_EXPORTS -c ../lib2ine.c
#gcc -m32 -fPIC -shared -Wl,-soname,lib2ine.so -o lib2ine.so -Wl,-rpath,/home/jsteve/src/2ine lib2ine.o -lpthread



