//COMSC-210 | Lab 32 | Ahmad Dharhan

#include Car.h
#include <iostream>
#include <deque>

using namespace std;

const int SIZE = 2;

int main(){

    deque<Car> toll;

    for(int i = 0; i < SIZE; i++){
        toll.push_back(Car());
    }

    return 0;
}

