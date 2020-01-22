//
//  Float.cpp
//  LibNrMaths
//
//  Created by Nyhl Rawlings on 26/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Float.h"

namespace nrcore {
 
    Float::Float(String value, int base, int decimals) {
        
    }
    
    Float::Float(ByteArray &integer, ByteArray &decimals) {
        this->integer = integer;
        this->decimals = decimals;
    }
    
    Float::Float(const Float &val) {
        
    }
    
    Float::~Float() {
    
    }
    
    Float& Float::add(const Float &val) {
        return *this;
    }
    
    Float& Float::subtract(const Float &val) {
        return *this;
    }

    Float& Float::multiply(const Float &val) {
        return *this;
    }
    
    Float& Float::divide(const Float &val) {
        return *this;
    }
    
    Float& Float::power(const unsigned long val) {
        return *this;
    }
    
    Float& Float::sqrt() {
        return *this;
    }
    
    String Float::toString(int base) {
        String ret;
        return ret;
    }
    
    Float Float::initHexadecimal(String value, int decimal_bits) {
        ByteArray val = ByteArray::fromHex(value);
        
        int decimal_offset = decimal_bits/8;
        decimal_bits %= 8;
        
        if (decimal_bits)
            decimal_offset--;
        
        ByteArray decimals = val.subBytes(decimal_offset);
        char fb = decimals.operator const char *()[0] & 0xFF>>(8-decimal_bits);
        decimals.operator char *()[0] = fb;
        
        ByteArray integer = val.subBytes(0, decimal_offset+1);
        
        return Float(1, 10, 4);
    }
    
    Float Float::initDecimal(String value) {
        int exponent = 0;
        
        size_t len = value.length();
        for (size_t i=0; i<len; i++) {
            char digit = value.operator char *()[i];
            digit -= 48;
            
        }
        return Float(1, 10, 4);
    }
    
}
