#if defined(i386) || defined(__i386__) || defined( __i386)
    /**
     * For instance, if the CPU only support 32-bit instruction set/
     * We don't know, so we'll completely drop it.
    */
    #error "32-bit platforms are not supported"
#endif

#if !defined(__AVX__)
    #warning "AVX instruction isn't supported on this platform"
#elif !defined(__SSE2__)
    #error "SSE2 SIMD isn't supported on this platform"
#elif !defined(__SSE__)
    #error "SSE SIMD isn't supported on this platform"
#endif

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

#include "reex.h"

#ifdef PROG_VERSION
#undef PROG_VERSION
#define PROG_VERSION    "0.1"
#else
#define PROG_VERSION    "0.1"
#endif

static unsigned int iter = 98352000;

static void show_help(void)
{
    fprintf(stdout,
        "reex - v%s\n"
        "Stress test your CPU, a little bit more...\n\n"
        "Commands:\n"
        "   --avx-sp    -- AVX single-precision floating point\n"
        "   --avx-dp    -- AVX double-precision floating point\n"
        "   --sse-sp    -- SSE single-precision floating point\n"
        "   --sse2-dp   -- SSE2 double-precision floating point\n"
        "   --eall      -- All of above in a never-ending loop\n"
    , PROG_VERSION);
}

static void avx_unsuppoted_err(void)
{
    fprintf(stderr,
        "Error: AVX isn't enabled, if your CPU supports AVX, "
        "please add #define AVX_ENABLE at the top of reex.c\n"
    );
    exit(EXIT_FAILURE);
}

static void caught_sigint(/** Avoid void for signal */)
{
    fprintf(stderr, "\nCaught SIGINT, exiting...\n");
    exit(EXIT_FAILURE);
}

static double multi_thread_attach(void *fn, unsigned int iter)
{
    clock_t start, end;
    double diff;
    long onln_cores = sysconf(_SC_NPROCESSORS_ONLN); 

    pthread_t threads[onln_cores];
    int i;

    start = clock();

    for (i = 0; i < onln_cores; i++) {
        if (pthread_create(&threads[i], NULL, fn, (void *)(unsigned long int)iter) != 0)
            perror("pthread_create():");
    }

    for (i = 0; i < onln_cores; i++) {
        if (pthread_join(threads[i], NULL) != 0)
            perror("pthread_join():");
    }

    for (i = 0; i < onln_cores; i++) {
        if (pthread_cancel(threads[i]) != 0)
            perror("pthread_cancel():");
    }

    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;

    return diff;
}

#ifdef AVX_ENABLE

static void avx_sp(void)
{
    double sp_add, sp_sub, sp_mul, sp_div;
    
    sp_add = multi_thread_attach((void * (*)(void *))avx_f32_add, iter);
    sp_sub = multi_thread_attach((void * (*)(void *))avx_f32_sub, iter);
    sp_mul = multi_thread_attach((void * (*)(void *))avx_f32_mul, iter);
    sp_div = multi_thread_attach((void * (*)(void *))avx_f32_div, iter);

    fprintf(stdout,
        "AVX single-precision\n"
        "   Addition: %.3fs\n"
        "   Substraction: %.3fs\n"
        "   Multiplication: %.3fs\n"
        "   Division: %.3fs\n\n",
        sp_add, sp_sub, sp_mul, sp_div
    );
}

static void avx_dp(void)
{
    double dp_add, dp_sub, dp_mul, dp_div;

    dp_add = multi_thread_attach((void * (*)(void *))avx_f64_add, iter);
    dp_sub = multi_thread_attach((void * (*)(void *))avx_f64_sub, iter);
    dp_mul = multi_thread_attach((void * (*)(void *))avx_f64_mul, iter);
    dp_div = multi_thread_attach((void * (*)(void *))avx_f64_div, iter);

    fprintf(stdout,
        "AVX double-precision\n"
        "   Addition: %.3fs\n"
        "   Substraction: %.3fs\n"
        "   Multiplication: %.3fs\n"
        "   Division: %.3fs\n\n",
        dp_add, dp_sub, dp_mul, dp_div
    );
}

#endif

