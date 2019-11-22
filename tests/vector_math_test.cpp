#include "gtest/gtest.h"
#include "vector_math.h"

namespace {


TEST(vectorTest, new_array) {
    const int size = 10;
    int *x = new int[size];
    int *y = new int[size];

    for(int i = 0; i < size; ++i){
        x[i] = size - i;
        y[i] = i;
    }

    int *z = new int[size];
    int *returned_z = vector_math::add<int>(x, y, size, z);
    
    EXPECT_EQ(z, returned_z);
    for(int i = 0; i < size; ++i){
        EXPECT_EQ(size, z[i]);
    }

    delete[] x;
    delete[] y;
    delete[] z;
}

TEST(vectorTest, inplace) {
    const int size = 10;
    int *x = new int[size];
    int *y = new int[size];

    for(int i = 0; i < size; ++i){
        x[i] = size - i;
        y[i] = i;
    }

    int *out = vector_math::add<int>(x, y, size);
    // assert same array has been returned 
    EXPECT_EQ(x, out);
    for(int i = 0; i < size; ++i){
        EXPECT_EQ(size, out[i]);
    }

    delete[] x;
    delete[] y;
}

}  // namespace