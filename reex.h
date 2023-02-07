#ifndef REEX_H
#define REEX_H

#ifdef AVX_ENABLE
    #include "avx/avx_f32_add.h"
    #include "avx/avx_f32_sub.h"
    #include "avx/avx_f32_mul.h"
    #include "avx/avx_f32_div.h"
    #include "avx/avx_f64_add.h"
    #include "avx/avx_f64_sub.h"
    #include "avx/avx_f64_mul.h"
    #include "avx/avx_f64_div.h"
    #include "avx/avx_f32_mix.h"
    #include "avx/avx_f64_mix.h"
#endif

#include "sse/sse_f32_add.h"
#include "sse/sse_f32_sub.h"
#include "sse/sse_f32_mul.h"
#include "sse/sse_f32_div.h"
#include "sse/sse_f32_mix.h"

#include "sse2/sse2_f64_add.h"
#include "sse2/sse2_f64_sub.h"
#include "sse2/sse2_f64_mul.h"
#include "sse2/sse2_f64_div.h"
#include "sse2/sse2_f64_mix.h"

#endif
