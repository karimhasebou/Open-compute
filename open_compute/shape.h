//
//  shape.h
//  open_compute
//
//  Created by Karim Hasebou on 11/19/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef shape_hpp
#define shape_hpp

#include <vector>

class Shape : public std::vector<int>
{
public:
    Shape() : std::vector<int>(){};
    Shape(const std::vector<int> x) : std::vector<int>(x){};
    int volume(){
        int vol = 1;
        for(auto x : *this) vol *= x;
        return vol;
    }
};

#endif /* shape_hpp */
