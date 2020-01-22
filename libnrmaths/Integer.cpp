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
        int exponent = 0;
        
        size_t len = value.length();
        for (size_t i=0; i<len; i++) {
            char digit = value.operator char *()[i];
            digit -= 48;
            if (exponent) {
                
            }
        }
    }
    
    Integer& Integer::add(const Integer &val) {
        ByteArray v1, v2, res;
        int carry = 0;
        
        if (value.length() > val.length()) {
            v1 = value;
            v2 = val.value;
        } else {
            v1 = val.value;
            v2 = value;
        }
        
        Memory m1 = v1;
        Memory m2 = v2;
        
        int len = (int)v2.length();
        for (int i=0; i<len; i++) {
            int v = carry + m1[i] + m2[i];
            
            carry = v/256;
            v %= 256;
            
            res.append(Memory(&v, 1));
            
        }
        
        while (carry) {
            int v = carry % 256;
            carry = carry / 256;
            
            res.append(Memory(&v, 1));
        }
        
        value = res;
        
        return *this;
    }
    
    Integer& Integer::subtract(const Integer &val) {
        return *this;
    }
    
    Integer& Integer::multiply(const Integer &val) {
        return *this;
    }
    
    Integer& Integer::divide(const Integer &val) {
        return *this;
    }
    
    Integer& Integer::power(const unsigned long val) {
        return *this;
    }
    
    Integer& Integer::sqrt() {
        return *this;
    }

    size_t Integer::length() const {
        return value.length();
    }
    
    String Integer::toString(int base) {
        return String("");
    }

    int Integer::bitCount(const Memory &val) {
        Memory m = val.getMemory();
        
        int len = (int)val.length()*8;
        for (int i=0; i<len; i++) {
            int byte = i/8;
            int bit = i%8;
            
            if (m[byte] & (1>>bit))
                return len-i;
        }
        return 0;
    }

    Memory Integer::byteAddition(const Memory &val1, const Memory &val2) {
        const Memory *m1, *m2;
        ByteArray result;
        
        if (val1.length() >= val2.length()) {
            m1 = &val1;
            m2 = &val2;
        } else {
            m1 = &val2;
            m2 = &val1;
        }
        
        int index = 0;
        int carry = 0;
        int value = 0;
        
        do {
            if (index < m2->length()) {
                value = carry + ((unsigned char)m1->getByte(index)) + ((unsigned char)m2->getByte(index));
                carry = 0;
            } else
                value = carry;
            
            result.insert(0, (char*)&value, 1);
            carry = value>>8;
            index++;
        } while (carry);
        
        return result;
    }
    
}
