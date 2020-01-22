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
            case 10:
                break;
                
            case 16:
                this->value = ByteArray::fromHex(value);
                break;
        }
    }
    
    Integer::Integer(int value) {
        this->value = Memory(&value, 4);
        sign = value >= 0;
    }
    
    Integer::Integer(Memory &value) {
        this->value = value;
    }
    
    Integer::Integer(const Integer &val) {
        
    }
    
    Integer::~Integer() {
        
    }
    
    void Integer::fromDecimal(String value) {
        ByteArray ba = ByteArray();
        
        size_t len = value.length();
        for (size_t i=0; i<len; i++) {
            char digit = value.operator char *()[i];
            digit -= 48;
            
        }
    }
    
    Integer& Integer::add(const Integer &val) {
        value = byteAddition(this->value, val.value);
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
            
            if (m[byte] & (1<<bit))
                return len-i;
        }
        return 0;
    }

    int Integer::leadingZeroedBits(const Memory &val) {
        Memory m = val.getMemory();
        
        int len = (int)val.length()*8;
        for (int i=0; i<len; i++) {
            int byte = i/8;
            int bit = i%8;
            
            if (m[byte] & (1<<bit))
                return i;
        }
        return 0;
    }

    bool Integer::checkBit(const Memory &subject, int bit) {
        int byte = bit/8;
        bit %= 8;
        
        char b = subject.getByte(byte);
        return b & ~(1<<bit);
    }

    Memory Integer::clearBits(const Memory &subject, const Memory &bits) {
        Memory res = subject.getMemory();
        Memory b = bits.getMemory();
        
        int len = (int)res.length();
        
        if (b.length() < len) {
            ByteArray _b(b, (int)b.length());
            int needed = ((int)len - (int)_b.length());
            int tmp = 0;
            int inserted = 0;
            
            while (needed) {
                _b.insert(0, (char*)&tmp, inserted = (needed > 4 ? 4 : needed));
                needed -= inserted;
            }
            
            b = _b;
        } else if (b.length() > len) {
            int diff = (int)(b.length() - len);
            b = Memory(&b.getPtr()[diff], len);
        }
        
        for (int i=0; i<len; i++)
            res[i] = res[i] & ~b[i];
        
        return res;
    }

    Memory Integer::clearBit(const Memory &subject, int bit) {
        int byte = bit/8;
        bit %= 8;
        
        Memory result = subject.getMemory();
        result[byte] &= ~(1<<bit);
        
        return result;
    }

    Memory Integer::byteAddition(const Memory &val1, const Memory &val2) {
        const Memory *m1, *m2;

        if (val1.length() >= val2.length()) {
            m1 = &val1;
            m2 = &val2;
        } else {
            m1 = &val2;
            m2 = &val1;
        }
        
        int len = (int)m2->length();
        int index = 0;
        int carry = 0;
        int value = 0;
        
        Memory _res = m1->getMemory();
        ByteArray  result = ByteArray(_res);
        
        do {
            if (index < m2->length()) {
                value = carry + ((unsigned char)m1->getByte(index)) + ((unsigned char)m2->getByte(index));
                carry = 0;
            } else
                value = carry;
            
            result.insert(0, (char*)&value, 1);
            carry = value>>8;
            index++;
        } while (carry || index < len);
        
        return result;
    }

    Memory Integer::byteMultiplication(const Memory &val, const Memory &mul) {
        ByteArray multiplier;
        Memory result;
        
        multiplier = ByteArray(mul.getMemory(), (int)mul.length());
        int bit_cnt = bitCount(mul);
        int bit = leadingZeroedBits(mul)+1;
        
        while (bit<bit_cnt) {
            if (checkBit(multiplier, bit)) {
                
            }
            bit++;
        }
        
        return result;
    }

    Memory Integer::mul2(const Memory &subject, int count) {
        int bit_cnt = bitCount(subject);

        ByteArray result(subject);
        
        int tmp = 0;
        int new_bytes = count/8;
        count = count % 8;
        
        while (new_bytes) {
            int appended = new_bytes > 4 ? 4 : new_bytes;
            result.append(&tmp, appended);
            new_bytes -= appended;
        }
        
        if (count)
            result.shift(count);
        
        int leading_zeros = (int)subject.length()-bit_cnt;
        if (leading_zeros > 8)
            result = result.subBytes(leading_zeros/8);
        
        return result;
    }

    Memory Integer::div2(const Memory &subject, int count) {
        int bytes = count/8;
        int bits = count%8;
        
        if (bits)
            bytes++;
        
        ByteArray result(subject);
        result.shift(bits);
        if (!result.operator char *()[0])
            result = result.subBytes(1, (int)result.length()-2-bytes);
        else if (bytes)
            result = result.subBytes(0, (int)result.length()-bytes);
        
        return result;
    }

    Memory Integer::rem2(const Memory &subject, int count) {
        int bytes = count/8;
        char bits = count%8;
        char bit_mask = 0;
        
        if (bits) {
            bytes++;
            for (int i=0; i<bits; i++)
                bit_mask |= 1<<i;
        }
        
        ByteArray result(&subject.getMemory().getPtr()[subject.length()-bytes], bytes);
        result.operator char *()[0] &= bit_mask;
        
        return result;
    }
    
}