static void sse_sp(void)
{
    double sp_add, sp_sub, sp_mul, sp_div;

    sp_add = multi_thread_attach((void * (*)(void *))sse_f32_add, iter);
    sp_sub = multi_thread_attach((void * (*)(void *))sse_f32_sub, iter);
    sp_mul = multi_thread_attach((void * (*)(void *))sse_f32_mul, iter);
    sp_div = multi_thread_attach((void * (*)(void *))sse_f32_div, iter);

    fprintf(stdout,
        "SSE single-precision\n"
        "   Addition: %.3fs\n"
        "   Substraction: %.3fs\n"
        "   Multiplication: %.3fs\n"
        "   Division: %.3fs\n\n",
        sp_add, sp_sub, sp_mul, sp_div
    );
}

static void sse2_dp(void)
{
    double dp_add, dp_sub, dp_mul, dp_div;

    dp_add = multi_thread_attach((void * (*)(void *))sse2_f64_add, iter);
    dp_sub = multi_thread_attach((void * (*)(void *))sse2_f64_sub, iter);
    dp_mul = multi_thread_attach((void * (*)(void *))sse2_f64_mul, iter);
    dp_div = multi_thread_attach((void * (*)(void *))sse2_f64_div, iter);

    fprintf(stdout,
        "SSE2 double-precision\n"
        "   Addition: %.3fs\n"
        "   Substraction: %.3fs\n"
        "   Multiplication: %.3fs\n"
        "   Division: %.3fs\n\n",
        dp_add, dp_sub, dp_mul, dp_div
    );
}

#ifdef AVX_ENABLE

static void mix_avx_sp(void)
{
    double all;

    all = multi_thread_attach((void * (*)(void *))avx_f32_mix, iter);

    fprintf(stdout,
        "AVX single-precision - add, sub, mul, div\n"
        "All took: %.3fs\n",
        all
    );
}

static void mix_avx_dp(void)
{
    double all;

    all = multi_thread_attach((void * (*)(void *))avx_f64_mix, iter);

    fprintf(stdout,
        "AVX double-precision - add, sub, mul, div\n"
        "All took: %.3fs\n",
        all
    );
}

#endif

static void mix_sse_sp(void)
{
    double all;

    all = multi_thread_attach((void * (*)(void *))sse_f32_mix, iter);

    fprintf(stdout,
        "SSE single-precision - add, sub, mul, div\n"
        "All took: %.3fs\n",
        all
    );
}

static void mix_sse2_dp(void)
{
    double all;

    all = multi_thread_attach((void * (*)(void *))sse2_f64_mix, iter);

    fprintf(stdout,
        "SSE2 double-precision - add, sub, mul, div\n"
        "All took: %.3fs\n",
        all
    );
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        show_help();
        exit(EXIT_FAILURE);
    }

    clock_t start, end;
    long onln_cores = sysconf(_SC_NPROCESSORS_ONLN);

    signal(SIGINT, caught_sigint);

    fprintf(stdout, "Running [%d] with %ld logical core(s)\n", getpid(), onln_cores);

    if (!strcmp(argv[1], "--avx-sp")) {
        #ifdef AVX_ENABLE
        avx_sp();
        #else
        avx_unsuppoted_err();
        #endif
    } else if (!strcmp(argv[1], "--avx-dp")) {
        #ifdef AVX_ENABLE
        avx_dp();
        #else
        avx_unsuppoted_err();
        #endif
    } else if (!strcmp(argv[1], "--sse-sp")) {
        sse_sp();
    } else if (!strcmp(argv[1], "--sse2-dp")) {
		sse2_dp();
    } else if (!strcmp(argv[1], "--mix-avx-sp")) {
        #ifdef AVX_ENABLE
        mix_avx_sp();
        #else
        avx_unsuppoted_err();
        #endif
    } else if (!strcmp(argv[1], "--mix-avx-dp")) {
        #ifdef AVX_ENABLE
        mix_avx_dp();
        #else
        avx_unsuppoted_err();
        #endif
    } else if (!strcmp(argv[1], "--mix-sse-sp")) {
        mix_sse_sp();
    } else if (!strcmp(argv[1], "--mix-sse2-dp")) {
        mix_sse2_dp();
    } else if (!strcmp(argv[1], "--eall")) {
        for (;;) {
            #ifdef AVX_ENABLE
            avx_sp();
            avx_dp();
            mix_avx_sp();
            mix_avx_dp();
            #endif
            sse_sp();
            mix_sse_sp();
            sse2_dp();
            mix_sse2_dp();
        }
    } else {
        show_help();
        exit(EXIT_SUCCESS);
    }

    pthread_exit(EXIT_SUCCESS);
}
