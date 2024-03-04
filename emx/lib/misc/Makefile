OBJ = abort.o calloc.o _defext.o _fullpat.o getuid.o mkdir.o putenv.o sbrk.o spawnv.o system.o \
      alarm.o _chdir2.o difftime.o _getcwd1.o gmtime.o mktime.o pwd.o _scrsize.o spawnve.o time.o \
      asctime.o chdir.o dirent.o _getcwd2.o heapchk.o _msize.o qsort.o _searche.o spawnvp.o times.o \
      _assert.o _chdrive.o execve.o getcwd.o itoa.o _path.o raise.o signal.o spawnvpe.o ulimit.o \
      atexit.o _cleanup.o exit.o _getdriv.o kill.o perror.o rand.o sleep.o _startup.o ultoa.o \
      atof.o clock.o _expand.o getenv.o localtim.o prtc.o _readkbd.o spawnl.o strtod.o umask.o \
      atoi.o _core.o _fngetdr.o getopt.o ltoa.o prti.o realloc.o spawnle.o strtol.o utimes.o \
      atol.o ctime.o free.o getpages.o _main.o prts.o _respons.o spawnlp.o _swchar.o wait.o \
      bsearch.o ctype.o ftime.o getpid.o malloc.o ptrace.o rmdir.o spawnlpe.o syserr.o _wildcar.o

CFLAGS = -ggdb3 -O0 -fno-stack-protector -fno-builtin -nostdinc -I../../include

CC = i586-linux-gcc


misc.a: $(OBJ)
	i586-linux-ar cru misc.a $(OBJ)
	i586-linux-ranlib misc.a
	i586-linux-size misc.a


clean:
	@rm -f $(OBJ)
	@rm -f misc.a
