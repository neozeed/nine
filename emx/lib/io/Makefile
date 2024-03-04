OBJ = access.o _fbuf.o fgets.o fputchar.o fstat.o isatty.o popen.o _seekhdr.o tell.o write.o \
      fcloseal.o fileleng.o fputs.o fsync.o _isterm.o printf.o setbuf.o _tmpbuf.o \
      chmod.o fclose.o _fill.o fread.o ftell.o lseek.o puts.o setbuffe.o tmpfile.o \
      clearerr.o fcntl.o flushall.o freopen.o ftruncat.o mktemp.o read.o setmode.o truncate.o \
      close.o fdopen.o _flush.o fscanf.o fwrite.o _newstre.o remove.o setvbuf.o ungetc.o \
      creat.o fflush.o _fopen.o fseek.o gets.o open.o rename.o sprintf.o unlink.o \
      _crlf.o fgetc.o fopen.o _fseekhd.o _input.o _output.o rewind.o sscanf.o vfprintf.o \
      dup.o fgetchar.o fprintf.o _fsetmod.o ioctl.o pclose.o rmtmp.o stat.o vprintf.o \
      eof.o fgetpos.o fputc.o fsetpos.o _iodata.o pipe.o scanf.o stdio.o vsprintf.o

CFLAGS = -O0 -ggdb3 -fno-builtin -fno-stack-protector -nostdinc -I../../include

CC = i586-linux-gcc


io.a: $(OBJ)
	i586-linux-ar cru io.a $(OBJ)
	i586-linux-ranlib io.a
	i586-linux-size io.a


clean:
	@rm -f $(OBJ)
	@rm -f io.a
