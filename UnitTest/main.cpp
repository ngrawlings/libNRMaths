//
//  main.cpp
//  UnitTest
//
//  Created by Nyhl Rawlings on 26/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include <libnrmaths/Float.h>

using namespace nrcore;

int main(int argc, const char * argv[]) {
    Float f("10000000000000000001", 10, 64);
    
    std::cout << f.toString(10) << "\n";
    
    return 0;
}
