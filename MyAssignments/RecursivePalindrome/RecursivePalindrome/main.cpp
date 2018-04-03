//
//  main.cpp
//  RecursivePalindrome
//
//  Created by Gary Hicks on 2018-03-12.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(int sequence[], int length, int index){
    
    if (sequence[index]==sequence[length-1]){
        
        index++;
        length--;
        if (length==0){
            return true;
        }
    
        return IsPalindrome(sequence, length, index);
        
    }else{
        
        return false;
    }
}

int main() {
    
    int len;
    cin>>len;
    
    //cout<<len<<endl;
    
    int sequence[len];
    
    for(int i = 0; i<len; i++){
        cin>>sequence[i];
    }
    //cout<<sequence[1]<<endl;
    
    int index = 0;
    bool status = IsPalindrome(sequence, len, index);
    
    if (status == true) {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    return 0;
}
