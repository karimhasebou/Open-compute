#ifndef __MATRIX_MATH
#define __MATRIX_MATH

#include "tensor.hpp"
#include "vector_math.h"

namespace open_compute
{

/*[[[cog
binary_op_func_impl = """
template<class type>
Tensor %s_type_dispatch(Tensor& a, Tensor& b, bool in_place = false)
{
    if(!in_place) throw "operation not supported";
    AxisIterator a_iterator = a.axis_iterator();
    AxisIterator b_iterator = b.axis_iterator();

    int aidx = a_iterator.next();
    int bidx = b_iterator.next();
    int size = b_iterator.num_elements_at_last_axis();

    type* a_data = (type*) a.data();
    type* b_data = (type*) b.data();

    while(aidx >= 0){
        vector_math::%s<type>(a_data + aidx, b_data + bidx, size, 
            a_data + aidx);
        aidx = a_iterator.next();
        bidx = b_iterator.next();
    }

    return a;
}

Tensor %s(Tensor& a, Tensor& b, bool in_place = false)
{
    switch(a.datatype())
    {
        case open_compute::DataType::FLOAT_32:
            return %s_type_dispatch<float>(a, b, in_place);
        case open_compute::DataType::INT_32:
            return %s_type_dispatch<int>(a, b, in_place);
        default:
            throw "operation not supported";
    }
}
"""
import cog

binary_operators = ['add', 'multiply', 'subtract', 'divide']
for fn in binary_operators:
    cog.outl(binary_op_func_impl % (fn,fn,fn,fn,fn))
    
]]]*/

template<class type>
Tensor add_type_dispatch(Tensor& a, Tensor& b, bool in_place = false)
{
    if(!in_place) throw "operation not supported";
    AxisIterator a_iterator = a.axis_iterator();
    AxisIterator b_iterator = b.axis_iterator();

    int aidx = a_iterator.next();
    int bidx = b_iterator.next();
    int size = b_iterator.num_elements_at_last_axis();

    type* a_data = (type*) a.data();
    type* b_data = (type*) b.data();

    while(aidx >= 0){
        vector_math::add<type>(a_data + aidx, b_data + bidx, size, 
            a_data + aidx);
        aidx = a_iterator.next();
        bidx = b_iterator.next();
    }

    return a;
}

Tensor add(Tensor& a, Tensor& b, bool in_place = false)
{
    switch(a.datatype())
    {
        case open_compute::DataType::FLOAT_32:
            return add_type_dispatch<float>(a, b, in_place);
        case open_compute::DataType::INT_32:
            return add_type_dispatch<int>(a, b, in_place);
        default:
            throw "operation not supported";
    }
}


template<class type>
Tensor multiply_type_dispatch(Tensor& a, Tensor& b, bool in_place = false)
{
    if(!in_place) throw "operation not supported";
    AxisIterator a_iterator = a.axis_iterator();
    AxisIterator b_iterator = b.axis_iterator();

    int aidx = a_iterator.next();
    int bidx = b_iterator.next();
    int size = b_iterator.num_elements_at_last_axis();

    type* a_data = (type*) a.data();
    type* b_data = (type*) b.data();

    while(aidx >= 0){
        vector_math::multiply<type>(a_data + aidx, b_data + bidx, size, 
            a_data + aidx);
        aidx = a_iterator.next();
        bidx = b_iterator.next();
    }

    return a;
}

Tensor multiply(Tensor& a, Tensor& b, bool in_place = false)
{
    switch(a.datatype())
    {
        case open_compute::DataType::FLOAT_32:
            return multiply_type_dispatch<float>(a, b, in_place);
        case open_compute::DataType::INT_32:
            return multiply_type_dispatch<int>(a, b, in_place);
        default:
            throw "operation not supported";
    }
}


template<class type>
Tensor subtract_type_dispatch(Tensor& a, Tensor& b, bool in_place = false)
{
    if(!in_place) throw "operation not supported";
    AxisIterator a_iterator = a.axis_iterator();
    AxisIterator b_iterator = b.axis_iterator();

    int aidx = a_iterator.next();
    int bidx = b_iterator.next();
    int size = b_iterator.num_elements_at_last_axis();

    type* a_data = (type*) a.data();
    type* b_data = (type*) b.data();

    while(aidx >= 0){
        vector_math::subtract<type>(a_data + aidx, b_data + bidx, size, 
            a_data + aidx);
        aidx = a_iterator.next();
        bidx = b_iterator.next();
    }

    return a;
}

Tensor subtract(Tensor& a, Tensor& b, bool in_place = false)
{
    switch(a.datatype())
    {
        case open_compute::DataType::FLOAT_32:
            return subtract_type_dispatch<float>(a, b, in_place);
        case open_compute::DataType::INT_32:
            return subtract_type_dispatch<int>(a, b, in_place);
        default:
            throw "operation not supported";
    }
}


template<class type>
Tensor divide_type_dispatch(Tensor& a, Tensor& b, bool in_place = false)
{
    if(!in_place) throw "operation not supported";
    AxisIterator a_iterator = a.axis_iterator();
    AxisIterator b_iterator = b.axis_iterator();

    int aidx = a_iterator.next();
    int bidx = b_iterator.next();
    int size = b_iterator.num_elements_at_last_axis();

    type* a_data = (type*) a.data();
    type* b_data = (type*) b.data();

    while(aidx >= 0){
        vector_math::divide<type>(a_data + aidx, b_data + bidx, size, 
            a_data + aidx);
        aidx = a_iterator.next();
        bidx = b_iterator.next();
    }

    return a;
}

Tensor divide(Tensor& a, Tensor& b, bool in_place = false)
{
    switch(a.datatype())
    {
        case open_compute::DataType::FLOAT_32:
            return divide_type_dispatch<float>(a, b, in_place);
        case open_compute::DataType::INT_32:
            return divide_type_dispatch<int>(a, b, in_place);
        default:
            throw "operation not supported";
    }
}

//[[[end]]]





};

#endif