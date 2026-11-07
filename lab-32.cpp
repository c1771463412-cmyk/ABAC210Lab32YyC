// COMSC-210-5293 | Lab 32 | Yuyi Chen

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2;

int main() {
    srand(time(0));

    // Create a deque to store cars in the toll booth lane
    deque<Car> cars;

    // Add two cars to the initial queue
    for (int i = 0; i < INITIAL_CARS; i++) {
        Car newCar;
        cars.push_back(newCar);
    }

    // Display the initial queue
    cout << "Initial queue:" << endl;

    for (int i = 0; i < cars.size(); i++) {
        cout << "    ";
        cars[i].print();
    }

    cout << endl;

    
    // Test accessing the first car
    cout << "First car: ";
    cars.front().print();

    // Test removing the first car
    cars.pop_front();

    cout << "Cars remaining: " << cars.size() << endl;

    return 0;
}