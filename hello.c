#define INCL_DOS
#include <os2.h>

int main(void)
{
    DosPutMessage(1, 32, "Hello from a native OS/2 .exe!\r\n");
    return 0;
}
