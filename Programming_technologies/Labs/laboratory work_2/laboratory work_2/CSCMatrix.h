#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
using std::vector;


bool isNumber(std::string str)		// checking a string for a number
{
	for (char const& c : str)
	{
		if (c == '-')
		{
			for (int i = 1; i < str.size(); ++i)
			{
				if (std::isdigit(str[i]) == false)
					return false;
			}
			return true;
		}
		if (std::isdigit(c) == false)
			return false;
	}
	return true;
}


class CSCMatrix {

public:
	CSCMatrix(int rows, int cols);

	void inputMatrix();		// Entering the matrix data
	
	std::vector<double> getValues(){ return values; }
	std::vector<int> getRowIndexes(){ return rowIndexes; }
	std::vector<int> getColPointers() { return colPointers; }
private:
	int n; // Number of rows
	int m; // Number of columns
	std::vector<double> values; // Array of values
	std::vector<int> rowIndexes; // Array of row indexes
	std::vector<int> colPointers; // Array of column indexes

};