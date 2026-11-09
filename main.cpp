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
const int NR_LANES = 4;

void choices(array<deque<Car>,NR_LANES>& lane, int num);
void display(deque<Car>& lane, int num);
void laneswitch(array<deque<Car>, NR_LANES>& plaza, int num);

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
        
        cout << "Time: " << count << endl;

        for(int i = 0; i < NR_LANES; i++){
            choices(plaza, i);
        }

        cout << endl;

        for(int i = 0; i < NR_LANES; i++){
            display(plaza[i], i+1);
        }

        cout << endl;
    }


    return 0;
}

void choices(array<deque<Car>,NR_LANES>& lane,int num){
    int probability = rand() % 100;

    if(lane[num].empty()){

        if(probability < 50){
            cout << "Lane: " << num + 1 << " joined" << endl;
            lane[num].push_back(Car());
            lane[num].back().print();
        }
        else{
            cout << "Lane " << num + 1 << " Empty" << endl;
        }

        cout << endl;

        return;

    }
    else if(PROB_PAY > probability){
        cout << "Lane " << num + 1 << " Operation: Car paid: ";
        lane[num].front().print();
        lane[num].pop_front();
    }
    else if(probability < PROB_PAY + PROB_JOIN){
        cout << "Lane " << num + 1 << " Operation: Car joined: ";
        lane[num].push_back(Car());
        lane[num].back().print();
    }
    else{
        laneswitch(lane,num);
    }

    cout << endl;
}

void display(deque<Car>& lane,int num){
    cout << "Lane " << num << " Queue: " << endl;
    if(lane.empty()){
        cout << "\tEmpty" << endl;
        return;
    }
    for(Car car: lane){
        cout << "\t";
        car.print();
    }
}

void laneswitch(array<deque<Car>, NR_LANES>& plaza, int num){
    int newLane = rand() % NR_LANES;

    while(newLane == num){
        newLane = rand() % NR_LANES;
    }

    cout << "Lane: " << num + 1 << " Switched: ";
    plaza[num].back().print();
    cout << endl;
    plaza[newLane].push_back(plaza[num].back());
    plaza[num].pop_back();
}