//
//  main.cpp
//  RecursiveGCD
//
//  Created by Gary Hicks on 2018-03-12.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>

using namespace std;


int gcd(int a, int b){
    if (a==b){
        return a;
    }
    if (b==1){
        return 1;
    }
    else if (((a/b)*b)==a){
        return b;
    }
    else{
        return gcd(a, (b-1));
    }
}


int main() {
    
    int a,b;
    cin>>a>>b;
    
    if (b>a){
        int temp=b;
        b=a;
        a=temp;
        cout<<a<<endl;
    }
    
    int lowest = gcd(a,abs(b-a));
    cout<<lowest<<endl;
    
    return 0;
}
