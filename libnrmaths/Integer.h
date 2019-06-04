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
        Integer(ByteArray &value);
        Integer(const Integer &val);
        virtual ~Integer();
        
        Integer& add(const Integer &val);
        Integer& subtract(const Integer &val);
        Integer& multiply(const Integer &val);
        Integer& divide(const Integer &val);
        
        Integer& power(const unsigned long val);
        Integer& sqrt();
        
        String toString(int base);
        
    protected:
        bool sign;
        ByteArray value;
        
        void fromDecimal();
    };
    
}

#endif /* Integer_hpp */
