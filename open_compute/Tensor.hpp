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
#include "tensor_iterator.hpp"

struct Storage{
    char *data;
    int len;
    open_compute::DataType data_type;
    open_compute::Device device;
    Storage(int len, open_compute::DataType data_type, 
        open_compute::Device device) 
        : len(len), data_type(data_type), device(device) {
        data = (char*) malloc(len * open_compute::type_size(data_type));
    }
    ~Storage(){
        free(data);
    }
};

class Tensor
{
private:
    Storage *storage;
    TensorAccessor accessor;
public:
    Tensor(Shape shape, open_compute::DataType dt, 
        open_compute::Device device = open_compute::Device::CPU)
    {
        storage = new Storage(shape.volume(), dt, device);
        accessor = TensorAccessor(shape, shape);
    }

    ~Tensor(){
        delete storage;
    }
    
    Tensor reshape(Shape new_shape);
    
    Tensor copy();

    char* data(){
        return storage->data;
    }

    char* operator[](int idx){
        return storage->data + 
            idx * open_compute::type_size(storage->data_type);
    }

    char* operator[](vector<int>& shape){
        return storage->data + 
            accessor[shape] * open_compute::type_size(storage->data_type);
    }

    open_compute::AxisIterator axis_iterator(){
        open_compute::AxisIterator it(accessor);
        return it;
    }

    open_compute::DataType datatype(){
        return storage->data_type;
    }
};

#endif /* Tensor_hpp */
