#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* GCC builtin replacement: full memory barrier */
void __sync_synchronize(void)
{
    MemoryBarrier();
}

/* GCC builtin replacement: atomic fetch-and-add, return old value */
int __sync_fetch_and_add(int* ptr, int value)
{
    return InterlockedExchangeAdd((volatile LONG*)ptr, (LONG)value);
}

/* GNU asprintf replacement for MSVC */
int asprintf(char** strp, const char* fmt, ...)
{
    int len;
    va_list ap;

    if (!strp || !fmt) {
        return -1;
    }

    va_start(ap, fmt);
    len = _vscprintf(fmt, ap);  /* count without writing */
    va_end(ap);

    if (len < 0) {
        *strp = NULL;
        return -1;
    }

    *strp = (char*)malloc((size_t)len + 1);
    if (!*strp) {
        return -1;
    }

    va_start(ap, fmt);
    if (vsnprintf(*strp, (size_t)len + 1, fmt, ap) < 0) {
        va_end(ap);
        free(*strp);
        *strp = NULL;
        return -1;
    }
    va_end(ap);

    return len;  /* chars written, not counting terminator */
}

#endif /* _MSC_VER */
