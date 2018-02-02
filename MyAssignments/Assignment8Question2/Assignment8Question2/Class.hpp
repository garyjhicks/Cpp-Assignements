//
//  Class.hpp
//  Assignment8Question2
//
//  Created by Gary Hicks on 2018-01-29.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#ifndef Class_hpp
#define Class_hpp

#include <iostream>

using namespace std;

class Fuel{
private:
    const double capacityMax=20000;
    const double capacityMin=100;
    double startFuel;
    double size;
    double unitSwitch(double value, string unit);

public:
    Fuel();
    Fuel(double newStartFuel, double newSize);
    double getFuelLevel(string unit);
    bool reFuel(double add, string unit);
    bool useFuel(double use, string unit);
};

#endif /* Class_hpp */
