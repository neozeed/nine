// from https://gist.github.com/lunixbochs/462ee21c3353c56b910f
//
#include <sys/syscall.h>

#define sysdef(name)               \
    int name() {                   \
        __asm__ __volatile__(      \
            "movq %0, %%rax;"      \
            "mov %%rcx, %%r10;"    \
            "syscall;"             \
            :: "i"(SYS_##name) : "rax" \
        );                         \
    }

void _start() {
    __asm__ __volatile__ (
         "pop %%rbp;" // C compiler will push rbp
         "pop %%rdi;"        // argc
         "mov %%rsp, %%rsi;" // argv
         "andq $-16, %%rsp;"
         "call main;"
         "movq %%rax, %%rdi;" // exit
         "movq %0, %%rax;"
         "syscall;"
         :: "i"(SYS_exit)
    );
}

