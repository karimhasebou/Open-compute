#include "gtest/gtest.h"
#include "vector_math.h"
#include "matrix_math.hpp"
#include "tensor.hpp"
#include "tensor_accessor.hpp"
namespace {


TEST(TensorAccessor, get_index) {
    int size = 5;
    Shape shape({size, size, size});
    TensorAccessor ac(shape, shape);

    int idx = 0;
    for(int i = 0; i < size;++i){
        for(int j = 0; j < size; ++j){
            for(int k = 0; k < size; ++k, idx++){
                EXPECT_EQ(ac.get_index({i, j, k}), idx);
            }
        }
    }
}


}  // namespace