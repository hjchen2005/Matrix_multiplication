#ifndef matrix_multiplication_dpps_h
#define matrix_multiplication_dpps_h

#include <smmintrin.h>

const int size= 4;

void matrix_multiplication_dpps(float A[size][size], float B[size][size], float S[size][size]);

void matrix_multiplication_dpps(float A[size][size], float B[size][size], float S[size][size]){
    const int mask = 0x1F;
    __m128 v1 = { 3, 2, 3, 2 }, v2 = { 2, 3, 2, 3 },
    v3 = { 3, 2, 3, 2 }, v4 = { 2, 3, 2, 3 }, s = { 0.0, 0.0, 0.0, 0.0 };
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k += 8) {
                v1 = _mm_set_ps(A[i][k], A[i][k + 1], A[i][k + 2], A[i][k + 3]);
                v2 = _mm_set_ps(A[i][k + 4], A[i][k + 5], A[i][k + 6], A[i][k + 7]);
                v3 = _mm_set_ps(B[i][k], B[i][k + 1], B[i][k + 2], B[i][k + 3]);
                v4 = _mm_set_ps(B[i][k + 4], B[i][k + 5], B[i][k + 6], B[i][k + 7]);
                s = _mm_dp_ps(v1, v3, mask);
                S[i][j] += s.m128_f32[0] + s.m128_f32[1] + s.m128_f32[2] + s.m128_f32[3];
                s = _mm_dp_ps(v2, v4, mask);
                S[i][j] += s.m128_f32[0] + s.m128_f32[1] + s.m128_f32[2] + s.m128_f32[3];
            }
            
        }
        
    }
    
}

#endif
