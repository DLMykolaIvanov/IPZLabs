#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для генерації випадкової матриці
vector<vector<int>> generateRandomMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Випадкові числа від 0 до 9
        }
    }
    return matrix;
}

// Функція для виведення матриці на екран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Функція для множення двох матриць
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0)); // Результуюча матриця
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    
    int rowsA = 3, colsA = 4; // Розмір першої матриці
    int rowsB = 4, colsB = 2; // Розмір другої матриці
    
    // Генерація випадкових матриць
    vector<vector<int>> matrixA = generateRandomMatrix(rowsA, colsA);
    vector<vector<int>> matrixB = generateRandomMatrix(rowsB, colsB);
    
    // Виведення початкових матриць
    cout << "Матриця A:\n";
    printMatrix(matrixA);
    
    cout << "Матриця B:\n";
    printMatrix(matrixB);
    
    // Множення матриць
    vector<vector<int>> result = multiplyMatrices(matrixA, matrixB);
    
    // Виведення результатуючої матриці
    cout << "Результат множення матриць A і B:\n";
    printMatrix(result);
    
    return 0;
}