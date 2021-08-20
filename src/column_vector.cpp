#include <cstdint>
#include <immintrin.h>
void filter_simd_avx2(const int32_t* __restrict in, int32_t* __restrict out, int32_t threshold, size_t count) {
    __m256i thresh = _mm256_set1_epi32(threshold);
    for (size_t i = 0; i < count; i += 8) {
        __m256i v = _mm256_loadu_si256((__m256i*)(in + i));
        __m256i mask = _mm256_cmpgt_epi32(v, thresh);
        _mm256_storeu_si256((__m256i*)(out + i), mask);
    }
}
