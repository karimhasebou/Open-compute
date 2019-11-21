#ifndef __TENSOR_ACCESSOR
#define __TENSOR_ACCESSOR

#include "shape.hpp"

class TensorAccessor
{
private:
    Shape tensor_dim;
    Shape view_dim;
    Shape stride;
public:
    TensorAccessor()
    {
        
    }
    const Shape& get_view(){
        return view_dim;
    }
    
    TensorAccessor(Shape tensor_dim, Shape view_dim) 
    : tensor_dim(tensor_dim), view_dim(view_dim)
    {
        for(int i = 0; i < tensor_dim.size();++i) stride.push_back(1);
    }

    TensorAccessor(Shape tensor_dim, Shape view_dim, Shape stride) 
    : tensor_dim(tensor_dim), view_dim(view_dim), stride(stride)
    {
    } 

    int operator[](const vector<int>& idx){
        return get_index(idx);
    }

    int get_index(const vector<int>& idx){
        int offset = 0;
        int multiplier = 1;
        for(int i = view_dim.size() - 1; i >= 0; i--){
            offset += idx[i] * multiplier * stride[i];
            multiplier *= tensor_dim[i];
        }
        return offset;
    }

    int last_continuous_axis(){
        if(stride[stride.size()-1] != 1) return -1;
        for(int i = stride.size() - 1; i > 0; ++i){
            if(stride[i] > 1) 
                return i + 1;
            if(view_dim[i] != tensor_dim[i])
                return i;
        }
        return 0;
    }
};

#endif