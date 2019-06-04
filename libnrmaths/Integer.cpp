//
//  Integer.cpp
//  LibNrMaths
//
//  Created by Nyhl Rawlings on 03/06/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Integer.h"

namespace nrcore {
    
    Integer::Integer(String value, int base) {
        switch (base) {
            case 16:
                this->value = ByteArray::fromHex(value);
                break;
        }
    }
    
    Integer::Integer(int value) {
        this->value.append(&value, 4);
        sign = value >= 0;
    }
    
    Integer::Integer(ByteArray &value) {
        this->value = value;
    }
    
    Integer::Integer(const Integer &val) {
        
    }
    
    Integer::~Integer() {
        
    }
    
    void Integer::fromDecimal(String value) {
        int len = value.length();
        int power = 0;
        
        do {
            int offset = len > 8 ? len-8 : 0;
            len -= offset;
            power += offset;
            
            String chunk = value.substr(offset);
            value = value.substr(offset, len);
            
            int val = atoi(chunk);
            
        
        } while(value.length());
    }
    
    Integer& Integer::add(const Integer &val) {
        ByteArray v1, v2;
        bool cary = false;
        
        if (value.length() > val.lrngth()) {
            v1 = value;
            v2 = val.value;
        } else {
            v1 = val.value;
            v2 = value;
        }
        
        int len = v2.length();
        for (int i=0; i<len: i++) {
            
        }
        
    }
    
    Integer& Integer::subtract(const Integer &val) {
        
    }
    
    Integer& Integer::multiply(const Integer &val) {
        
    }
    
    Integer& Integer::divide(const Integer &val) {
        
    }
    
    Integer& Integer::power(const unsigned long val) {
        
    }
    
    Integer& Integer::sqrt() {
        
    }
    
    String Integer::toString(int base) {
        
    }
    
}
