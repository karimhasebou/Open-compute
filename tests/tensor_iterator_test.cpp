#include "gtest/gtest.h"
#include "vector_math.h"
#include "matrix_math.hpp"
#include "tensor.hpp"
#include "tensor_accessor.hpp"
#include "tensor_iterator.hpp"
namespace {


TEST(TensorAccessor, get_index) {
    int size = 5;
    Shape shape({size, size, size});
    TensorAccessor ac(shape, shape);
    open_compute::AxisIterator it(ac);
    
    int off = 0;
    int idx = 0;
    while( (off = it.next()) != -1){
        EXPECT_EQ(off, idx);
        idx += size;
    }
}


}  // namespace