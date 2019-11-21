#ifndef __MATRIX_MATH
#define __MATRIX_MATH

#include "tensor.hpp"
#include "vector_math.h"

namespace open_compute
{

/*[[[cog
string binary_op_func_impl = '''
template<class type>
Tensor {0}_type_dispatch(Tensor& a, Tensor& b, bool in_place = false)
{
    if(!in_place) throw "operation not supported";
    AxisIterator a_iterator = a.axis_iterator();
    AxisIterator b_iterator = b.axis_iterator();

    int aidx = a_iterator.next();
    int bidx = a_iterator.next();
    int size = b_iterator.num_elements_at_last_axis();

    while(aid >= 0){
        vector_math::{0}<type>(a.data() + aidx, b.data() + bidx, size, 
            , a.data() + aidx);
        aidx = a_iterator.next();
        bidx = b_iterator.next();
    }

    return a;
}

Tensor {0}(Tensor& a, Tensor& b, bool in_place = false)
{
    switch(a.datatype())
    {
        case open_compute::DataType::FLOAT_32:
            return {0}_type_dispatch<float>(a, b, in_place);
        case open_compute::DataType::INT_32:
            return {0}_type_dispatch<int>(a, b, in_place);
        default:
            throw "operation not supported";
    }
}
'''
import cog

binary_operators = ['add', 'multiply', 'subtract', 'divide']
for fn in binary_operators:
    cog.outl(binary_op_func_impl.format(fn))
]]]*/
//[[[end]]]





};

#endif