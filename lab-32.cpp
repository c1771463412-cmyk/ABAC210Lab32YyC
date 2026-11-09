// COMSC-210-5293 | Lab 33 | Yuyi Chen

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2;
const int NUM_LANES = 4;
const int TIME_PERIODS = 20;

const int PAID_CHANCE = 46;
const int JOIN_CHANCE = 39;
const int SWITCH_CHANCE = 15;
const int PERCENT = 100;


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
                // Empty lanes have a 50% chance of getting a car
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
            else if (chance < PAID_CHANCE) {
                // The first car pays and leaves the lane
                cout << "Lane: " << i + 1 << " Paid: ";
                lanes[i].front().print();

                lanes[i].pop_front();
            }
            else if (chance < PAID_CHANCE + JOIN_CHANCE) {
                // A new car joins the end of the lane
                Car newCar;
                lanes[i].push_back(newCar);

                cout << "Lane: " << i + 1 << " Joined: ";
                newCar.print();
            }
            else {
                // The last car switches to another lane
                int newLane = rand() % NUM_LANES;

                // Make sure the car switches to a different lane
                while (newLane == i) {
                    newLane = rand() % NUM_LANES;
                }

                // Save the last car before removing it
                Car switchingCar = lanes[i].back();
                lanes[i].pop_back();

                // Add the car to the end of the new lane
                lanes[newLane].push_back(switchingCar);

                cout << "Lane: " << i + 1 << " Switched: ";
                switchingCar.print();
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