OBJ = abort.o atol.o _defext.o getcwd.o itoa.o _path.o qsort.o spawnv.o syserr.o wait.o \
	alarm.o bsearch.o difftime.o getenv.o localtim.o perror.o rand.o spawnve.o system.o _wildcar.o \
	asctime.o calloc.o dirent.o getopt.o ltoa.o prtc.o realloc.o spawnvp.o time.o \
	_assert.o chdir.o execve.o getpages.o malloc.o prti.o _respons.o spawnvpe.o times.o \
	atexit.o clock.o exit.o getuid.o mkdir.o prts.o rmdir.o _startup.o ulimit.o \
	atof.o ctime.o _expand.o gmtime.o mktime.o putenv.o _searche.o strtod.o ultoa.o\
	atoi.o ctype.o free.o heapchk.o _msize.o pwd.o sleep.o strtol.o utimes.o

CFLAGS = -nostdinc -I../../include

CC = i586-linux-gcc


misc.a: $(OBJ)
	i586-linux-ar cru misc.a $(OBJ)
	i586-linux-ranlib misc.a
	i586-linux-size misc.a


clean:
	@rm -f $(OBJ)
	@rm -f misc.a
