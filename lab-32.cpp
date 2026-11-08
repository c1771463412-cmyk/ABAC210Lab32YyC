// COMSC-210-5293 | Lab 33 | Yuyi Chen

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2;
const int LEAVE_CHANCE = 55;
const int PERCENT = 100;
const int NUM_LANES = 4;

int main() {
    srand(time(0));
    
    // Create an array of deques for four toll booth lanes
    deque<Car> lanes[NUM_LANES];

    // Test adding a car to each lane
    for (int i = 0; i < NUM_LANES; i++) {
        Car newCar;
        lanes[i].push_back(newCar);
    }

    // Test displaying the first car in each lane
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ": ";
        lanes[i].front().print();
    }

    // Test removing a car from the first lane
    lanes[0].pop_front();

    cout << "Lane 1 size: " << lanes[0].size() << endl;
    cout << "Lane 2 size: " << lanes[1].size() << endl;

    return 0;
}