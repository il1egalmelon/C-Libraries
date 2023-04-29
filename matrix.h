#include <iostream>
#include <iomanip>

namespace matrix {
    using std::setw;

    const int MAX_SIZE = 10;

    void inputMatrix(int matrix[][MAX_SIZE], int size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
                std::cin >> matrix[i][j];
            }
        }
    }

    void outputMatrix(int matrix[][MAX_SIZE], int size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << setw(4) << matrix[i][j];
            }
            std::cout << '\n';
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

        std::cout << "Enter size of matrix: ";
        std::cin >> size;

        std::cout << "\nEnter the first matrix:\n";
        inputMatrix(matrix1, size);

        std::cout << "\nEnter the second matrix:\n";
        inputMatrix(matrix2, size);

        std::cout << "\nFirst matrix:\n";
        outputMatrix(matrix1, size);

        std::cout << "\nSecond matrix:\n";
        outputMatrix(matrix2, size);

        addMatrix(matrix1, matrix2, result, size);
        std::cout << "\nAddition of the two matrices:\n";
        outputMatrix(result, size);

        subMatrix(matrix1, matrix2, result, size);
        std::cout << "\nSubtraction of the two matrices:\n";
        outputMatrix(result, size);

        mulMatrix(matrix1, matrix2, result, size);
        std::cout << "\nMultiplication of the two matrices:\n";
        outputMatrix(result, size);

        divMatrix(matrix1, matrix2, result, size);
        std::cout << "\nDivision of the two matrices:\n";
        outputMatrix(result, size);
    }
}
