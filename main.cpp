//COMSC-210 | Lab 32 | Ahmad Dharhan

#include "Car.h"
#include <iostream>
#include <deque>
#include <random>

using namespace std;

const int SIZE = 2;

int main(){

    int num;

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
        int probability = rand() % 100;

        if(probability < 55){
            
        }
        else if (probability > 55){

        }
    }

    return 0;
}

