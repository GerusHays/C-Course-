#include <iostream>
#include <limits>
#include <string>
#include "ItemTracker.h"

/*
  Corner Grocer – CS210 Project

  Menu:
   1) Prompt for an item (word) and print how many times it appears.
   2) Print the full frequency list (item count).
   3) Print the histogram using asterisks.
   4) Exit.

  Notes from me:
   - I load the file once at program start and immediately write a backup
     "frequency.dat" so I always have the pre-computed counts.
   - I validate menu input so I don’t crash on a random letter.
   - Lookups are forgiving (case-insensitive), but stored keys keep their original
     casing from the input file so output matches the provided data.
*/

static const std::string kInputPath  = "data/Input.txt";
static const std::string kBackupPath = "frequency.dat";

// Small helper: get an int menu choice
int GetMenuChoice() {
    std::cout << "\n===== CORNER GROCER MENU =====\n";
    std::cout << "1 - Search for an item’s frequency\n";
    std::cout << "2 - Print all item frequencies\n";
    std::cout << "3 - Print histogram\n";
    std::cout << "4 - Exit\n";
    std::cout << "Choose an option: ";

    int choice = 0;
    while (true) {
        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume leftover newline
            return choice;
        }
        // Bad input or out of range, clear and retry (a little extra here)
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter 1, 2, 3, or 4: ";
    }
}

int main() {
    ItemTracker tracker;

    // Load data at startup
    if (!tracker.LoadFromFile(kInputPath)) {
        std::cerr << "Fatal: unable to continue without input data.\n";
        return 1;
    }

    // Write backup file required by the spec
    if (!tracker.WriteBackupFile(kBackupPath)) {
        std::cerr << "Warning: could not write " << kBackupPath << ". Continuing anyway.\n";
    }

    // Main menu loop
    while (true) {
        int choice = GetMenuChoice();

        if (choice == 1) {
            std::cout << "Enter item to search for: ";
            std::string query;
            std::getline(std::cin, query);

            int count = tracker.CountOf(query);
            std::cout << count << '\n'; // spec: return numeric value of the frequency

        } else if (choice == 2) {
            tracker.PrintAll();

        } else if (choice == 3) {
            tracker.PrintHistogram('*');

        } else if (choice == 4) {
            std::cout << "Goodbye.\n";
            break;
        }
    }

    return 0;
}
