#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the input file for reading Fahrenheit temperatures
    ifstream inputFile("FahrenheitTemperature.txt");
    // Open the output file for writing the Celsius results
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if either file failed to open
    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1; // Exit program with error code
    }

    string city; // To hold city name from the file
    int fahrenheit; // To hold temperature in Fahrenheit

    // Read from the file until there is no more data
    while (inputFile >> city >> fahrenheit) {
        // Convert Fahrenheit to Celsius using the given formula
        double celsius = (fahrenheit - 32) * 5.0 / 9.0;
        // Write the city and the Celsius temperature to the output file
        outputFile << city << " " << celsius << endl;
    }

    inputFile.close();
    outputFile.close();
    
    // Notify the user that the conversion is done
    cout << "Conversion complete. Check CelsiusTemperature.txt." << endl;
    return 0;
}