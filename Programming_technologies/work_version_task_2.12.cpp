//#include "myvector.h"
#include <iostream>
#include <vector>

// 2.12 ���� ����������� ������� �SC. ����� � ������������. 


/*

int main() {
    setlocale(LC_ALL, "ru");


    //MyVector<Element, 100> sparseMatrix;        // �������� ���������� ������
    double det = 0.0;
    int n;
    std::cout << "������� ������ �������: ";
    do
    {
        std::cin >> n;
        if (n <= 1)
        {
            std::cout << "������ ������� < ��� = 1. ������� ����� ������!" << std::endl;
        }
        else
            break;
    } while (true);
    CSCMatrix matrix(n);
    matrix.inputMatrix();

    //std::cout << "Determinant: " << matrix.determinant(sparseMatrix, n) << std::endl;

    return 0;
}
*/
/*
 int temp;
 std::cout << "������� �������[" << i + 1 << "][" << j + 1 << "]: ";     std::cin >> temp;
 matrix.rowIndices[i] = i;
 matrix.colPointers[j] = j;
 matrix.values[i] = temp;
 */





 // ��������� ��� �������� ������� ������� CSC
struct CSCMatrix {
    int n; // ���������� �����
    int m; // ���������� ��������
    std::vector<double> values; // ������ ��������
    std::vector<int> rowIndexes; // ������ �������� �����
    std::vector<int> colPointers; // ������ �������� ��������

    // �����������
    CSCMatrix(int rows, int cols) {
        n = rows;
        m = cols;
        colPointers.resize(cols + 1, 0);
    }

    // ���� �������� �������
    void inputMatrix() {
        std::cout << "������� ���������� ��������� ���������: ";
        int numNonZero;
        std::cin >> numNonZero;

        std::cout << "������� �������� ��������� ���������:\n";
        for (int i = 0; i < numNonZero; i++) {
            double value;
            int row, col;
            std::cout << "ROW: "; std::cin >> row;
            std::cout << "COL: "; std::cin >> col;
            std::cout << "VALUE: "; std::cin >> value;


            values.push_back(value);
            rowIndexes.push_back(row - 1);
            colPointers[col]++;
        }

        // ���������� �������� ��������
        for (int i = 1; i <= m; i++) {
            colPointers[i] += colPointers[i - 1];
        }
    }
};

/*
std::vector<std::vector<int>> getMinor(std::vector<std::vector<int>>& matrix, int row, int col) {
    std::vector<std::vector<int>> minor;
    for (int i = 0; i < matrix.size(); i++) {
        if (i != row) {
            std::vector<int> temp;
            for (int j = 0; j < matrix.size(); j++) {
                if (j != col) {
                    temp.push_back(matrix[i][j]);
                }
            }
            minor.push_back(temp);
        }
    }
    return minor;
}

// ������� ��� ������� ������������ �������
int determinant(std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    // ������� ������ - ������� �������� 1x1
    if (size == 1) {
        return matrix[0][0];
    }
    // ������� ������ - ������� �������� 2x2
    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;
    int sign = 1;

    // ���������� ��������� ������������ ��������� ������ ������ �� �� ������
    for (int i = 0; i < size; i++) {
        std::vector<std::vector<int>> minor = getMinor(matrix, 0, i);
        det += sign * matrix[0][i] * determinant(minor);
        sign = -sign;
    }

    return det;
}
*/
double determinant(std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    double det = 0.0;

    // ������� ������ - ������� 2x2
    if (n == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        // ���������� ��������� ������������ ��� ������� �������� (n-1)x(n-1)
        for (int j = 0; j < n; j++) {
            std::vector<std::vector<double>> subMatrix(n - 1, std::vector<double>(n - 1));
            for (int row = 1; row < n; row++) {
                int colIndex = 0;
                for (int col = 0; col < n; col++) {
                    if (col != j) {
                        subMatrix[row - 1][colIndex++] = matrix[row][col];
                    }
                }
            }
            det += matrix[0][j] * determinant(subMatrix) * (j % 2 == 0 ? 1 : -1); // �������������� ����������
        }
    }

    return det;
}
// ������� ��� ���������� ������� ������� CSC
std::vector<std::vector<double>> unpackCSCMatrix(int n, const std::vector<int>& col_ptr,
    const std::vector<int>& row_idx,
    const std::vector<double>& values) {
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n, 0));

    int nz = values.size();  // ���������� ��������� ���������

    // ���������� ������� � ���������� ��������
    for (int j = 0; j < n; j++) {
        int col_start = col_ptr[j];
        int col_end = (j == n - 1) ? nz : col_ptr[j + 1];

        for (int i = col_start; i < col_end; i++) {
            int row = row_idx[i];
            int value = values[i];

            matrix[row][j] = value;
        }
    }

    return matrix;
}
/*
int main() {
    setlocale(LC_ALL, "ru");
    int rows, cols;

    std::cout << "������� ���������� ����� �������: ";
    std::cin >> rows;

    std::cout << "������� ���������� �������� �������: ";
    std::cin >> cols;

    CSCMatrix matrix(rows, cols);

    matrix.inputMatrix();

    std::vector<std::vector<double>>m = unpackCSCMatrix(rows, matrix.colPointers, matrix.rowIndexes, matrix.values);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "������������: " << determinant(m);
    return 0;
}
*/