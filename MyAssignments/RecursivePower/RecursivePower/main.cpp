//
//  main.cpp
//  RecursivePower
//
//  Created by Gary Hicks on 2018-03-12.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>

using namespace std;

int power(int m, int n){
    if (n==0) {
        return 1;
    }
    else{
        return m*power(m, n-1);
    }
}

int main() {
    
    int m,n;
    cin>>m>>n;
    
    int result = power(m,n);
    cout<<result<<endl;
    
}
