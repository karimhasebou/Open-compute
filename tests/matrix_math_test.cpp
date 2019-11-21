#include "gtest/gtest.h"
#include "vector_math.h"
#include "matrix_math.h"
#include "tensor.h"

namespace {


TEST(FloatMatrixAdd, new_array) {
    int size = 5;
    Shape shape({size, size, size});

    Tensor a(shape, open_compute::FLOAT_32);
    Tensor b(shape, open_compute::FLOAT_32);

    int vol = shape.volume();
    for(int i = 0; i < vol; ++i){
        *((float*)a[i]) = i;
        *((float*)b[i]) = i;
    } 

    a = open_compute::multiply(a, b, true);
    for(int i = 0; i < vol; ++i){
        //cout << *((float*)a[i]) << endl;
        EXPECT_EQ(*((float*)a[i]),  float(i) * i);
    } 
}


}  // namespace