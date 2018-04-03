//
//  main.cpp
//  RecursionASCII
//
//  Created by Gary Hicks on 2018-03-12.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ascii2int(char str[], int length, int i){
    //cout<<length<<endl;
    cout<<"i is "<<i<<endl;
    if (i==length-1){
        return 0;
    }
    else{
        i++;
        //cout<<"i is "<<i<<endl;
        cout<<int((str[i])-48)*(pow(10,length-i-1))<<endl;
        return int((str[i])-48)*(pow(10,length-i-1)) + ascii2int(str, length, i);
    }
}

string int2ascii(int num, int i, string string){
    if (i==1){
        string += (char) num + 48;
        return string;
    }
    else{
        string += (char)(num/i + 48);
        num = num-(num/i)*i;
        i=i/10;
        return int2ascii(num, i, string);
    }
        
}

int main() {
    
    /*char str[] = "";
    cin>>str;
    
    //cout<<str<<endl;
    
    int i=-1;
    
    int value = ascii2int(str, int(strlen(str)), i);
    cout<<value<<endl;*/
    
    int num;
    cin>>num;
    
    int fake = num;
    int j = 0;
    
    while(fake>0){
        fake = fake/10;
        j++;
    }
    
    int i=pow(10,j-1);
    string string = "";
    
    string = int2ascii(num, i, string);
    cout<<string<<endl;
    
    return 0;
}
