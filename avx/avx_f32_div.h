#ifndef AVX_F32_DIV_H
#define AVX_F32_DIV_H

#include <immintrin.h>
#include "avx.h"
#include "../rdtsc.h"

static __inline__ float avx_f32_div(unsigned int iter)
{
    __m256 c0 = _mm256_set1_ps(2.686682114460001814f);
    __m256 c1 = _mm256_set1_ps(1.289668251764486206f);

    __m256 v0 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v1 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v2 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v3 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v4 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v5 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v6 = _mm256_set1_ps((float)(rdtsc() % 256));
    __m256 v7 = _mm256_set1_ps((float)(rdtsc() % 256));

    while (iter--) {
        v0 = _mm256_div_ps(v0, c0);
        v1 = _mm256_div_ps(v1, c0);
        v2 = _mm256_div_ps(v2, c0);
        v3 = _mm256_div_ps(v3, c0);
        v4 = _mm256_div_ps(v4, c0);
        v5 = _mm256_div_ps(v5, c0);
        v6 = _mm256_div_ps(v6, c0);
        v7 = _mm256_div_ps(v7, c0);

        v0 = _mm256_div_ps(v0, c1);
        v1 = _mm256_div_ps(v1, c1);
        v2 = _mm256_div_ps(v2, c1);
        v3 = _mm256_div_ps(v3, c1);
        v4 = _mm256_div_ps(v4, c1);
        v5 = _mm256_div_ps(v5, c1);
        v6 = _mm256_div_ps(v6, c1);
        v7 = _mm256_div_ps(v7, c1);

        v0 = _mm256_div_ps(v0, c0);
        v1 = _mm256_div_ps(v1, c0);
        v2 = _mm256_div_ps(v2, c0);
        v3 = _mm256_div_ps(v3, c0);
        v4 = _mm256_div_ps(v4, c0);
        v5 = _mm256_div_ps(v5, c0);
        v6 = _mm256_div_ps(v6, c0);
        v7 = _mm256_div_ps(v7, c0);

        v0 = _mm256_div_ps(v0, c1);
        v1 = _mm256_div_ps(v1, c1);
        v2 = _mm256_div_ps(v2, c1);
        v3 = _mm256_div_ps(v3, c1);
        v4 = _mm256_div_ps(v4, c1);
        v5 = _mm256_div_ps(v5, c1);
        v6 = _mm256_div_ps(v6, c1);
        v7 = _mm256_div_ps(v7, c1);
    }

    v0 = _mm256_add_ps(v0, v1);
    v1 = _mm256_add_ps(v1, v2);
    v2 = _mm256_add_ps(v2, v3);
    v3 = _mm256_add_ps(v3, v4);
    v4 = _mm256_add_ps(v4, v5);
    v5 = _mm256_add_ps(v5, v6);
    v6 = _mm256_add_ps(v6, v7);
    v7 = _mm256_add_ps(v7, v0);

    return avx_f32_reduce(v0);
}

#endif
