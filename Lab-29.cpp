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
// Begin a time-based simulation for attendance changes
    // For 25 minute intervals
        // Iterate through random attendance events:
    for(int t = 0; t < periods; t++) {
        for (auto& [team, lists] : gameFans) {
            int action = rand() % 3;
            
            // Sometimes add a few new fans
            if (action == 0) {
                string newFan = "Fan" + to_string(rand() % 900 + 100);
                lists[2].push_back(newFan);
                cout << "New fan joined " << team << ": " << newFan << endl;
            }
            // Sometimes remove a few existing fans


            // Sometimes convert a new fan into a casual fan


        }
    }
    // Print what happened this time period, e.g. "3 new fans joined the Sharks vs Kings game."

    // After all time periods, display the final results of attendance
    // Show how many fans total came for each type
    cout << "Simulation function placeholder.\n";
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

    cout << "Before "
         << gameFans["Ducks"][0].size() << " season, "
         << gameFans["Ducks"][1].size() << " casual, "
         << gameFans["Ducks"][2].size() << " new fans.\n";

    simulateAttendanceChanges(gameFans, 1);
    
    cout << "After: "
         << gameFans["Ducks"][0].size() << " season, "
         << gameFans["Ducks"][1].size() << " casual, "
         << gameFans["Ducks"][2].size() << " new fans.\n";
         
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
    string opponent, type, fanID;
    stringstream ss(line);
    getline(ss, opponent, ',');
    getline(ss, type, ',');
    getline(ss, fanID, ',');

    if(type == "season")
        gameFans[opponent][0].push_back(fanID);
    else if (type == "casual")
        gameFans[opponent][1].push_back(fanID);
    else if (type == "new")
        gameFans[opponent][0].push_back(fanID);

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