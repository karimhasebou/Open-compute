//
//  Tensor.h
//  open_compute
//
//  Created by Karim Hasebou on 11/18/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef Tensor_hpp
#define Tensor_hpp
#include <array>
#include <cmath>

#include "types.h"
#include "shape.h"
#include "tensor_accessor.h"
#include "tensor_iterator.h"

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
    std::shared_ptr<Storage> storage;
    TensorAccessor accessor;
    int storage_data_offset;
    
    Tensor(std::shared_ptr<Storage> storage, TensorAccessor accessor,
        int storage_data_offset) : storage(storage), accessor(accessor),
        storage_data_offset(storage_data_offset){
        
    }
public:


    Tensor(Shape shape, open_compute::DataType dt, 
        open_compute::Device device = open_compute::Device::CPU, 
        int storage_data_offset=0)
    {
        storage = std::make_shared<Storage>(shape.volume(), dt, device);
        accessor = TensorAccessor(shape, shape);
        this->storage_data_offset = storage_data_offset;
    }

    ~Tensor(){
    }

    Tensor slice(std::vector<std::array<int,3>> range)
    {
        Shape slice_shape;
        Shape slice_stride;
        std::vector<int> start_idx(range.size());
        for(int i = 0; i < range.size(); ++i){
            int dim = std::ceil(float(range[i][1] - range[i][0])/range[i][2]);
            slice_shape.push_back(dim);
            slice_stride.push_back(range[i][2]);
            start_idx[i] = range[i][0];
        }
        TensorAccessor slice_accessor(accessor.get_tensor_dim(), 
            slice_shape, slice_stride);
        int slice_storage_offset = accessor.get_index(start_idx) 
            + storage_data_offset;
        return Tensor(storage, slice_accessor, slice_storage_offset);
    }

    char* data(){
        return storage->data;
    }

    char* operator[](const int& idx){
        return storage->data + 
            (storage_data_offset + idx) * 
            open_compute::type_size(storage->data_type);
    }

    char* operator[](const std::vector<int>& shape){
        return storage->data + 
            (storage_data_offset + accessor[shape]) * 
            open_compute::type_size(storage->data_type);
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
