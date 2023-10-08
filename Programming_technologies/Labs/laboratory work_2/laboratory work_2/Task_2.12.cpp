#include "CSCMatrix.h"


//////////////////////////////////// 2.12 The sparse matrix SC is given. Find its determinant.\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

double determinant(vector<vector<double>>& matrix) {
    int n = matrix.size();
    double det = 0.0;

    // The base case is a 2x2 matrix
    if (n == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        // Recursively calculate the determinant for a matrix of size (n-1)x(n-1)
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
            det += matrix[0][j] * determinant(subMatrix) * (j % 2 == 0 ? 1 : -1); // Algebraic complement
        }
    }

    return det;
}
// // Function for unpacking a CSV format matrix
vector<vector<double>> unpackCSCMatrix(int n, const vector<int>& col_ptr,
    const vector<int>& row_idx,
    const vector<double>& values) {
    vector<vector<double>> matrix(n, vector<double>(n, 0));

    int nz = values.size();  // Number of non-zero elements

    // Unpacking the matrix and filling in the values
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




int main() {
    setlocale(LC_ALL, "ru");
    int rows, cols, size;
    std::string str;
    
    std::cout << "Enter the number of rows of the matrix: ";
    do
    {
        std::cin >> str;
        if (!isNumber(str))
        {
            std::cout << "Error number < 0 or not a number was entered. Try again!" << std::endl;
        }
        else
        {
            break;
        }
    } while (true);
    rows = std::stoi(str);
    
    
    
    std::cout << "Enter the number of columns of the matrix: ";
    do
    {
        std::cin >> str;
        if (!isNumber(str))
        {
            std::cout << "Error number < 0 or not a number was entered. Try again!" << std::endl;
        }
        else
        {
            break;
        }
    } while (true);
    
    cols = std::stoi(str);
    
    std::cout << "Enter the size of the matrix matrix: ";
    do
    {
        std::cin >> str;
        if (!isNumber(str))
        {
            std::cout << "Error number < 0 or not a number was entered. Try again!" << std::endl;
        }
        else
        {
            break;
        }
    } while (true);

    size = std::stoi(str);
    CSCMatrix matrix(size, size);

    matrix.inputMatrix();

    vector<vector<double>>m = unpackCSCMatrix(size, matrix.getColPointers(), matrix.getRowIndexes(), matrix.getValues());
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Determinant: " << determinant(m);
    return 0;
}






