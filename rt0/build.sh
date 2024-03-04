#!/bin/bash
# i586-linux-gcc -Os -Wall -std=gnu99 -pedantic -nostdlib -fomit-frame-pointer -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -mfpmath=sse -mfancy-math-387 -ffunction-sections -fdata-sections -Wl,--gc-sections -c hi.c
i586-linux-gcc -Os -Wall -std=gnu99 -pedantic -nostdlib -fomit-frame-pointer -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -mfpmath=sse -mfancy-math-387 -ffunction-sections -fdata-sections -Wl,--gc-sections -c src/lib/00_start.c  -Iinclude
i586-linux-gcc -Os -Wall -std=gnu99 -pedantic -nostdlib -fomit-frame-pointer -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -mfpmath=sse -mfancy-math-387 -ffunction-sections -fdata-sections -Wl,--gc-sections -c src/lib/_exit.c  -Iinclude
i586-linux-gcc -Os -Wall -std=gnu99 -pedantic -nostdlib -fomit-frame-pointer -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -mfpmath=sse -mfancy-math-387 -ffunction-sections -fdata-sections -Wl,--gc-sections -c src/lib/syscall.c -Iinclude

i586-linux-gcc -nostdlib -fno-builtin -c hi.c

i586-linux-ld --as-needed -dynamic-linker /lib/ld-linux.so.2 -pie -m elf_i386 00_start.o syscall.o _exit.o hi.o  -lc -o hi

