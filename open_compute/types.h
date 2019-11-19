//
//  types.h
//  open_compute
//
//  Created by Karim Hasebou on 11/18/19.
//  Copyright © 2019 karim hasebou. All rights reserved.
//

#ifndef types_h
#define types_h

namespace open_compute{

enum DataType
{
    INT_8,
    INT_16,
    INT_32,
    FLOAT_8,
    FLOAT_16,
    FLOAT_32,
};

int type_size(DataType type)
{
    switch(type){
        case INT_8:
        case FLOAT_8:
            return 1;
        case INT_16:
        case FLOAT_16:
            return 2;
        case INT_32:
        case FLOAT_32:
            return 4;
    }
}

enum Device{
    CPU,
    GPU,
};

};

#endif /* types_h */
