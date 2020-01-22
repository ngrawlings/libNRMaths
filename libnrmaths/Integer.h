//
//  Integer.hpp
//  LibNrMaths
//
//  Created by Nyhl Rawlings on 03/06/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <libnrcore/memory/ByteArray.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class Integer {
    public:
        Integer(String value, int base);
        Integer(int value);
        Integer(Memory &value);
        Integer(const Integer &val);
        virtual ~Integer();

        Integer& add(const Integer &val);
        Integer& subtract(const Integer &val);
        Integer& multiply(const Integer &val);
        Integer& divide(const Integer &val);
        
        Integer& power(const unsigned long val);
        Integer& sqrt();
        
        static int bitCount(const Memory &val);
        static int leadingZeroedBits(const Memory &val);
        static Memory byteAddition(const Memory &val1, const Memory &val2);
        static Memory byteMultiplication(const Memory &val1, const Memory &val2);
        static bool checkBit(const Memory &subject, int bit);
        static Memory clearBits(const Memory &subject, const Memory &bits);
        static Memory clearBit(const Memory &subject, int bit);
        
        static Memory mul2(const Memory &subject, int count);
        static Memory div2(const Memory &subject, int count);
        static Memory rem2(const Memory &subject, int count);
        
        size_t length() const;
        
        String toString(int base);
        
    protected:
        bool sign;
        Memory value;

        void fromDecimal(String value);
        
        
    };
    
}

#endif /* Integer_hpp */
