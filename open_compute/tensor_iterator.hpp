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
    vector<int> next;
    int access_to_increment;
public:
    AxisIterator(TensorAccessor& accessor) 
    : accessor(accessor) , next(vector<int>(accessor.get_view().size(),0)){
      access_to_increment = next.size() - 2;
    }
    
    int next(){
        if(access_to_increment < 0) return -1;
        int idx = accessor[next];

        next[access_to_increment] = (next[access_to_increment] + 1) 
            % accessor.get_view()[access_to_increment];

        if(next[access_to_increment] == 0){
            --access_to_increment;
        }

        return idx;
    }
};

};

#endif /* TensorIterator_hpp */
