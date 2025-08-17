/*
 * Calculator.cpp
 *
 *  Date: 11 July 2025
 *  Author: Gerus Hays
 */

#include <iostream>
using namespace std;

// Added function to evaluate and print the result of an expression
void evaluateExpression(int op1, int op2, char operation) {
    switch (operation) {
        case '+':
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
            break;
        case '-':
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
            break;
        case '*':
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
            break;
        case '/':
            if (op2 != 0) // Added division by zero check and ensured we can get decimals when dividing say 5 / 2 = 2.5
                cout << op1 << " / " << op2 << " = " << static_cast<double>(op1) / op2 << endl;
            else
                cout << "Error: Division by zero is undefined." << endl;
            break;
        default:
            cout << "Invalid operator." << endl;
    }
}

int main() {
    int op1, op2;
    char operation;
    char answer = 'y'; // Fixed initialization to single quotes (char literal)

    // Changed from void main() to int main() and added return 0 at the end
    while (answer == 'y') {
        cout << "Enter expression (e.g. 5 + 3): " << endl;

        // Changed input order: user enters operand1, operator, operand2
        cin >> op1 >> operation >> op2;

        // Moved logic to a function for cleaner structure
        evaluateExpression(op1, op2, operation);

        cout << "Do you wish to evaluate another expression? (y/n) " << endl;
        cin >> answer;
    }

    return 0; // Added return statement for int main
}
