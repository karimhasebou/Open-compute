#ifndef __MATRIX_MATH
#define __MATRIX_MATH

#include "tensor.h"
#include "vector_math.h"

namespace open_compute
{

template<class type>
type* average_pool(float* a, int rows, int cols,
    int kwidth, int kheight, float* out = nullptr);

template<class type>
type* max_pool(float* a, int rows, int cols,
    int kwidth, int kheight, float* out = nullptr);

template<class type>
type* matmul(float* a, float* b, 
    int aRows, int aCols, int bCols, bool b_transposed,float* out = nullptr){
    assert(b_transposed); // not supporting non transposed b
    if(out == nullptr) out = new type[aRows * bCols];

    type* out_tmp = out;
    for(int aRow = 0; aRow < aRows; ++aRow){
        type* b_tmp = b;
        for(int bCol = 0; bCol < bCols; ++bCol){
            *out_tmp++ vector_math::dot_product(a, b_tmp, aCols);
            b_tmp += aCols;
        }
    }

    return out;
}

};

#endif