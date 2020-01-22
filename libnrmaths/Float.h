//
//  Float.hpp
//  LibNrMaths
//
//  Created by Nyhl Rawlings on 26/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Float_hpp
#define Float_hpp

#include <libnrcore/memory/ByteArray.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class Float {
    public:
        Float(String value, int base, int decimals = 0);
        Float(ByteArray &integer, ByteArray &decimals);
        Float(const Float &val);
        virtual ~Float();
        
        Float& add(const Float &val);
        Float& subtract(const Float &val);
        Float& multiply(const Float &val);
        Float& divide(const Float &val);
        
        Float& power(const unsigned long val);
        Float& sqrt();
        
        String toString(int base);
        
        static Float initHexadecimal(String value, int decimals = 0);
        static Float initDecimal(String value);
        
    protected:
        ByteArray integer;
        ByteArray decimals;
    };
    
}

#endif /* Float_hpp */
