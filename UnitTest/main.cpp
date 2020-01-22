//
//  main.cpp
//  UnitTest
//
//  Created by Nyhl Rawlings on 26/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include <libnrmaths/Integer.h>

using namespace nrcore;

int main(int argc, const char * argv[]) {
    const char b1[] = {static_cast<char>(0xAA), static_cast<char>(0xAA), static_cast<char>(0xAA), static_cast<char>(0xAA)};
    const char b2[] = {static_cast<char>(0xAA), static_cast<char>(0xAA), static_cast<char>(0xAA), static_cast<char>(0xAA)};
    
    Memory v1(&b1, 4);
    Memory v2(&b2, 4);
    Integer::byteAddition(v1, v2);
    
    const char fs[] = {static_cast<char>(0xFF), static_cast<char>(0xFF), static_cast<char>(0xFF), static_cast<char>(0xFF)};
    
    v1 = Memory(fs, 4);
    ByteArray ba(v2);
    ba.shift(1);
    v2 = ba.subBytes(0, 4);
    
    Integer::clearBits(v1, v2);
    
    int s = 0xAAAACCCC;
    int m = 8;
    
    v1 = Memory(&s, 4);
    v2 = Memory(&m, 4);
    
    Integer::byteMultiplication(v1, v2);
    
    Memory div = Integer::div2(v1, 12);
    Memory rem = Integer::rem2(v1, 12);
    
    //std::cout << f.toString(10) << "\n";
    
    return 0;
}
