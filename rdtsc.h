#ifndef RDTSC_H
#define RDTSC_H

#if defined i386 || defined __i386__ || defined __i386
/**
 * https://www.mcs.anl.gov/~kazutomo/rdtsc.html
 * TL;DR: Don't use this unless you got a 32-bit only CPU, targetting Pentium.
*/
    #error "32-bit platforms are not supported"
#elif defined __x86_64__

static __inline__ unsigned long long rdtsc()
{
    unsigned int a, d;
    __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

    /** Shifting 32-bits for GCC */
    return ((unsigned long long)d << 32) | a;
}

#endif

#endif
