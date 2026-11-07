// COMSC-210-5293 | Lab 32 | Yuyi Chen

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2;
const int LEAVE_CHANCE = 55;
const int PERCENT = 100;

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
    
    // Run the simulation until the queue is empty
    int time = 0;

    while (!cars.empty()) {
        time++;

        // Generate a random number from 0 to 99
        int chance = rand() % PERCENT;

        if (chance < LEAVE_CHANCE) {
            // The first car pays and leaves the lane
            cout << "Time: " << time << " Operation: Car paid: ";
            cars.front().print();

            cars.pop_front();
        }
        else {
            // A new car joins the end of the lane
            Car newCar;
            cars.push_back(newCar);

            cout << "Time: " << time
                 << " Operation: Joined lane: ";
            newCar.print();
        }

        // Display the queue after each time period
        cout << "Queue:" << endl;

        if (cars.empty()) {
            cout << "    Empty" << endl;
        }
        else {
            for (int i = 0; i < cars.size(); i++) {
                cout << "    ";
                cars[i].print();
            }
        }

        cout << endl;
    }

    return 0;
}