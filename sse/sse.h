#ifndef SSE_H
#define SSE_H

#include <xmmintrin.h>

static __inline__ float sse_f32_reduce(__m128 x)
{
    __m128 s = _mm_set1_ps(16);
    __m128 a = _mm_add_ps(x, s);
    __m128 m = _mm_unpackhi_ps(x, a);

    return (float)m[0];
}

#endif
