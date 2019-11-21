//
//  shape.hpp
//  open_compute
//
//  Created by Karim Hasebou on 11/19/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef shape_hpp
#define shape_hpp

#include <vector>
using namespace std;

class Shape : public vector<int>
{
public:
    Shape() : vector<int>(){};
    Shape(const vector<int> x) : vector<int>(x){};
    int volume(){
        int vol = 1;
        for(auto x : *this) vol *= x;
        return vol;
    }
};

#endif /* shape_hpp */
