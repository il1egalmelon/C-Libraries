#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;

const int MAX_SIZE = 10;

void inputMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

void addMatrix(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subMatrix(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void mulMatrix(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void divMatrix(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] / matrix2[i][j];
        }
    }
}

void matrix_main() {
    int size;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    cout << "Enter size of matrix: ";
    cin >> size;

    cout << "\nEnter the first matrix:\n";
    inputMatrix(matrix1, size);

    cout << "\nEnter the second matrix:\n";
    inputMatrix(matrix2, size);

    cout << "\nFirst matrix:\n";
    outputMatrix(matrix1, size);

    cout << "\nSecond matrix:\n";
    outputMatrix(matrix2, size);

    addMatrix(matrix1, matrix2, result, size);
    cout << "\nAddition of the two matrices:\n";
    outputMatrix(result, size);

    subMatrix(matrix1, matrix2, result, size);
    cout << "\nSubtraction of the two matrices:\n";
    outputMatrix(result, size);

    mulMatrix(matrix1, matrix2, result, size);
    cout << "\nMultiplication of the two matrices:\n";
    outputMatrix(result, size);

    divMatrix(matrix1, matrix2, result, size);
    cout << "\nDivision of the two matrices:\n";
    outputMatrix(result, size);
}
