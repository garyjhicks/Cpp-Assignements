//
//  main.cpp
//  Assignment9Question2
//
//  Created by Gary Hicks on 2018-01-30.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void guess(int &min, int &max, int lowerbound,int upperbound){
    
    int myGuess=(max+min)/2;
    
    cout<<"Is your number: "<<myGuess<<"?"<<endl;
    string ans;
    cout<<"H = higher, L = lower, Y = yes"<<endl;
    cin>>ans;
    
    
    if (myGuess<=lowerbound && ans=="L"){
        cout<<"You are a lying bitch"<<endl;
    }
    else if (myGuess>=upperbound && ans=="H"){
        cout<<"You are a lying bitch"<<endl;
    }
    
    else if (ans=="Y"){
        cout<<"Yay!"<<endl;
    }
    else if (ans=="H"){
        
        min=myGuess;
        max=max+1;
        lowerbound=myGuess+1;
        
        guess(min,max,lowerbound,upperbound);
    }
    else if (ans=="L"){

        max=myGuess;
        upperbound=myGuess-1;
        guess(min,max,lowerbound,upperbound);
    }
    
    
}


int main() {
  
    
    
    int max,min;
    cin>>min>>max;
    int lowerbound=min;
    int upperbound=max;
    guess(min,max,lowerbound,upperbound);
    
    
    return 0;
}
