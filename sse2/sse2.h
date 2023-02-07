#ifndef SSE2_H
#define SSE2_H

#include <emmintrin.h>

static __inline__ double sse2_f64_reduce(__m128d x)
{
    __m128d s = _mm_set1_pd(32);
    __m128d a = _mm_add_pd(x, s);
    __m128d m = _mm_unpackhi_pd(x, a);

    return (double)m[0];
}

#endif
