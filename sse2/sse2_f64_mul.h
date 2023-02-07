#ifndef SSE2_F64_MUL_H
#define SSE2_F64_MUL_H

#include <emmintrin.h>
#include "sse2.h"
#include "../rdtsc.h"

static __inline__ double sse2_f64_mul(unsigned int iter)
{
    __m128d c0 = _mm_set1_pd(1.4142135623730950488f);
    __m128d c1 = _mm_set1_pd(1.6422289836162283477f);

    __m128d v0 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v1 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v2 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v3 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v4 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v5 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v6 = _mm_set1_pd((double)(rdtsc() % 256));
    __m128d v7 = _mm_set1_pd((double)(rdtsc() % 256));

    while (iter--) {
        v0 = _mm_mul_pd(v0, c0);
        v1 = _mm_mul_pd(v1, c0);
        v2 = _mm_mul_pd(v2, c0);
        v3 = _mm_mul_pd(v3, c0);
        v4 = _mm_mul_pd(v4, c0);
        v5 = _mm_mul_pd(v5, c0);
        v6 = _mm_mul_pd(v6, c0);
        v7 = _mm_mul_pd(v7, c0);

        v0 = _mm_mul_pd(v0, c1);
        v1 = _mm_mul_pd(v1, c1);
        v2 = _mm_mul_pd(v2, c1);
        v3 = _mm_mul_pd(v3, c1);
        v4 = _mm_mul_pd(v4, c1);
        v5 = _mm_mul_pd(v5, c1);
        v6 = _mm_mul_pd(v6, c1);
        v7 = _mm_mul_pd(v7, c1);

        v0 = _mm_mul_pd(v0, c0);
        v1 = _mm_mul_pd(v1, c0);
        v2 = _mm_mul_pd(v2, c0);
        v3 = _mm_mul_pd(v3, c0);
        v4 = _mm_mul_pd(v4, c0);
        v5 = _mm_mul_pd(v5, c0);
        v6 = _mm_mul_pd(v6, c0);
        v7 = _mm_mul_pd(v7, c0);

        v0 = _mm_mul_pd(v0, c1);
        v1 = _mm_mul_pd(v1, c1);
        v2 = _mm_mul_pd(v2, c1);
        v3 = _mm_mul_pd(v3, c1);
        v4 = _mm_mul_pd(v4, c1);
        v5 = _mm_mul_pd(v5, c1);
        v6 = _mm_mul_pd(v6, c1);
        v7 = _mm_mul_pd(v7, c1);
    }

    v0 = _mm_add_pd(v0, v1);
    v1 = _mm_add_pd(v1, v2);
    v2 = _mm_add_pd(v2, v3);
    v3 = _mm_add_pd(v3, v4);
    v4 = _mm_add_pd(v4, v5);
    v5 = _mm_add_pd(v5, v6);
    v6 = _mm_add_pd(v6, v7);
    v7 = _mm_add_pd(v7, v0);

    return sse2_f64_reduce(v0);
}

#endif
