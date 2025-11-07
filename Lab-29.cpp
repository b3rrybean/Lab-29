// Include necessary headers

// Define constants

// Define function to simulate attedance changes overtime
    // simulateAttendanceChanges(map, periods)
    // Parameters: map of opponent teams, number of games (time periods)


// Define main function:
    // Initialize a map to store hockey game information
        // Each opponent name (like "Ducks", "Kings", etc.) will be the map key
        // The value will be an array of three lists:
            // [1] = season ticket holders
            // [2] = casual fans
            // [3] = new fans

// Open an external file called fans.txt to read initial fan data
    // If the file doesn't open, print an error message and exit the program
// Read data from file and populate map by extracting opponent name, fan type, and fan ID
    // Insert the fan ID into the correct list (season, casual, or first-time)
        // Read each line from the file using getline
        // Split the line at commas into opponent, fan type, fan ID

// Close the file

// Begin a time-based simulation for attendance changes
    // For 25 minute intervals
        // Iterate through random attendance events:
            // Sometimes add a few new fans
            // Sometimes remove a few existing ones
            // Sometimes convert a first-time fan into a casual fan
    // Print what happened this time period, e.g. "3 new fans joined the Sharks vs Kings game."

    // After all time periods, display the final results of attendance
    // Show how many fans total came for each type

// End of function

// I think the simulation function should go up top? not sure yet...

// End of program