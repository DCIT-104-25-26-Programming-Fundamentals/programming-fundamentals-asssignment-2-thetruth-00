// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function Prototypes
void printSingleTable(int num);
void printTablesUpToN(int n);

int main() {
    int targetNum, maxRange;

    // --- PART A: Single Table ---
    cout << "Enter a number for its multiplication table: ";
    cin >> targetNum;
    
    // Validation for Part A
    if (targetNum <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return 0; // Stop execution
    }
    
    printSingleTable(targetNum);
    cout << endl; // Formatting line break

    // --- PART B: Tables from 1 to N ---
    cout << "Enter a number N to print all tables from 1 to N: ";
    cin >> maxRange;
    
    // Validation for Part B
    if (maxRange <= 0) {
        cout << "Error: The value of N must be a positive integer." << endl;
        return 0; // Stop execution
    }

    printTablesUpToN(maxRange);

    return 0;
}

// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; ++i) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }
}

// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
void printTablesUpToN(int n) {
    for (int i = 1; i <= n; ++i) {
        printSingleTable(i);
        
        // Print a separator line after every table except the last one
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}