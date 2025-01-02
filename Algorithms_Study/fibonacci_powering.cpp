#include <iostream>
using namespace std;

constexpr int SIZE = 2;

// Matrix multiplication function
void multiply(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    int temp[SIZE][SIZE] = {0}; // Temporary matrix to store the result of multiplication
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Copy result into the result matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

// Function to calculate matrix power
int (*FibPower(int arr[SIZE][SIZE], int power))[SIZE] {
    static int result[SIZE][SIZE] = {0}; // `static` to avoid returning a local variable
    static int temp[SIZE][SIZE]; // Temporary matrix to store multiplication results

    // Initialize result as the identity matrix
    result[0][0] = 1;
    result[0][1] = 0;
    result[1][0] = 0;
    result[1][1] = 1;

    // Matrix exponentiation: multiply result by arr for (power - 1) times
    while (power > 0) {
        if (power % 2 == 1) {
            multiply(result, arr, temp); // Multiply result by arr when the power is odd
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    result[i][j] = temp[i][j];
                }
            }
        }

        multiply(arr, arr, temp); // Square the base matrix
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                arr[i][j] = temp[i][j];
            }
        }
        
        power /= 2; // Reduce the power
    }

    return result; // Return the pointer to the result matrix
}

int main() {
    int arr[SIZE][SIZE] = {{1, 1}, {1, 0}}; // The matrix to raise to a power
    int (*result)[SIZE] = FibPower(arr, 5); // Calculate the power of the matrix

    // Print the result
    cout << "Matrix raised to the power of 5 is:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
