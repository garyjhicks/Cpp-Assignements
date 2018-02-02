//
//  main.cpp
//  Assignment8Question1
//
//  Created by Gary Hicks on 2018-01-26.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

void ReadElevation(ifstream&fin,int elevation[50][25]){
    for(int i = 0;i<50;i++){
        for (int j=0;j<25;j++){
            fin>>elevation[i][j];
        }
    }
}
int ReadCache(ifstream&fin,int cache[50][25],int sizecache){
    for(int i = 0;i<50;i++){
        for (int j=0;j<25;j++){
            fin>>cache[i][j];
            if (cache[i][j]==1){
                sizecache++;
            }
        }
    }
    return sizecache;
}

double energynum(int startx,int starty, int endx, int endy,int elevation[50][25]){
    double energy= sqrt((endx-startx)*(endx-startx)+(endy-starty)*(endy-starty))+7*sqrt((elevation[endx][endy]-elevation[startx][starty])*(elevation[endx][endy]-elevation[startx][starty]));
    return energy;
}

bool find(int &startx,int &starty, int elevation[50][25],int cache[50][25]){
    int max=10000000;
    int nextx;
    int nexty;
    for (int i=0;i<50;i++){
        for (int j=0;j<25;j++){
            if (cache[i][j]==1){
                int endx=i;
                int endy=j;
                int energy;
                energy=energynum(startx,starty,endx,endy,elevation);
                if (energy<max){
                    max=energy;
                    nextx=endx;
                    nexty=endy;
                }
            }
        }
    }
    if (max!=10000000){
        startx=nextx;
        starty=nexty;
        cache[nextx][nexty]=0;
        return true;
    }
    else{
        return false;
    }
}

void optimize(int elevation[50][25],int cache[50][25],int sizecache){
    int final[sizecache][2];
    int startx=0;
    int starty=0;
    for (int i=0; i<sizecache;i++){
        bool status=find(startx, starty, elevation, cache);
        if (status==true){
            final[i][0]=startx;
            final[i][1]=starty;
        }
    }
    for(int i = 0;i<sizecache;i++){
        for (int j=0;j<2;j++){
            if (j==1){
                cout<<final[i][j]<<flush;
            }
            else{
              cout<<final[i][j]<<setw(5)<<flush;
            }
        }
        cout<<endl;
    }
}


int main() {
    
    ifstream fin;
    int elevation[50][25];
    int cache[50][25];
    int sizecache=0;
    
    fin.open("elevations.txt");
    ReadElevation(fin,elevation);
    fin.close();
    
    fin.open("caches.txt");
    sizecache=ReadCache(fin,cache,sizecache);
    fin.close();
    
    /*for(int i = 0;i<50;i++){
     for (int j=0;j<25;j++){
     cout<<cache[i][j]<<setw(1)<<flush;
     }
     cout<<endl;
     }*/
    
    
    //int energy;
    //energy=energynum(startx,starty,endx,endy,elevation);
    
    //bool status=find(startx, starty, elevation, cache);
    
    optimize(elevation,cache,sizecache);
    
    
    return 0;
}
