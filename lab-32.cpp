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

    // Add two cars to each toll booth lane
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            Car newCar;
            lanes[i].push_back(newCar);
        }
    }

    // Display the initial queue for all lanes
    cout << "Initial queue:" << endl;

    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":" << endl;

        for (int j = 0; j < lanes[i].size(); j++) {
            cout << "    ";
            lanes[i][j].print();
        }
    }

    cout << endl;

    return 0;
}