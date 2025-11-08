// Include necessary headers
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

// Define constants
const int NUM_PERIODS = 25; // 25 game nights

// Define function to simulate attendance changes overtime
// simulateAttendanceChanges(map, periods)
// Parameters: map of opponent teams, number of games (time periods)
void simulateAttendanceChanges(map<string, array<list<string>, 3>>& gameFans, int periods) {
    srand(time(0));
// Begin a time-based simulation for attendance changes
    // For 25 minute intervals
        // Iterate through random attendance events:
    for(int t = 0; t < periods; t++) {
        for (auto& [opponent, lists] : gameFans) {
            int action = rand() % 3;
            
            // Sometimes add a few new fans (promotion)
            if (action == 0) {
                string newFan = "Fan" + to_string(rand() % 900 + 100);
                lists[2].push_back(newFan);
                cout << "[Promotion] New fan joined Sharks vs " << opponent << ": " << newFan << endl;
            }
            // Sometimes remove a few existing fans (bad weather)
            else if (action == 1 && !lists[1].empty()) {
                cout << "[Weather] Casual fan removed from Sharks vs" << opponent << ": " << lists[1].back() << endl;
                lists[1].pop_back();
            }

            // Sometimes convert a new fan into a casual fan (loyalty shift)
             else if (action == 2 && !lists[2].empty()) {
                string fan = lists[2].front();
                lists[2].pop_front();
                lists[1].push_back(fan);
                cout << "[Loyalty] Converted " << fan << " from new to casual for Sharks" << endl;
            }
            // Winning streak: extra casual fans join
            else if (action == 3) {
                string fan = "Fan" + to_string(rand() % 900 + 100);
                lists[0].push_back(fan);
                cout << "[Winning Streak] New fan joined Sharks" << endl;
            }
        }
    }
    // Print what happened this time period, e.g. "3 new fans joined the Sharks vs Kings game."
    // After all time periods, display the final results of attendance
    // Show how many fans total came for each type
    cout << "Simulation complete. Final totals:\n";
    for (auto& [opponent, lists] : gameFans) {
        cout << " Sharks vs "<< opponent
             << " -Season: " << lists[0].size()
             << ", Casual: " << lists[1].size()
             << ", New: " << lists[2].size() << endl;
    }
}
// End of function

// Define main function:
int main() {
    // Initialize a map to store hockey game information
    map<string, array<list<string>, 3>> gameFans;
        // Each opponent name (like "Ducks", "Kings", etc.) will be the map key
        // The value will be an array of three lists:
            // [0] = season ticket holders
            // [1] = casual fans
            // [2] = new fans
         
    // Open an external file called fans.txt to read initial fan data
        // If the file doesn't open, print an error message and exit the program
    ifstream file("fans.txt");
    if (!file.is_open()) {
        cout << "Error: could not open fans.txt\n";
        return 1;
    }

    // Read data from file and populate map by extracting opponent name, fan type, and fan ID
        // Insert the fan ID into the correct list (season, casual, or new)
            // Read each line from the file using getline
            // Split the line at commas into opponent, fan type, fan ID
    string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        string opponent, type, fanID;
        stringstream ss(line);

        std::getline(ss, opponent, ',');
        std::getline(ss, type, ',');
        std::getline(ss, fanID, ',');

        if(type == "season")
            gameFans[opponent][0].push_back(fanID);
        else if (type == "casual")
            gameFans[opponent][1].push_back(fanID);
        else if (type == "new")
            gameFans[opponent][2].push_back(fanID);
    }

    // Close the file
    file.close();

    // Display the initial state of attendance
        // For each opponent, print how many fans are in each list
    for (auto& [team, lists] : gameFans) {
        cout << "Opponent: " << team << endl;
        cout << " Season fans: " << lists[0].size() << endl;
        cout << " Casual fans: " << lists[1].size() << endl;
        cout << " New fans: " << lists[2].size() << endl;
    }
    // Call simulateAttendanceChanges with the map and 25 time periods
        // This will run the time-based simulation
    simulateAttendanceChanges(gameFans, NUM_PERIODS);

    // After the simulation, display the final attendance results
        // For each opponent, show the total fans in each category
        // e.g. "Sharks vs Ducks - Season: 15, Casual: 20, New: 10"

    return 0;
}

// End of main function
// End of program