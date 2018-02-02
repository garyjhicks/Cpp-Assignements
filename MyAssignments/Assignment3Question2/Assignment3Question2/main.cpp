//
//  main.cpp
//  Assignment3Question2
//
//  Created by Gary Hicks on 2018-01-19.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int a=0;
    int b=0;
    
    do{
        cout<<"Time 1: "<<flush;
        int time1;
        cin>>time1;
        if (time1>100 && time1<2400){
            if ((time1-60)/100!=(time1/100)){
                a=time1;
            }
        }

    }while(a<100 || a>2400);
    cout<<"First time is: "<<a<<endl;
    
    do{
        cout<<"Time 2: "<<flush;
        int time2;
        cin>>time2;
        if (time2>100 && time2<2400){
            if ((time2-60)/100!=(time2/100)){
                b=time2;
            }
        }
        
    }while(b<100 || b>2400);
    cout<<"Second time is: "<<b<<endl;
    
    int amin = a-(a/100)*100+(a/100)*60;
    int bmin = b-(b/100)*100+(b/100)*60;
    
    if (a>b){
      cout<<amin-bmin<<endl;
    }
    else{
        cout<<bmin-amin<<endl;
    }
    return 0;
}
