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

    while(!toll.empty()){
        
    }

    return 0;
}

