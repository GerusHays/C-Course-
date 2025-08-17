// Written by Gus Hays
// July 17 2025
// OOP implementation of dual clocks for Chada Tech coding project
// This simulates a 12-hour and 24-hour clock and lets users add time manually

#include <iostream>
#include <iomanip>
using namespace std;

// Clock class handles time and formatting
class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor sets time or defaults to 00:00:00
    Clock(int h = 0, int m = 0, int s = 0) {
        hour = h;
        minute = m;
        second = s;
    }

    // Adds one hour, wraps around after 23 to 0
    void addHour() {
        hour = (hour + 1) % 24;
    }

    // Adds one minute, and adds an hour if it wraps
    void addMinute() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            addHour();
        }
    }

    // Adds one second, and adds a minute if it wraps
    void addSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            addMinute();
        }
    }

    // Displays the 12-hour formatted clock with AM/PM
    void display12Hour() const {
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;  // midnight or noon
        string ampm = (hour < 12) ? "AM" : "PM";

        cout << "*      " << setw(2) << setfill('0') << displayHour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << " " << ampm << "       *";
    }

    // Displays the 24-hour formatted clock
    void display24Hour() const {
        cout << "*       " << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << "        *";
    }
};

// Shows the user interaction menu
void displayMenu() {
    cout << "MENU\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";
    cout << "Enter your choice: ";
}

// Handles printing both clocks side by side
void displayClocks(const Clock& clock) {
    cout << "\n**************************     **************************\n";
    cout << "*     12-Hour Clock      *     *     24-Hour Clock      *\n";

    clock.display12Hour();
    cout << "     ";
    clock.display24Hour();
    cout << "\n";

    cout << "**************************     **************************\n\n";
}

int main() {
    int h, m, s;

    // Grab starting time from the user
    cout << "Enter initial time (HH MM SS): ";
    cin >> h >> m >> s;

    // Set up our clock object with user input
    Clock clock(h, m, s);
    int choice;

    // Loop menu until user exits manually
    while (true) {
        displayClocks(clock);
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                clock.addHour();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addSecond();
                break;
            case 4:
                cout << "\nExiting...\n";
                return 0;  // Bye
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
