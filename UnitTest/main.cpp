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
    
    //std::cout << f.toString(10) << "\n";
    
    return 0;
}
