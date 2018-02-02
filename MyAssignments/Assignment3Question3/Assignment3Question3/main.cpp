//
//  main.cpp
//  Assignment3Question3
//
//  Created by Gary Hicks on 2018-01-21.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    
    ifstream fin("taxi.txt");
    if (!fin){
        cout << "Unable to open file"<<endl;
        return 1; // terminate with error
    }
    
    cout<<setw(7)<<"Trip"<<setw(7)<<"Home"<<setw(7)<<"Stops"<<setw(12)<<"Distance"<<setw(12)<<"TotalDist"<<setw(10)<<"Cost"<<setw(20)<<"TotalCost"<<endl;
    //cout<<setprecision(4);
    double DistanceTotal = 0;
    double CostTotal = 0;
    double Long = 0;
    double cheap = 10000;
    
    for (int i=0;i<5;i++){

        cout<<setw(7)<<i+1<<setw(7)<<flush;
        int home;
        fin>>home;
        cout<<home<<setw(7)<<flush;
        int stops;
        fin>>stops;
        double dstops = stops;
        cout<<stops<<setw(7)<<flush;
        double distance = 0;
        double pastx = 0;
        double pasty = 0;
        double DistanceFromDock = 0;
        
        for (int i = stops;i<2*stops;i++){
            double x;
            double y;
            double line;
            fin>>x;
            fin>>y;
            //cout<<x<<setw(7)<<flush;
            //cout<<y<<setw(7)<<flush;
            line = sqrt((x-pastx)*(x-pastx)+(y-pasty)*(y-pasty));
            if (home==1){
                DistanceFromDock = sqrt(x*x+y*y);
            }
            distance = distance + line;
            pastx=x;
            pasty=y;
        }
        cout<<setw(10)<<distance+DistanceFromDock<<flush;
        DistanceTotal = DistanceTotal+distance+DistanceFromDock;
        cout<<setw(10)<<DistanceTotal<<flush;
        double cost = 11*dstops+2.7*(distance+DistanceFromDock);
        cout<<setw(10)<<"$"<<cost<<flush;
        CostTotal = CostTotal + cost;
        cout<<setw(10)<<"$"<<CostTotal<<endl;
        
        if ((distance+DistanceFromDock)>Long){
            Long=distance+DistanceFromDock;
        }
        
        if ((cost)<cheap){
            cheap=cost;
        }
        
    }
    
    for (int i=5;i<78;i++){
        if (((i+6)/10)*10==i+6){
            cout<<setw(7)<<i+1<<setw(7)<<flush;
            int home;
            fin>>home;
            cout<<home<<setw(7)<<flush;
            int stops;
            fin>>stops;
            double dstops = stops;
            cout<<stops<<setw(7)<<flush;
            double distance = 0;
            double pastx = 0;
            double pasty = 0;
            double DistanceFromDock = 0;
            
            for (int i = stops;i<2*stops;i++){
                double x;
                double y;
                double line;
                fin>>x;
                fin>>y;
                //cout<<x<<setw(7)<<flush;
                //cout<<y<<setw(7)<<flush;
                line = sqrt((x-pastx)*(x-pastx)+(y-pasty)*(y-pasty));
                if (home==1){
                    DistanceFromDock = sqrt(x*x+y*y);
                }
                distance = distance + line;
                pastx=x;
                pasty=y;
            }
            cout<<setw(10)<<distance+DistanceFromDock<<flush;
            DistanceTotal = DistanceTotal+distance+DistanceFromDock;
            cout<<setw(10)<<DistanceTotal<<flush;
            double cost = 11*dstops+2.7*(distance+DistanceFromDock);
            cout<<setw(10)<<"$"<<cost<<flush;
            CostTotal = CostTotal + cost;
            cout<<setw(10)<<"$"<<CostTotal<<endl;
            
            if ((distance+DistanceFromDock)>Long){
                Long=distance+DistanceFromDock;
            }
            
            if ((cost)<cheap){
                cheap=cost;
            }
        }
        else{
            //cout<<setw(7)<<i+1<<setw(7)<<flush;
            int home;
            fin>>home;
            //cout<<home<<setw(7)<<flush;
            int stops;
            fin>>stops;
            double dstops = stops;
            //cout<<stops<<setw(7)<<flush;
            double distance = 0;
            double pastx = 0;
            double pasty = 0;
            double DistanceFromDock = 0;
            
            for (int i = stops;i<2*stops;i++){
                double x;
                double y;
                double line;
                fin>>x;
                fin>>y;
                //cout<<x<<setw(7)<<flush;
                //cout<<y<<setw(7)<<flush;
                line = sqrt((x-pastx)*(x-pastx)+(y-pasty)*(y-pasty));
                if (home==1){
                    DistanceFromDock = sqrt(x*x+y*y);
                }
                distance = distance + line;
                pastx=x;
                pasty=y;
            }
            //cout<<setw(10)<<distance+DistanceFromDock<<flush;
            DistanceTotal = DistanceTotal+distance+DistanceFromDock;
            //cout<<setw(10)<<DistanceTotal<<endl;
            double cost = 11*dstops+2.7*(distance+DistanceFromDock);
            CostTotal = CostTotal + cost;
            
            if ((distance+DistanceFromDock)>Long){
                Long=distance+DistanceFromDock;
            }
            
            if ((cost)<cheap){
                cheap=cost;
            }
        }
    }
    
    cout<<"Longest Trip: "<<Long<<endl;
    cout<<"Cheapest Trip: "<<cheap<<endl;

    fin.close();
    return 0;
}

