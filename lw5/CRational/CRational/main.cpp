//
//  main.cpp
//  CRational
//
//  Created by Moore on 18/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include "CRational.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    CRational first(1, 5);
    first *= 6;
    cout << first.ToDouble() << " - first rational to double.\n";
    CRational sec(1);
    sec = first + 5;
    cout << sec.ToDouble() << "int + rational\n";
    return 0;
}
