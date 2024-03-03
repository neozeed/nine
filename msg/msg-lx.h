/**
 * 2ine; an OS/2 emulator for Linux.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 */

/* THIS FILE IS AUTOGENERATED. DO NOT EDIT BY HAND. see lxapigen.pl */

/* This is glue code for OS/2 binaries. Native binaries don't need this. */
#if LX_LEGACY

static APIRET16 bridge16to32_Dos16PutMessage(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PCHAR, pBuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cbMsg);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, hfile);
    return Dos16PutMessage(hfile, cbMsg, pBuf);
}

static APIRET16 bridge16to32_Dos16TrueGetMessage(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, msgseg);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcbMsg);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PCHAR, pFilename);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, msgnum);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cbBuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PCHAR, pData);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cTable);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, pTable);
    return Dos16TrueGetMessage(pTable, cTable, pData, cbBuf, msgnum, pFilename, pcbMsg, msgseg);
}

LX_NATIVE_MODULE_16BIT_SUPPORT()
    LX_NATIVE_MODULE_16BIT_API(Dos16PutMessage)
    LX_NATIVE_MODULE_16BIT_API(Dos16TrueGetMessage)
LX_NATIVE_MODULE_16BIT_SUPPORT_END()

LX_NATIVE_MODULE_DEINIT({
    LX_NATIVE_MODULE_DEINIT_16BIT_SUPPORT();
})

static int init16_msg(void) {
    LX_NATIVE_MODULE_INIT_16BIT_SUPPORT()
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16PutMessage, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16TrueGetMessage, 26)
    LX_NATIVE_MODULE_INIT_16BIT_SUPPORT_END()
    return 1;
}

LX_NATIVE_MODULE_INIT({ if (!init16_msg()) return 0; })
    LX_NATIVE_EXPORT16_DIFFERENT_NAME(Dos16PutMessage, "DOSPUTMESSAGE", 1),
    LX_NATIVE_EXPORT16_DIFFERENT_NAME(Dos16TrueGetMessage, "DOSTRUEGETMESSAGE", 2),
    LX_NATIVE_EXPORT(DosPutMessage, 5),
    LX_NATIVE_EXPORT(DosTrueGetMessage, 6)
LX_NATIVE_MODULE_INIT_END()

#endif /* LX_LEGACY */

/* end of msg-lx.h ... */

