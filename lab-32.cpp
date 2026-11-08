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
const int TIME_PERIODS = 20;

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

    // Run the simulation for 20 time periods
    for (int time = 1; time <= TIME_PERIODS; time++) {
        cout << "Time: " << time << endl;

        // Perform an operation on each lane
        for (int i = 0; i < NUM_LANES; i++) {
            int chance = rand() % PERCENT;

            if (lanes[i].empty()) {
                // An empty lane has a 50% chance of getting a car
                if (chance < PERCENT / 2) {
                    Car newCar;
                    lanes[i].push_back(newCar);

                    cout << "Lane: " << i + 1 << " Joined: ";
                    newCar.print();
                }
                else {
                    cout << "Lane: " << i + 1
                         << " No change" << endl;
                }
            }
            else if (chance < PERCENT / 2) {
                // The first car pays and leaves the lane
                cout << "Lane: " << i + 1 << " Paid:   ";
                lanes[i].front().print();

                lanes[i].pop_front();
            }
            else {
                // A new car joins the end of the lane
                Car newCar;
                lanes[i].push_back(newCar);

                cout << "Lane: " << i + 1 << " Joined: ";
                newCar.print();
            }
        }

        // Display all lanes after each time period
        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane " << i + 1 << " Queue:" << endl;

            if (lanes[i].empty()) {
                cout << "    empty" << endl;
            }
            else {
                for (int j = 0; j < lanes[i].size(); j++) {
                    cout << "    ";
                    lanes[i][j].print();
                }
            }
        }

        cout << endl;
    }

    return 0;
}