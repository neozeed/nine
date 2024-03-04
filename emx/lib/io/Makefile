OBJ = access.o fclose.o _fill.o fputs.o fsync.o printf.o _seekhdr.o stdio.o vprintf.o \
	chmod.o fdopen.o flushall.o fread.o ftell.o isatty.o puts.o setbuf.o tell.o vsprintf.o \
	clearerr.o fflush.o _flush.o freopen.o ftruncat.o lseek.o read.o setbuffe.o _tmpbuf.o write.o \
	close.o fgetc.o _fopen.o fscanf.o fwrite.o remove.o setmode.o tmpfile.o \
	creat.o fgetchar.o fopen.o fseek.o gets.o mktemp.o rename.o setvbuf.o truncate.o \
	eof.o fgetpos.o fprintf.o _fseekhd.o _input.o _newstre.o rewind.o sprintf.o ungetc.o \
	_fbuf.o fgets.o fputc.o fsetpos.o ioctl.o open.o rmtmp.o sscanf.o unlink.o \
	fcloseal.o fileleng.o fputchar.o fstat.o _iodata.o _output.o scanf.o stat.o vfprintf.o

CFLAGS = -fno-builtin -nostdinc -I../../include

CC = i586-linux-gcc


io.a: $(OBJ)
	i586-linux-ar cru io.a $(OBJ)
	i586-linux-ranlib io.a
	i586-linux-size io.a


clean:
	@rm -f $(OBJ)
	@rm -f io.a
