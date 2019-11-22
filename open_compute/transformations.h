#ifndef __TRANSFORMATIONS_H
#define __TRANSFORMATIONS_H

#include <array>
#include <algorithm>

template<class type>
type* im2col(type* mat, 
    const std::array<int,3> arr_dims,
    const std::array<int,3> arr_view, 
    const std::array<int,3> arr_stride,
    const std::array<int,2> window_dims,
    const std::array<int,2> window_stride,
    const std::array<int, 4> padding,
    std::array<int, 2>& out_dims){
    
    int width = arr_dims[0] - window_dims[0] 
        + padding[0] + padding[1]) / window_stride[0] + 1;
    int height = (arr_dims[1] - window_dims[1] 
        + padding[2] + padding[3]) / window_stride[1] + 1;
    
    out_dims[0] = window_dims[0] * window_dims[1] * arr_view[2];
    out_dims[1] = height * width;
    
    type* out = new type[out_dims[0] * out_dims[1]];
    type* outIt = out;

    for(int y = 0; y < height; ++y){
    for(int x = 0; x < width; ++x){
    for(int d = 0; d < arr_view[2]; ++d){
        type* matPtr = get_loc(arr, d, 
        y * window_stride[1] - padding[2],
        x * window_stride[0] - padding[0]);
        for(int ky = 0; ky < window_dims[1]; ++ky){
            if(ky + y * stride <  paddingTop
                || ky + y * stride - paddingTop >= arr_view[1]){ // if y is out of range, we are
                std::fill(outIt, outIt + window_dims[0], type(0));
                outIt += window_dims[0];// thus we can fill entire row of zeros
            }else{
                int matPtrBegin = x * window_stride[0] - padding[0];
                int i = 0;
                while(matPtrBegin < 0 && i < window_dims[0]){
                    *++ = type(0);
                    ++matPtrBegin;
                    ++i;
                }

                while(i < kernelSize && srcABegin < inShape.w){
                    *outIt++ = matPtr[i];
                    ++i;
                    ++matPtrBegin;
                }
            }
        }
    }
    }
    }

    return out;
}

#endif