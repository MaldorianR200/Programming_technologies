#include "CSCMatrix.h"

CSCMatrix::CSCMatrix(int rows, int cols)
{
	n = rows;
	m = cols;
	colPointers.resize(cols + 1, 0);
}

void CSCMatrix::inputMatrix()
{
	std::string str;
	int numNonZeros = 0;
	std::cout << "Enter the number of non-zero elements: ";
	do
	{
		std::cin >> str;
		if (!isNumber(str))
		{
			std::cout << "The number of nonzero elements is < 0 or not a number at all. Try again!" << std::endl;
		}
		else
			break;
	} while (true);
	numNonZeros = std::stoi(str);
	std::cout << std::endl;

	std::cout << "Fill in the matrix({format} [row number][column number][value]):" << std::endl;
	std::cout << "Values are entered by columns, i.e. we first pass non-zero values of the first column, then the second, etc." << std::endl;
	for (int i = 0; i < numNonZeros; ++i)    // ¬водим ненуливые значени€
	{
		double value;
		int row, col;
		std::cout << "ROW: " << std::endl;
		do
		{
			std::cin >> str;
			if (!isNumber(str))
			{
				std::cout << "ROW < 0 or not a number at all! Try again!" << std::endl;
			}
			else
			{
				if (std::stoi(str) <= n && std::stoi(str) != 0)
				{
					break;
				}
				else
				{
					std::cout << "Entered number " << std::stoi(str) << " > ROW(" << n << ") or = 0. Try again!" << std::endl;
				}

			}

		} while (true);
		row = std::stoi(str);


		std::cout << "COL: " << std::endl;
		do
		{
			std::cin >> str;
			if (!isNumber(str))
			{
				std::cout << "COL < 0 or not a number at all! Try again!" << std::endl;
			}
			else
				if (std::stoi(str) <= m && std::stoi(str) != 0)
				{
					break;
				}
				else
				{
					std::cout << "Entered number " << std::stoi(str) << " > COL(" << m << ") or = 0. Try again!" << std::endl;
				}
		} while (true);
		col = std::stoi(str);


		std::cout << "VALUE: " << std::endl;
		do
		{
			std::cin >> str;
			if (!isNumber(str))
			{
				std::cout << "VALUE is not a number!. Try again!" << std::endl;
			}
			else
				break;
		} while (true);
		value = std::stoi(str);


		rowIndexes.push_back(row - 1);
		colPointers[col]++;
		values.push_back(value);
	}
	for (int i = 1; i <= n; ++i)		// Calculation of column indexes
	{
		colPointers[i] += colPointers[i - 1];
	}
}
