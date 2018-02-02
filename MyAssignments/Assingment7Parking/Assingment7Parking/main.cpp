//
//  main.cpp
//  Assingment7Parking
//
//  Created by Gary Hicks on 2018-01-24.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void readCurrent(string currentname[50], int currentnumber[50], ifstream&fin){
    
    for (int i=0;i<50;i++){
        currentname[i]="empty";
        currentnumber[i]=3; // 3 indicates an empty parking spot in the array
    }
    
    int type; //either 0 or 1 indicating student or teacher.
    string name;
    int space;
    
    while(true){
        
        fin>>type>>name>>space;
        if (fin.eof()){
            break;
        }
        currentname[space-1]=name;
        currentnumber[space-1]=type;
    }
    
    /*for (int i=0;i<50;i++){
     cout<<currentname[i]<<setw(25)<<flush;
     }
     cout<<endl<<flush;
     for (int i=0;i<50;i++){
     cout<<currentnumber[i]<<setw(25)<<flush;
     }*/
    
}

int readBoth(int addnumber[50], string addname[50], ifstream&fin, int removenumber[50], string removename[50], int &removeoradd){
    
    int type;
    string name;
    int a=0;
    
    if(removeoradd==0){
        for(int i=0;i<50;i++){
            
            fin>>type>>name;
            if (fin.eof()){
                break;
            }
            addnumber[i]=type;
            addname[i]=name;
            a++;
        }
        
        int size=a;
        
        return size;
    }
    else{
        for(int i=0;i<50;i++){
            
            fin>>type>>name;
            if (fin.eof()){
                break;
            }
            removenumber[i]=type;
            removename[i]=name;
            a++;
        }
        
        int size=a;
        
        return size;
    }
}
void free(string currentname[50],int currentnumber[50], string &toremove){
    for (int i=0;i<50;i++){
        if (currentname[i]==toremove){
            currentname[i]="empty";
            currentnumber[i]=3;
        }
        
    }
}

int find(string currentname[50],int currentnumber[50]){
    int a=-1;
    for (int i=0;i<50;i++){
        if (currentnumber[i]==3){
            return i;
        }
    }
    return a;
}

bool assign(string currentname[50],int currentnumber[50], int addnumber[50], string addname[50], int manyadd,int i){
    
    int freespace;
    freespace=find(currentname,currentnumber);
    
    if (freespace==-1){
        return false;
    }
    else{
        currentname[freespace]=addname[i];
        
        if (addnumber[i]==0){
            currentnumber[freespace]=2;
        }
        else if (addnumber[i]==4){
            currentnumber[freespace]=0;
        }
        else{
            currentnumber[freespace]=addnumber[i];
        }
        return true;
    }
}

void optimize(string currentname[50],int currentnumber[50], int addnumber[50], string addname[50], int &manyadd){
    int i=0;
    
    for(int b=25;b<50;b++){
        if (currentnumber[b]==1){
            addname[i]=currentname[b];
            addnumber[i]=currentnumber[b];
            i++;
            string toremove=currentname[b];
            free(currentname,currentnumber,toremove);
            //bool status=assign(currentname,currentnumber,addnumber,addname,manyadd,i);
        }
    }
    
    for (int a=0;a<26;a++){
        if (currentnumber[a]==2){
            addname[i]=currentname[a];
            addnumber[i]=currentnumber[a];
            //cout<<addname[i]<<endl;
            i++;
            string toremove=currentname[a];
            free(currentname,currentnumber,toremove);
            //bool status=assign(currentname,currentnumber,addnumber,addname,manyadd,i);
        }
    }
    int size=i;
    for (int i=0;i<size;i++){
        bool status=assign(currentname,currentnumber,addnumber,addname,manyadd,i);
        if (status==false){
            break;
        }
    }
    for (int i=0;i<50;i++){
        if (currentnumber[i]==3){
            for (int j=0;j<50;j++){
                if (currentnumber[j]==2){
                    int temp;
                    temp=currentnumber[j];
                    currentnumber[j]=currentnumber[i];
                    currentnumber[i]=1;
                    
                    string stemp;
                    stemp=currentname[j];
                    currentname[j]=currentname[i];
                    currentname[i]=stemp;
                    break;
                }
            }
        }
    }
}



int main() {
    
    ifstream fin;
    fin.open("parking_current.txt");
    
    string currentname[50];
    int currentnumber[50];
    
    readCurrent(currentname,currentnumber,fin);
    fin.close();
    
    int manyadd;
    int manyremove;
    int removeoradd=0;
    int addnumber[50];
    string addname[50];
    int removenumber[50];
    string removename[50];
    
    fin.open("parking_add.txt");
    manyadd = readBoth(addnumber, addname, fin, removenumber,removename, removeoradd);
    fin.close();
    
    removeoradd=1;
    
    fin.open("parking_remove.txt");
    manyremove = readBoth(addnumber, addname, fin, removenumber,removename, removeoradd);
    fin.close();
    
    for (int i=0; i<manyremove;i++){
        string toremove=removename[i];
        free(currentname,currentnumber,toremove);
    }
    
    for (int i=0;i<manyadd;i++){
        bool status=assign(currentname,currentnumber,addnumber,addname,manyadd,i);
        if (status==false){
            break;
        }
    }
    
    optimize(currentname,currentnumber, addnumber, addname, manyadd);
    
    /*for (int i=0;i<50;i++){
     cout<<addname[i]<<setw(25)<<flush;
     }
     cout<<endl<<flush;
     for (int i=0;i<50;i++){
     cout<<addnumber[i]<<setw(25)<<flush;
     }*/
    
    for (int i=0;i<50;i++){
        cout<<currentname[i]<<setw(10)<<flush;
        if (currentnumber[i]==2){
            cout<<1<<setw(10)<<flush;
        }
        else if (currentnumber[i]==3){
            cout<<"N/A"<<setw(10)<<flush;
        }
        else{
            cout<<currentnumber[i]<<setw(10)<<flush;
        }
        cout<<i+1<<endl;
    }
    
    return 0;
    
}
