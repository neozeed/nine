OBJ = bcmp.o memccpy.o memmove.o strchr.o strdup.o strlwr.o strnicmp.o strrev.o strtok.o \
      bcopy.o memcmp.o memset.o strcmp.o strerror.o strncat.o strnset.o strset.o strupr.o \
      bzero.o memcpy.o rindex.o strcpy.o stricmp.o strncmp.o strpbrk.o strspn.o \
      index.o memicmp.o strcat.o strcspn.o strlen.o strncpy.o strrchr.o strstr.o memchr.o

CFLAGS = -ggdb3 -O0 -fno-stack-protector -fno-builtin -nostdinc -I../../include

CC = i586-linux-gcc


str.a: $(OBJ)
	i586-linux-ar cru str.a $(OBJ)
	i586-linux-ranlib str.a
	i586-linux-size str.a


clean:
	@rm -f $(OBJ)
	@rm -f str.a
