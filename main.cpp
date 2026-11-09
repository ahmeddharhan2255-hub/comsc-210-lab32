//COMSC-210 | Lab 32 | Ahmad Dharhan

#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

void choices(array<deque<Car>,NR_LANES> plaza, int lane);

const int SIZE = 2;
const int PROB_PAY = 46;
const int PROB_JOIN = 39;
const int SWITCH = 15;
const int NR_LANES = 4;

int main(){

    srand(time(0));

    deque<Car> lane1,lane2,lane3,lane4;
    array<deque<Car>,NR_LANES> plaza = {lane1,lane2,lane3,lane4};


    for(int i = 0; i < SIZE; i++){
        lane1.push_back(Car());
        lane2.push_back(Car());
        lane3.push_back(Car());
        lane4.push_back(Car());
    }

    cout << "Initial queue: " << endl;

    for(Car car: lane1){
        cout << "\t";
        car.print();
    }
    cout << endl;
    
    int count = 0;

    while(count != 20){
        count += 1;
        
        cout << "Time " << count << endl;

        choices(plaza[0],1);
        choices(plaza[1],2);
        choices(plaza[2],3);
        choices(plaza[3],4);

    }

    cout << "\tEmpty" << endl;

    return 0;
}

void choices(deque<Car> lane,int num){
    int probability = rand() % 100;
    int lane_switch = rand() % 4;

    if(probability > PROB_PAY){
        cout << " Operation: Car paid: ";
        lane.front().print();
        lane.pop_front();
    }
    else if(probability < PROB_JOIN && probability > SWITCH){
        cout << " Operation: Car joined: ";
        lane.push_back(Car());
        lane.back().print();
    }
    else{
        switch(lane_switch);
            if (lane_switch == num){
                
            }
    }

    cout << "Queue: " << endl;
        for(Car car: lane){
            cout << "\t";
            car.print();
        }
    cout << endl;
}




