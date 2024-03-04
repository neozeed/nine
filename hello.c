#define INCL_DOS
#include <os2.h>

#include <dlfcn.h>


APIRET (*zDosPutMessage)(HFILE hfile, ULONG cbMsg, PCHAR pBuf) OS2APIINFO(5);
int main(void)
{
	void *handle;
	void *handle2;
	handle=dlopen("dll/lib2ine.so",RTLD_NOW|RTLD_GLOBAL);
	handle2=dlopen("dll/msg.so",RTLD_NOW|RTLD_LOCAL);
	*(void **) (&zDosPutMessage) = dlsym(handle2, "DosPutMessage");

    printf("should error1");
    zDosPutMessage(1, 32, "Hello from a native OS/2 .exe!\r\n");
    printf("should error2");
    return 0;
}
