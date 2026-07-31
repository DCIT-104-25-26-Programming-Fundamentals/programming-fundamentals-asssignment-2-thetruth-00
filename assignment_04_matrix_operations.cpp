// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

using namespace std;

// Global constant for fixed maximum size
const int MAX_SIZE = 10;

// Function Prototypes
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);

int main() {
    int choice;
    
    // Matrix Declarations
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    
    int rowsA, colsA, rowsB, colsB;

    cout << "=== Matrix Operations Menu ===" << endl;
    cout << "1. Part A: Transpose a Matrix" << endl;
    cout << "2. Part B: Add Two Matrices" << endl;
    cout << "3. Part C: Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\n--- PART A: Transpose ---" << endl;
            cout << "Enter number of rows (max 10): "; cin >> rowsA;
            cout << "Enter number of columns (max 10): "; cin >> colsA;
            
            if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
                cout << "Error: Size exceeds maximum limit of 10." << endl;
                break;
            }

            cout << "\nEnter elements for Matrix A:" << endl;
            readMatrix(A, rowsA, colsA);

            cout << "\nOriginal Matrix A:" << endl;
            displayMatrix(A, rowsA, colsA);

            transposeMatrix(A, result, rowsA, colsA);

            cout << "\nTransposed Matrix:" << endl;
            // Rows and columns swap dimensions for the display
            displayMatrix(result, colsA, rowsA);
            break;
        }
        case 2: {
            cout << "\n--- PART B: Matrix Addition ---" << endl;
            cout << "Enter number of rows (max 10): "; cin >> rowsA;
            cout << "Enter number of columns (max 10): "; cin >> colsA;

            if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
                cout << "Error: Size exceeds maximum limit of 10." << endl;
                break;
            }

            cout << "\nEnter elements for Matrix A:" << endl;
            readMatrix(A, rowsA, colsA);

            cout << "\nEnter elements for Matrix B:" << endl;
            readMatrix(B, rowsA, colsA);

            addMatrices(A, B, result, rowsA, colsA);

            cout << "\nResultant Sum Matrix (A + B):" << endl;
            displayMatrix(result, rowsA, colsA);
            break;
        }
        case 3: {
            cout << "\n--- PART C: Matrix Multiplication ---" << endl;
            cout << "Enter rows for Matrix A: "; cin >> rowsA;
            cout << "Enter columns for Matrix A (and rows for Matrix B): "; cin >> colsA;
            cout << "Enter columns for Matrix B: "; cin >> colsB;
            rowsB = colsA; // Required rule for multiplication

            if (rowsA > MAX_SIZE || colsA > MAX_SIZE || colsB > MAX_SIZE) {
                cout << "Error: Size exceeds maximum limit of 10." << endl;
                break;
            }

            cout << "\nEnter elements for Matrix A (" << rowsA << "x" << colsA << "):" << endl;
            readMatrix(A, rowsA, colsA);

            cout << "\nEnter elements for Matrix B (" << rowsB << "x" << colsB << "):" << endl;
            readMatrix(B, rowsB, colsB);

            multiplyMatrices(A, B, result, rowsA, colsA, colsB);

            cout << "\nResultant Product Matrix (A x B):" << endl;
            displayMatrix(result, rowsA, colsB);
            break;
        }
        default:
            cout << "Invalid choice program terminating." << endl;
    }

    return 0;
}

// Helper function to handle grid inputs step-by-step
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "  Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Outputs the grids safely using standard width formatting
void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Swaps row indices with column indices
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// PART B: Basic element-wise matrix addition
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Mathematical dot-product multiplication engine
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize cell element accumulator
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}