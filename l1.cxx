#include <iostream>
#include <vector>
#include <climits>
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

// Функція для знаходження оптимального порядку множення матриць
int matrixChainOrder(vector<int>& dims, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][n - 1];
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

// Основна функція
int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int numMatrices = 3 + rand() % 3; // Випадкова кількість матриць (від 3 до 5)
    vector<vector<vector<int>>> matrices(numMatrices);
    vector<int> dimensions(numMatrices + 1);

    // Генерація випадкових матриць з дотриманням умов для множення
    dimensions[0] = 3 + rand() % 3; // Випадкова кількість рядків першої матриці (від 3 до 5)
    for (int i = 0; i < numMatrices; i++) {
        int rows = dimensions[i];
        int cols = 3 + rand() % 3; // Випадкова кількість стовпців (від 3 до 5)
        dimensions[i + 1] = cols;
        matrices[i] = generateRandomMatrix(rows, cols);
    }

    // Виведення початкових матриць
    for (int i = 0; i < numMatrices; i++) {
        cout << "Матриця " << i + 1 << ":\n";
        printMatrix(matrices[i]);
    }

    // Знаходження оптимального порядку множення матриць
    int minCost = matrixChainOrder(dimensions, numMatrices + 1);
    cout << "Мінімальна кількість операцій множення: " << minCost << endl;

    // Множення матриць в заданому порядку
    vector<vector<int>> result = matrices[0];
    for (int i = 1; i < numMatrices; i++) {
        result = multiplyMatrices(result, matrices[i]);
    }

    // Виведення результатуючої матриці
    cout << "Результат множення всіх матриць:\n";
    printMatrix(result);

    return 0;
}
