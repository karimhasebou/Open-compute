//
//  vector_math.h
//  open_compute
//
//  Created by Karim Hasebou on 11/18/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef vector_math_h
#define vector_math_h

#include <cstddef>

namespace vector_math
{
template<class Type>
Type* add(Type* a, Type* b, size_t len, bool in_place = false)
{
    Type *out;
    if(in_place) out = a;
    else out = new Type[len];
    for(size_t i = 0; i < len; ++i)
        out[i] = a[i] + b[i];
    return out;
}

template<class Type>
Type* multiply(Type* a, Type* b, size_t len, bool in_place = false)
{
    Type *out;
    if(in_place) out = a;
    else out = new Type[len];
    for(size_t i = 0; i < len; ++i)
        out[i] = a[i] * b[i];
    return out;
}

template<class Type>
Type* subtract(Type* a, Type* b, size_t len, bool in_place = false)
{
    Type *out;
    if(in_place) out = a;
    else out = new Type[len];
    for(size_t i = 0; i < len; ++i)
        out[i] = a[i] - b[i];
    return out;
}

template<class Type>
Type* divide(Type* a, Type* b, size_t len, bool in_place = false)
{
    Type *out;
    if(in_place) out = a;
    else out = new Type[len];
    for(size_t i = 0; i < len; ++i)
        out[i] = a[i] / b[i];
    return out;
}

template<class Type>
Type dot_product(Type* a, Type* b, size_t len)
{
    Type out = Type(0);
    for(size_t i = 0; i < len; ++i)
        out += a[i] * b[i];
    return out;
}

template<class Type>
Type* transpose(Type* a, int rows, int cols, bool in_place = false){
    Type *out;
    
    if(in_place){
        Type *tmp = out = a;
        for(int c = 0; c <= cols / 2; c++)
            for(int r = 0; r < rows; r++, ++tmp)
                swap(*tmp,  *(a + r * cols + c));
    }else{
        *out = new Type[rows * cols];
        Type *tmp = out;
        for(int c = 0; c < cols; c++)
            for(int r = 0; r < rows; r++)
                *tmp++ = *(a + r * cols + c);
    }
    return out;
}
};

#endif /* vector_math_h */
