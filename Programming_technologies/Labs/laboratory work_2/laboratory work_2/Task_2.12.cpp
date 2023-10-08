#include "Vector.h"

// 2.12 ���� ����������� ������� �SC. ����� � ������������. 



double determinant(vector<vector<double>>& matrix) {
    int n = matrix.size();
    double det = 0.0;

    // ������� ������ - ������� 2x2
    if (n == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        // ���������� ��������� ������������ ��� ������� �������� (n-1)x(n-1)
        for (int j = 0; j < n; j++) {
            vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));
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
vector<vector<double>> unpackCSCMatrix(int n, const vector<int>& col_ptr,
    const vector<int>& row_idx,
    const vector<double>& values) {
    vector<vector<double>> matrix(n, vector<double>(n, 0));

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
    int rows, cols, size;
    std::string str;
    
    std::cout << "������� ���������� ����� �������: ";
    do
    {
        std::cin >> str;
        if (!isNumber(str))
        {
            std::cout << "������ ����� < 0 ��� ������� �� �����. ��������� �������!" << std::endl;
        }
        else
        {
            break;
        }
    } while (true);
    rows = std::stoi(str);
    
    
    
    std::cout << "������� ���������� �������� �������: ";
    do
    {
        std::cin >> str;
        if (!isNumber(str))
        {
            std::cout << "������ ����� < 0 ��� ������� �� �����. ��������� �������!" << std::endl;
        }
        else
        {
            break;
        }
    } while (true);
    
    cols = std::stoi(str);
    
    std::cout << "������� ������ ������� �������: ";
    do
    {
        std::cin >> str;
        if (!isNumber(str))
        {
            std::cout << "������ ����� < 0 ��� ������� �� �����. ��������� �������!" << std::endl;
        }
        else
        {
            break;
        }
    } while (true);

    size = std::stoi(str);
    CSCMatrix matrix(size, size);

    matrix.inputMatrix();

    vector<vector<double>>m = unpackCSCMatrix(size, matrix.colPointers, matrix.rowIndexes, matrix.values);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "������������: " << determinant(m);
    return 0;
}


*/



/*

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
*/