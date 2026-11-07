//COMSC-210 | Lab 32 | Ahmad Dharhan

#include "Car.h"
#include <iostream>
#include <deque>
#include <random>

using namespace std;

const int SIZE = 2;

int main(){

    deque<Car> toll;

    for(int i = 0; i < SIZE; i++){
        toll.push_back(Car());
    }

    cout << "Initial queue: " << endl;

    for(Car car: toll){
        cout << "\t";
        car.print();
    }

    int count = 0;

    while(!toll.empty()){
        count += 1;
        
        int probability = rand() % 100;

        if(probability < 55){
            cout << "Time " << count;
            cout << " Operation: Car paid: ";
            toll.front().print();
            toll.pop_front();
        }
        else{
            cout << "Time " << count;
            cout << " Operation: Car joined: ";
            toll.back().print();
            toll.push_back(Car());
        }

        cout << "Queue: " << endl;
        for(Car car: toll){
            cout << "\t";
            car.print();
        }
    }

    return 0;
}

