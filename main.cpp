//COMSC-210 | Lab 32 | Ahmad Dharhan

#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

const int SIZE = 2;
const int PROB_PAY = 46;
const int PROB_JOIN = 39;
const int SWITCH = 15;
const int NR_LANES = 4;

void choices(deque<Car>& lane, int num);
void display(deque<Car>& lane, int num);

int main(){

    srand(time(0));

    array<deque<Car>,NR_LANES> plaza;

    for(int i = 0; i < NR_LANES; i++){
        for(int j = 0; j < SIZE; j++){
            plaza[i].push_back(Car());
        }
    }

    cout << "Initial queue: " << endl;

    cout << "Lane 1: " << endl;
    for(Car car: plaza[0]){
        cout << "\t";
        car.print();
    }

    cout << "Lane 2: " << endl;
    for(Car car: plaza[1]){
        cout << "\t";
        car.print();
    }

    cout << "Lane 3: " << endl;
    for(Car car: plaza[2]){
        cout << "\t";
        car.print();
    }

    cout << "Lane 4:" << endl;
    for(Car car: plaza[3]){
        cout << "\t";
        car.print();
    }

    cout << endl;
    
    int count = 0;

    while(count != 20){
        count += 1;
        
        cout << "Time " << count << endl;

        for(int i = 0; i < NR_LANES; i++){
            choices(plaza[i], i+1);
        }

        for(int i = 0; i < NR_LANES; i++){
            display(plaza[i],i+1);
        }
    }

    cout << "\tEmpty" << endl;

    return 0;
}

void choices(deque<Car>& lane,int num){
    int probability = rand() % 100;

    cout << "Lane " << num ;
    if(lane.empty()){
        cout << "Empty" << endl;
        return;
    }
    else if(probability > 50){
        cout << " Operation: Car paid: ";
        lane.front().print();
        lane.pop_front();
    }
    else{
        cout << " Operation: Car joined: " << endl;
        lane.push_back(Car());
        lane.back().print();
    }

    cout << endl;
}

void display(deque<Car>& lane,int num){
    cout << "Lane " << num << " Queue: " << endl;

    for(Car car: lane){
        cout << "\t";
        car.print();
    }
}