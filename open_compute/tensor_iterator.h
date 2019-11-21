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

#include "range.hpp"
#include "shape.hpp"

#include "tensor_accessor.hpp"

namespace open_compute
{

class AxisIterator
{
private:
    TensorAccessor accessor;
    vector<int> cur_idx;
    int access_to_increment;
public:
    AxisIterator(TensorAccessor& accessor) 
    : accessor(accessor) , cur_idx(vector<int>(accessor.get_view().size(),0)){
      access_to_increment = cur_idx.size() - 2;
    }
    
    int num_elements_at_last_axis(){
        return accessor.get_view().back();
    }

    int next(){
        if(access_to_increment < 0) return -1;
        int idx = accessor[cur_idx];

        while(access_to_increment >= 0 && 
            (cur_idx[access_to_increment] = (cur_idx[access_to_increment] + 1) 
            % accessor.get_view()[access_to_increment]) == 0){
             --access_to_increment;
        }
        if(access_to_increment >= 0) access_to_increment = cur_idx.size()-2;

        return idx;
    }
};

};

#endif /* TensorIterator_hpp */
