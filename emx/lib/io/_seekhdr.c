/* _seekhdr.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */

#include <io.h>
#include <memory.h>

int _seek_hdr (int handle)
    {
    struct
        {
        char magic[2];
        char fill1[6];
        unsigned short hdr_size;
        } exe_hdr;
    struct
        {
        char sig[16];
        char bound;
        char fill1;
        unsigned short hdr_loc_lo;      /* cannot use long, alignment! */
        unsigned short hdr_loc_hi;
        } patch;
    long original_pos;

    original_pos = tell (handle);
    if (read (handle, &exe_hdr, sizeof (exe_hdr)) != sizeof (exe_hdr))
        goto failure;
    if (memcmp (exe_hdr.magic, "MZ", 2) != 0)
        return (lseek (handle, original_pos, SEEK_SET) == -1 ? -1 : 0);
    if (lseek (handle, original_pos + 16 * exe_hdr.hdr_size, SEEK_SET) == -1)
        goto failure;
    if (read (handle, &patch, sizeof (patch)) != sizeof (patch))
        goto failure;
    if (memcmp (patch.sig, "emx", 3) != 0)
        goto failure;
    if (lseek (handle, original_pos + patch.hdr_loc_lo
                                + 65536L * patch.hdr_loc_hi, SEEK_SET) == -1)
        goto failure;
    return (0);

failure:
    (void)lseek (handle, original_pos, SEEK_SET);
    return (-1);
    }
