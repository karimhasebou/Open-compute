//
//  range.h
//  open_compute
//
//  Created by Karim Hasebou on 11/19/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef range_hpp
#define range_hpp

#include <vector>

class Range
{
private:
    std::vector<std::vector<int>> arr;
public:
    int rank(){
        return int(arr.size());
    }
    std::vector<int>& operator[](int idx){
        return arr[idx];
    }
};


#endif /* range_hpp */
