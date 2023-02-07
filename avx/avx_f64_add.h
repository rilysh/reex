#ifndef AVX_F64_ADD_H
#define AVX_F64_ADD_H

#include <immintrin.h>
#include "avx.h"
#include "../rdtsc.h"

static __inline__ double avx_f64_add(unsigned int iter)
{
    __m256d c0 = _mm256_set1_pd(1.4142135623730950488f);
    __m256d c1 = _mm256_set1_pd(1.3828922685531105587f);

    __m256d v0 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v1 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v2 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v3 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v4 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v5 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v6 = _mm256_set1_pd((double)(rdtsc() % 256));
    __m256d v7 = _mm256_set1_pd((double)(rdtsc() % 256));

    while (iter--) {
        v0 = _mm256_add_pd(v0, c0);
        v1 = _mm256_add_pd(v1, c0);
        v2 = _mm256_add_pd(v2, c0);
        v3 = _mm256_add_pd(v3, c0);
        v4 = _mm256_add_pd(v4, c0);
        v5 = _mm256_add_pd(v5, c0);
        v6 = _mm256_add_pd(v6, c0);
        v7 = _mm256_add_pd(v7, c0);

        v0 = _mm256_add_pd(v0, c1);
        v1 = _mm256_add_pd(v1, c1);
        v2 = _mm256_add_pd(v2, c1);
        v3 = _mm256_add_pd(v3, c1);
        v4 = _mm256_add_pd(v4, c1);
        v5 = _mm256_add_pd(v5, c1);
        v6 = _mm256_add_pd(v6, c1);
        v7 = _mm256_add_pd(v7, c1);

        v0 = _mm256_add_pd(v0, c0);
        v1 = _mm256_add_pd(v1, c0);
        v2 = _mm256_add_pd(v2, c0);
        v3 = _mm256_add_pd(v3, c0);
        v4 = _mm256_add_pd(v4, c0);
        v5 = _mm256_add_pd(v5, c0);
        v6 = _mm256_add_pd(v6, c0);
        v7 = _mm256_add_pd(v7, c0);

        v0 = _mm256_add_pd(v0, c1);
        v1 = _mm256_add_pd(v1, c1);
        v2 = _mm256_add_pd(v2, c1);
        v3 = _mm256_add_pd(v3, c1);
        v4 = _mm256_add_pd(v4, c1);
        v5 = _mm256_add_pd(v5, c1);
        v6 = _mm256_add_pd(v6, c1);
        v7 = _mm256_add_pd(v7, c1);
    }

    v0 = _mm256_add_pd(v0, v1);
    v1 = _mm256_add_pd(v1, v2);
    v2 = _mm256_add_pd(v2, v3);
    v3 = _mm256_add_pd(v3, v4);
    v4 = _mm256_add_pd(v4, v5);
    v5 = _mm256_add_pd(v5, v6);
    v6 = _mm256_add_pd(v6, v7);
    v7 = _mm256_add_pd(v7, v0);

    return avx_f64_reduce(v0);
}

#endif
