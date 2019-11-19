#include "gtest/gtest.h"
#include "vector_math.h"

namespace {


TEST(addTest, int_out_off_place) {
    // This test is named "Negative", and belongs to the "FactorialTest"
    // test case.
    const int size = 10;
    int *x = new int[size];
    int *y = new int[size];

    for(int i = 0; i < size; ++i){
        x[i] = size - i;
        y[i] = i;
    }

    int *z = vector_math::add<int>(x, y, size);
    for(int i = 0; i < size; ++i){
        EXPECT_EQ(size, z[i]);
    }

    delete[] x;
    delete[] y;
    delete[] z;
}

TEST(addTest, int_out_in_place) {
    // This test is named "Negative", and belongs to the "FactorialTest"
    // test case.
    const int size = 10;
    int *x = new int[size];
    int *y = new int[size];

    for(int i = 0; i < size; ++i){
        x[i] = size - i;
        y[i] = i;
    }

    int *out = vector_math::add<int>(x, y, size, true);
    // assert same array has been returned 
    EXPECT_EQ(x, out);
    for(int i = 0; i < size; ++i){
        EXPECT_EQ(size, out[i]);
    }

    delete[] x;
    delete[] y;
}

}  // namespace