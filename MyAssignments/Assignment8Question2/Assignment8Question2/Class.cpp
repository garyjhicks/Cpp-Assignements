//
//  Class.cpp
//  Assignment8Question2
//
//  Created by Gary Hicks on 2018-01-29.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include "Class.hpp"
#include <iostream>

using namespace std;

Fuel::Fuel(){
    startFuel=10050;
    size=20000;
}

Fuel::Fuel(double newStartFuel, double newSize){
    size=newSize;
    startFuel=newStartFuel;
    if (startFuel>newSize || startFuel<0){
        startFuel=-1;
    }
    if (size>capacityMax || size<0){
        newSize=-1;
    }
        
}


double Fuel::unitSwitch(double value, string unit){
    
    if (unit =="L"){
        return value;
    }
    else if (unit == "kg"){
        double L = value*840/1000;
        return L;
    }
    else{
        double L = value*840/1000*2.20462;
        return L;
    }
}

double Fuel::getFuelLevel(string unit){
    
    if (unit =="L"){
        return startFuel;
    }
    else if (unit == "kg"){
        double L = Fuel::unitSwitch(startFuel, "kg");
        return L;
    }
    else{
        double L = Fuel::unitSwitch(startFuel, "lb");
        return L;
    }
}

bool Fuel::reFuel(double add, string unit){
    
    double temp=startFuel;
    
    if (unit =="L"){
        startFuel=startFuel+add;
        if (startFuel>size){
            startFuel=temp;
            cout<<startFuel<<endl;
            return false;
        }
        cout<<startFuel<<endl;
        return true;
    }
    else if (unit == "kg"){
        add = Fuel::unitSwitch(add, "kg");
        startFuel=startFuel+add;
        if (startFuel>size){
            startFuel=temp;
            cout<<startFuel<<endl;
            return false;
        }
        cout<<startFuel<<endl;
        return true;
    }
    else if (unit=="lb"){
        add = Fuel::unitSwitch(add, "lb");
        startFuel=startFuel+add;
        if (startFuel>size){
            startFuel=temp;
            cout<<startFuel<<endl;
            return false;
        }
        cout<<startFuel<<endl;
        return true;
    }
    else{
        return false;
    }
}

bool Fuel::useFuel(double use, string unit){
    
    double temp=startFuel;
    
    if (unit =="L"){
        startFuel=startFuel-use;
        if (startFuel<0){
            startFuel=temp;
            //cout<<startFuel<<endl;
            return false;
        }
        //cout<<startFuel<<endl;
        return true;
    }
    else if (unit == "kg"){
        use = Fuel::unitSwitch(use, "kg");
        startFuel=startFuel-use;
        if (startFuel<0){
            startFuel=temp;
            //cout<<startFuel<<endl;
            return false;
        }
        //cout<<startFuel<<endl;
        return true;
    }
    else if (unit=="lb"){
        use = Fuel::unitSwitch(use, "lb");
        startFuel=startFuel-use;
        if (startFuel<0){
            startFuel=temp;
            //cout<<startFuel<<endl;
            return false;
        }
        //cout<<startFuel<<endl;
        return true;
    }
    else{
        return false;
    }
}
    
