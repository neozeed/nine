// from https://gist.github.com/lunixbochs/462ee21c3353c56b910f
// //
// #include <sys/syscall.h>

void _start() {
    __asm__ __volatile__ (
         "pop %ebp;" // C compiler will push rbp
         "pop %edi;"        // argc
         "mov %esp, %esi;" // argv
         "andl $-8, %esp;"
         "call main;"
    );
}

