//
//  main.cpp
//  Assignment3Question1
//
//  Created by Gary Hicks on 2018-01-19.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double max = 5;
    double min = -5;
    double x = (min+max)/2;
    double y = 3*x*x*x*x*x+11*x*x*x*x+12*x*x*x-7*x+5;
    
    
    
    while(y>0.0001 || y<-0.0001 ){
        if (y>0){
            max=x;
            x=(max+min)/2;
            y = 3*x*x*x*x*x+11*x*x*x*x+12*x*x*x-7*x+5;
        }
        if (y<0){
            min=x;
            x=(max+min)/2;
            y = 3*x*x*x*x*x+11*x*x*x*x+12*x*x*x-7*x+5;
        }
    }
    cout<<setprecision(10)<<x<<endl;
    
    return 0;
}
