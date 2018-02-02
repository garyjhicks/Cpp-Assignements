//
//  main.cpp
//  Assignment5Question2
//
//  Created by Gary Hicks on 2018-01-24.
//  Copyright © 2018 Gary Hicks. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int hours(int time_hhmmss){
    
    int hh = time_hhmmss/10000;
    return hh;
}

int minutes(int time_hhmmss){
    
    int hh = time_hhmmss/10000;
    int mm = (time_hhmmss-(hh*10000))/100;
    return mm;
}

int seconds(int time_hhmmss){
    
    int hh = time_hhmmss/10000;
    int mm = (time_hhmmss-(hh*10000))/100;
    int ss = time_hhmmss-(hh*10000)-(mm*100);
    return ss;
}

double x_coordinate(double heading, double distance){
    double xpos = distance*(cos(heading*3.1415927/180));
    return xpos;
}

double y_coordinate(double heading, double distance){
    double ypos = distance*(sin(heading*3.1415927/180));
    return ypos;
}

int get_duration(int start_hours,int start_minutes,int start_seconds,int end_hours,int end_minutes,int end_seconds){
    
    if (end_hours>=start_hours){
        int end = end_hours*3600+end_minutes*60+end_seconds;
        //cout<<end<<setw(10);
        int start = start_hours*3600+start_minutes*60+start_seconds;
        //cout<<start<<setw(10);
        int difference =end-start;
        return difference;
    }
    else{
        int end = (end_hours+24)*3600+end_minutes*60+end_seconds;
        int start = start_hours*3600+start_minutes*60+start_seconds;
        int difference =end-start;
        return difference;
    }
}

int main() {
    
    ifstream fin("wascally_wabbits.txt");
    if (!fin){
        cout << "Unable to open file"<<endl;
        return 1; // terminate with error
    }
    int pastRabbit =0;
    int start_hours=0;
    int start_minutes=0;
    int start_seconds=0;
    
    while(true){
        
        int Rabbit;
        fin>>Rabbit;
        if (fin.eof()){
            break;
        }
        cout << Rabbit << flush;
        
        //cout<<Rabbit<<setw(5)<<flush;
        
        int time_hhmmss;
        fin>>time_hhmmss;
        
        int hh = hours(time_hhmmss);
        if (hh>=10){
           cout<<setw(5)<<hh<<":"<<flush;
        }
        else{
            cout<<setw(5)<<"0"<<hh<<":"<<flush;
        }
        int end_hours = hh;
        
        int mm = minutes(time_hhmmss);
        if (mm>=10){
            cout<<mm<<":"<<flush;
        }
        else{
            cout<<"0"<<mm<<":"<<flush;
        }
        int end_minutes = mm;
        
        int ss = seconds(time_hhmmss);
        if (ss>=10){
            cout<<ss<<setw(5)<<flush;
        }
        else{
            cout<<"0"<<ss<<setw(5)<<flush;
        }
        int end_seconds = ss;
        
        double heading;
        fin>>heading;
        double distance;
        fin>>distance;
        
        double xpos=x_coordinate(heading, distance);
        cout<<"("<<xpos<<", "<<flush;
        
        double ypos=y_coordinate(heading, distance);
        cout<<ypos<<")"<<setw(10)<<flush;
        
        double difference;
        
        if (pastRabbit==Rabbit){
            difference = get_duration(start_hours, start_minutes, start_seconds,  end_hours, end_minutes, end_seconds);
            start_hours=end_hours;
            start_minutes=end_minutes;
            start_seconds=end_seconds;
            pastRabbit=Rabbit;
        }
        else{
            difference = 0;
            start_hours=end_hours;
            //cout<<start_hours;
            start_minutes=end_minutes;
            //cout<<start_minutes;
            start_seconds=end_seconds;
            //cout<<start_seconds;
            pastRabbit=Rabbit;
        }
        cout<<difference<<endl<<endl;
        
    }
    
    return 0;
}
