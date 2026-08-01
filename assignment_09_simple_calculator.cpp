// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Function prototypes for arithmetic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int performModulus(int a, int b);
double power(double base, double exponent);

// Helper function to handle number input collection safely
void getTwoNumbers(double &num1, double &num2);

int main() {
    int choice;
    double num1, num2;

    do {
        cout << "\n============================\n";
        cout << "       SIMPLE CALCULATOR\n";
        cout << "============================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cout << "Invalid entry. Please input a numerical selection.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Set formatting to 2 decimal places as required
        cout << fixed << setprecision(2);

        switch (choice) {
            case 1:
                getTwoNumbers(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << "\n";
                break;
            case 2:
                getTwoNumbers(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << "\n";
                break;
            case 3:
                getTwoNumbers(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << "\n";
                break;
            case 4:
                getTwoNumbers(num1, num2);
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero.\n";
                } else {
                    cout << "Result: " << num1 << " / " << num2 << " = " << divide(num1, num2) << "\n";
                }
                break;
            case 5:
                getTwoNumbers(num1, num2);
                // Cast operands to integers for modulus behavior operations
                if (static_cast<int>(num2) == 0) {
                    cout << "Error: Cannot divide by zero.\n";
                } else {
                    int intNum1 = static_cast<int>(num1);
                    int intNum2 = static_cast<int>(num2);
                    cout << "Result: " << intNum1 << " % " << intNum2 << " = " << performModulus(intNum1, intNum2) << "\n";
                }
                break;
            case 6:
                getTwoNumbers(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << power(num1, num2) << "\n";
                break;
            case 7:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Choose an option between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}

// Prompt & collect inputs cleanly
void getTwoNumbers(double &num1, double &num2) {
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
}

// 1. Addition
double add(double a, double b) {
    return a + b;
}

// 2. Subtraction
double subtract(double a, double b) {
    return a - b;
}

// 3. Multiplication
double multiply(double a, double b) {
    return a * b;
}

// 4. Division
double divide(double a, double b) {
    return a / b;
}

// 5. Modulus
int performModulus(int a, int b) {
    return a % b;
}

// 6. Exponentiation
double power(double base, double exponent) {
    return pow(base, exponent);
}