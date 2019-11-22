#include "gtest/gtest.h"
#include "vector_math.h"
#include "matrix_math.h"
#include "tensor.h"
#include "tensor_accessor.h"
#include "tensor_iterator.h"
#include <cstring>
#include <iostream>

namespace {


TEST(TensorSlice, test_int32) {
    Shape shape({2, 6, 6});

    Tensor base(shape, open_compute::DataType::INT_32);
    Tensor slice = base.slice({{0,2, 1}, {0, 6, 2}, {0, 6, 2}});

    int* base_ptr = (int*) base.data();
    int* begin = base_ptr;
    int* end = begin + shape.volume();
    for(int i = 0; begin != end; ++i, ++begin){
        *begin = i;
    }
    
    for(int i = 0; i < shape[0]; ++i){
        for(int j = 0; j < shape[1]/2; ++j){
            for(int k = 0; k < shape[2]/2; ++k){
                std::cout << *((int*)slice[{i, j, k}]) << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }
}


}  // namespace