#ifndef AVX_H
#define AVX_H

#include <immintrin.h>

static __inline__ float avx_f32_reduce(__m256 x)
{
    __m128 c = _mm256_castps256_ps128(x);
    __m128 e = _mm256_extractf128_ps(x, 1);
    __m128 m = _mm_add_ps(c, e);
    __m128 s0 = _mm_shuffle_ps(m, m, 14);
    __m128 s1 = _mm_shuffle_ps(m, m, 1);

    m = _mm_add_ps(m, s0);
    m = _mm_add_ps(m, s1);

    return (float)m[0];
}

static __inline__ double avx_f64_reduce(__m256d x)
{
    __m128d c = _mm256_castpd256_pd128(x);
    __m128d e = _mm256_extractf128_pd(x, 1);
    __m128d m = _mm_add_pd(c, e);
    __m128d h = _mm_unpackhi_pd(m, m);
    
    m = _mm_add_pd(m, h);

    return (double)m[0];
}

#endif
