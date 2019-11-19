//
//  TensorIterator.hpp
//  open_compute
//
//  Created by Karim Hasebou on 11/18/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef TensorIterator_hpp
#define TensorIterator_hpp

#include <stdio.h>
#include <vector>
#include <numeric>
using namespace std;

class Range
{
private:
    vector<vector<int>> arr;
public:
    int rank(){
        return int(arr.size());
    }
    vector<int>& operator[](int idx){
        return arr[idx];
    }
};

class Shape
{
private:
    vector<int> shape;
public:
    Shape(int dims) : shape(vector<int>(dims)){
    }
    
    Shape(vector<int> shape) : shape(shape){
    }
    
    vector<int>::iterator begin(){
        return shape.begin();
    }
    
    vector<int>::iterator end(){
        return shape.end();
    }
    
    int rank(){return int(shape.size());}
    int volume(){
        int vol = 1;
        for(auto x : shape) vol *= x;
        return vol;
    }
    int& operator[](int idx){
        return shape[idx];
    }
};

class Iterator
{
private:
    char *arr;
    char *arr_temp;
    char *arr_end;
    int data_type_size;
    Shape matrix_dim;
    Shape stride;
    Shape view;
public:
    Iterator(char *arr, int dtype_size, Range& range, Shape& stride, Shape& view)
        : arr(arr), data_type_size(dtype_size), matrix_dim(range.rank()),
            stride(stride), view(view), arr_temp(arr){
        
        for(int i = 0; i < range.rank(); ++i){
            matrix_dim[i] = (range[i][1] - range[i][0]) / stride[i];
        }
            
    }
    
    ~Iterator(){
    }
    
    
    char* operator[](vector<int>& idx){
        Shape shape(idx);
        return (*this)[shape];
    }
    
    char* operator[](Shape& idx){
        int offset = 0;
        int multiplier = 1;
        for(int i = view.rank() - 1; i >= 0; i--){
            offset += idx[i] * multiplier * stride[i];
            multiplier *= (matrix_dim[i]);
        }
        return arr + offset * data_type_size;
    }
    
    bool is_continous(){
        return std::accumulate(stride.begin(), stride.end(), 0) == stride.rank();
    }
    
    int continuous_memory_len(){
        int cont_mem_len;
        if(stride[stride.rank()] == 1){
            cont_mem_len = view[view.rank()];
            for(int i = matrix_dim.rank()-2; i >= 0
                && view[i] == matrix_dim[i]; --i){
                cont_mem_len *= view[i];
            }
        }else{
            cont_mem_len = 1;
        }
        return cont_mem_len;
    }
    
    char* next(){
        if(arr_temp == arr_end) return nullptr;
        else{
            char* next_loc = arr_temp;
            arr_temp += continuous_memory_len() * data_type_size;
            return next_loc;
        }
    }
};


#endif /* TensorIterator_hpp */
