// Anyshya Hemphill
// Program 2 - Distance
// This program generates two points in a 2D space, calculates their distances from the origin, and determines which point is closer to the origin.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> // For sqrt
using namespace std;

// Updated input validation function that enforces -10 to 10 range of user entry
int getValidatedInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (value < -10 || value > 10) {
            cout << "Value must be between -10 and 10.\n";
            continue;
        }

        break;
    }
    return value;
}

int main() {
    srand(time(0)); // Seed random number generator
    char again = 'Y';

	while (toupper(again) == 'Y') { // Loop until user decides to quit
        int x1, y1, x2, y2;
        char choice;

        cout << "Do you want to enter the points yourself? (Y/N): ";
		cin >> choice; // Gives the user the option to enter their own values

        if (toupper(choice) == 'Y') {
            x1 = getValidatedInput("Enter x1 (-10 to 10): ");
            y1 = getValidatedInput("Enter y1 (-10 to 10): ");
            x2 = getValidatedInput("Enter x2 (-10 to 10): ");
            y2 = getValidatedInput("Enter y2 (-10 to 10): ");
        }
        else {
            // Generate values between -10 and 10 inclusive
            x1 = (rand() % 21) - 10; 
            y1 = (rand() % 21) - 10;
            x2 = (rand() % 21) - 10;
            y2 = (rand() % 21) - 10;
        }

        cout << "\nPoint 1: (" << x1 << ", " << y1 << ")\n";
        cout << "Point 2: (" << x2 << ", " << y2 << ")\n";

        // Calculate distances
		double distance1 = sqrt(x1 * x1 + y1 * y1); //Uses the sqrt in the cmath library to calculate the distance
        double distance2 = sqrt(x2 * x2 + y2 * y2);

        cout << "\n";
		cout << "Distance of Point 1 to origin: " << distance1 << endl; //Prints the distance of each point to the origin
        cout << "Distance of Point 2 to origin: " << distance2 << endl;

        cout << "\n";

        if (distance1 < distance2) //Compares the distances from the orgin for each point
            cout << "Point 1 is closer to the origin.\n";
        else if (distance2 < distance1)
            cout << "Point 2 is closer to the origin.\n";
        else
            cout << "Both points are equidistant from the origin.\n";

		cout << "\nAgain? (Y/N): "; //Determines if the user wants to repeat the program
        cin >> again;
    }

    return 0;
}


/* Instructions from professor: 
Generate 4 random values: x1,y1,x2, and y2 which are coordinate points: (x1,y1) and (x2,y2) where
each value is an integer between -10 and 10, inclusive.
b. Calculate the distance of each point to the origin
c. Print each point, its distance to the origin & which point (1 or 2) is closer to the origin
d. Loop until the user decides to quit
e. Bonus: allow the user to decide to enter these 4 values or let the program generate them. If the user
enters them, then the values are verified to be numeric
*/
