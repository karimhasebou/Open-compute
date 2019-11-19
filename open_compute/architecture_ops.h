//
//  architecture_ops.h
//  open_compute
//
//  Created by Karim Hasebou on 11/18/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef architecture_ops_h
#define architecture_ops_h

#ifndef __ARCH_H__
#define __ARCH_H__
/** defines macros for abstracting architecture specific SIMD operations
 */

#if defined(__ARMV7__) || defined(__ARMV8__)
    #include "arm_neon.h"
    
    typedef  float32x4_t  SIMD_vec_ps ;

#ifdef __ARMV7__
    inline float32x4_t vdivq_f32(float32x4_t x, float32x4_t y){
        float32x4_t reciprocal = vrecpeq_f32(y);
        reciprocal = vmulq_f32(vrecpsq_f32(y, reciprocal), reciprocal);
        return vmulq_f32(x,reciprocal);
    }
#endif

    #define SIMD_num_float 4
    #define SIMD_array_align 16
    #define SIMD_loadu_ps(x) vld1q_f32(x)
    #define SIMD_load_ps(x) vld1q_f32(x)
    #define SIMD_store_ps(x,y) vst1q_f32(x, y)
    #define SIMD_storeu_ps(x, y) vst1q_f32(x, y)
    #define SIMD_set1_ps(x) vdupq_n_f32(x)
    #define SIMD_max_ps(x, y) vmaxq_f32(x, y)
    #define SIMD_add_ps(x, y) vaddq_f32(x, y)
    #define SIMD_sub_ps(x, y) vsubq_f32(x, y)
    #define SIMD_mul_ps(x, y) vmulq_f32(x, y)
    #define SIMD_div_ps(x, y) vdivq_f32 (x,y)
#elif defined(__x86_32) || defined(__x86_64_sse3)
    #include<xmmintrin.h>
    #include<emmintrin.h>
    #include<pmmintrin.h>
    #include<tmmintrin.h>

    typedef __m128 SIMD_vec_ps;
    
    #define SIMD_num_float 4
    #define SIMD_array_align 16
    #define SIMD_load_ps(x) _mm_load_ps(x)
    #define SIMD_loadu_ps(x) _mm_loadu_ps(x)
    #define SIMD_store_ps(x, y) _mm_store_ps(x, y)
    #define SIMD_storeu_ps(x, y) _mm_storeu_ps(x, y)
    #define SIMD_set1_ps(x) _mm_set1_ps(x)
    #define SIMD_max_ps(x, y) _mm_max_ps(x, y)
    #define SIMD_add_ps(x, y) _mm_add_ps(x, y)
    #define SIMD_sub_ps(x, y) _mm_sub_ps(x, y)
    #define SIMD_mul_ps(x, y) _mm_mul_ps(x, y)
    #define SIMD_div_ps(x, y) _mm_div_ps(x, y)

    

#else
    #include <smmintrin.h> // SSE4.1
    #include <xmmintrin.h>
    #include <immintrin.h>
    
    typedef __m256 SIMD_vec_ps;
    
    #define SIMD_num_float 8
    #define SIMD_array_align 32
    #define SIMD_load_ps(x) _mm256_load_ps(x)
    #define SIMD_loadu_ps(x) _mm256_loadu_ps(x)
    #define SIMD_store_ps(x, y) _mm256_store_ps(x, y)
    #define SIMD_storeu_ps(x, y) _mm256_storeu_ps(x, y)
    #define SIMD_set1_ps(x) _mm256_set1_ps(x)
    #define SIMD_max_ps(x, y) _mm256_max_ps(x, y)
    #define SIMD_add_ps(x, y) _mm256_add_ps(x, y)
    #define SIMD_sub_ps(x, y) _mm256_sub_ps(x, y)
    #define SIMD_mul_ps(x, y) _mm256_mul_ps(x, y)
    #define SIMD_div_ps(x, y) _mm256_div_ps(x, y)
#endif

#ifdef _MSC_VER
    #define alignedArray(name, alignBytes, numElements) \
     __declspec(align(alignBytes)) float name[numElements];
#else
    #define alignedArray(name, alignBytes, numElements) \
        float name[numElements] __attribute__((aligned(alignBytes)));
#endif

#define is_memory_aligned(addr) ((((size_t) addr) % SIMD_array_align) == 0)

#endif //__ARCH_H__


#endif /* architecture_ops_h */
