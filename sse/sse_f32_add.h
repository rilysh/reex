#ifndef SSE_F32_ADD_H
#define SSE_F32_ADD_H

#include <xmmintrin.h>
#include "sse.h"
#include "../rdtsc.h"

static __inline__ float sse_f32_add(unsigned int iter)
{
    __m128 c0 = _mm_set1_ps(1.4142135623730950488f);
    __m128 c1 = _mm_set1_ps(1.3828922685531105587f);

    __m128 v0 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v1 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v2 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v3 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v4 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v5 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v6 = _mm_set1_ps((float)(rdtsc() % 256));
    __m128 v7 = _mm_set1_ps((float)(rdtsc() % 256));

    while (iter--) {
        v0 = _mm_add_ps(v0, c0);
        v1 = _mm_add_ps(v1, c0);
        v2 = _mm_add_ps(v2, c0);
        v3 = _mm_add_ps(v3, c0);
        v4 = _mm_add_ps(v4, c0);
        v5 = _mm_add_ps(v5, c0);
        v6 = _mm_add_ps(v6, c0);
        v7 = _mm_add_ps(v7, c0);

        v0 = _mm_add_ps(v0, c1);
        v1 = _mm_add_ps(v1, c1);
        v2 = _mm_add_ps(v2, c1);
        v3 = _mm_add_ps(v3, c1);
        v4 = _mm_add_ps(v4, c1);
        v5 = _mm_add_ps(v5, c1);
        v6 = _mm_add_ps(v6, c1);
        v7 = _mm_add_ps(v7, c1);

        v0 = _mm_add_ps(v0, c0);
        v1 = _mm_add_ps(v1, c0);
        v2 = _mm_add_ps(v2, c0);
        v3 = _mm_add_ps(v3, c0);
        v4 = _mm_add_ps(v4, c0);
        v5 = _mm_add_ps(v5, c0);
        v6 = _mm_add_ps(v6, c0);
        v7 = _mm_add_ps(v7, c0);

        v0 = _mm_add_ps(v0, c1);
        v1 = _mm_add_ps(v1, c1);
        v2 = _mm_add_ps(v2, c1);
        v3 = _mm_add_ps(v3, c1);
        v4 = _mm_add_ps(v4, c1);
        v5 = _mm_add_ps(v5, c1);
        v6 = _mm_add_ps(v6, c1);
        v7 = _mm_add_ps(v7, c1);
    }

    v0 = _mm_add_ps(v0, v1);
    v1 = _mm_add_ps(v1, v2);
    v2 = _mm_add_ps(v2, v3);
    v3 = _mm_add_ps(v3, v4);
    v4 = _mm_add_ps(v4, v5);
    v5 = _mm_add_ps(v5, v6);
    v6 = _mm_add_ps(v6, v7);
    v7 = _mm_add_ps(v7, v0);

    return sse_f32_reduce(v0);
}

#endif
