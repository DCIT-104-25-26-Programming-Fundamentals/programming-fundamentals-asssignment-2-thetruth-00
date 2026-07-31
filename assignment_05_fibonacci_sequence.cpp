// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function Prototypes
void printFibonacciTerms(int n);
void checkFibonacciNumber(int num);

int main() {
    int n, num;

    // --- PART A: Print the First N Terms ---
    cout << "How many terms? ";
    cin >> n;
    
    // Requirement: N must be a positive integer
    if (n <= 0) {
        cout << "Error: The number of terms must be a positive integer." << endl;
    } else {
        printFibonacciTerms(n);
    }

    cout << endl; // Formatting line break

    // --- PART B: Check if a Number Belongs to the Sequence ---
    cout << "Enter a number to check: ";
    cin >> num;
    checkFibonacciNumber(num);

    return 0;
}

// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
void printFibonacciTerms(int n) {
    long long t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Fibonacci sequence: ";
    for (int i = 1; i <= n; ++i) {
        // Print the current term
        if (i == 1) {
            cout << t1 << " ";
            continue;
        }
        if (i == 2) {
            cout << t2 << " ";
            continue;
        }
        // Calculate subsequent terms
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << " ";
    }
    cout << endl;
}

// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
void checkFibonacciNumber(int num) {
    // Handle negative numbers immediately
    if (num < 0) {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }

    long long t1 = 0, t2 = 1, nextTerm = 0;

    // Handle the base cases directly
    if (num == 0 || num == 1) {
        cout << num << " is a Fibonacci number." << endl;
        return;
    }

    // Generate terms until we match or exceed the target number
    while (nextTerm < num) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    // Verify if the loop stopped on an exact match
    if (nextTerm == num) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

