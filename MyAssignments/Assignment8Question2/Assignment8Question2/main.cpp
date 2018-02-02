//
//  main.cpp
//  Assignment8Question2
//
//  Created by Gary Hicks on 2018-01-29.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include "Class.hpp"

using namespace std;

int main() {
    
    Fuel fuel(1000,5000);
    cout<<fuel.getFuelLevel("L")<<endl;
    fuel.reFuel(1000,"L");
    fuel.useFuel(200,"L");
    cout<<fuel.getFuelLevel("L")<<endl;
    cout<<fuel.getFuelLevel("kg")<<endl;
    cout<<fuel.getFuelLevel("lb")<<endl;
    
    cout<<endl;
    
    Fuel fuel0;
    cout<<fuel0.getFuelLevel("L")<<endl;
    fuel0.reFuel(1000,"L");
    fuel0.useFuel(200,"L");
    cout<<fuel0.getFuelLevel("L")<<endl;
    cout<<fuel0.getFuelLevel("kg")<<endl;
    cout<<fuel0.getFuelLevel("lb")<<endl;
    
    cout<<endl;
    
    Fuel fuel1(1000,5000);
    cout<<fuel1.getFuelLevel("L")<<endl;
    fuel1.reFuel(10000,"L");
    fuel1.useFuel(2000,"L");
    cout<<fuel1.getFuelLevel("L")<<endl;
    cout<<fuel1.getFuelLevel("kg")<<endl;
    cout<<fuel1.getFuelLevel("lb")<<endl;
    
    cout<<endl;
    return 0;
}
