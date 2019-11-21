//
//  Tensor.hpp
//  open_compute
//
//  Created by Karim Hasebou on 11/18/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef Tensor_hpp
#define Tensor_hpp

#include "types.h"
#include "shape.hpp"
#include "tensor_accessor.hpp"

struct Storage{
    char *data;
    int len;
    open_compute::DataType data_type;
    open_compute::Device device;
};

class Tensor
{
private:
    Storage *data;
    TensorAccessor accessor;
public:
    Tensor(vector<int> shape, open_compute::DataType dt, 
        open_compute::Device device = open_compute::Device::CPU);
    Tensor reshape(Shape new_shape);
    Tensor copy();
};

#endif /* Tensor_hpp */
