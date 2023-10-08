#include <iostream>
#include "lib.h"
#include <string>






/*
bool isNumber(std::string str)		// проверка строки на число
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
*/

class CSCMatrix {
public:

	int n; // Количество строк
	int m; // Количество столбцов
	vector<double> values; // Массив значений
	vector<int> rowIndexes; // Массив индексов строк
	vector<int> colPointers; // Массив индексов столбцов

	// Конструктор
	CSCMatrix(int rows, int cols) {
		n = rows;
		m = cols;
		colPointers.resize(cols + 1, 0);
	}

	void inputMatrix()		// Вводим данные матрицы
	{
		std::string str;
		int numNonZeros = 0;
		std::cout << "Введите число ненулевых элементов: ";
		do
		{
			std::cin >> str;
			if (!isNumber(str))
			{
				std::cout << "Число ненулевых элементов < 0 или вовсе не число. Повторите попытку!" << std::endl;
			}
			else
				break;
		} while (true);
		numNonZeros = std::stoi(str);
		std::cout << std::endl;

		std::cout << "Заполните матрицу({формат} [номер строки][номер столбца][значение]):" << std::endl;
		std::cout << "Значения вводятся по столбцам, т.е. передаём сначала ненулевые значения первого столбца потом второго и т.д." << std::endl;
		for (int i = 0; i < numNonZeros; ++i)    // Вводим ненуливые значения
		{
			double value;
			int row, col;
			std::cout << "ROW: " << std::endl; 
			do
			{
				std::cin >> str;
				if (!isNumber(str))
				{
					std::cout << "ROW < 0 или вовсе не число! Повторите попытку!" << std::endl;
				}
				else
				{
					if (std::stoi(str) <= n && std::stoi(str) != 0)
					{
						break;
					}
					else
					{
						std::cout << "Введённое число " << std::stoi(str) << " > ROW(" << n << ") или = 0. Повторите попытку!" << std::endl;
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
					std::cout << "COL < 0 или вовсе не число! Повторите попытку!" << std::endl;
				}
				else
					if (std::stoi(str) <= m && std::stoi(str) != 0)
					{
						break;
					}
					else
					{
						std::cout << "Введённое число " << std::stoi(str) << " > COL(" << m << ") или = 0. Повторите попытку!" << std::endl;
					}
			} while (true);
			col = std::stoi(str);


			std::cout << "VALUE: " << std::endl;
			do
			{
				std::cin >> str;
				if (!isNumber(str))
				{
					std::cout << "VALUE не число!. Повторите попытку!" << std::endl;
				}
				else
					break;
			} while (true);
			value = std::stoi(str);


			rowIndexes.push_back(row-1);
			colPointers[col]++;
			values.push_back(value);
		}
		for (int i = 1; i <= n; ++i)		// Вычисление индексов столбцов
		{
			colPointers[i] += colPointers[i - 1];
		}
	}

	vector<vector<int>> unpackCSCMatrix(int n, const vector<int>& col_ptr,		// распаковка матрицы СSC
		const vector<int>& row_idx,
		const vector<int>& values) {
		vector<vector<int>> matrix(n);

		int nz = values.size();  // Количество ненулевых элементов

		// Распаковка матрицы и заполнение значений
		for (int j = 0; j < n; j++) {
			int col_start = col_ptr[j];
			int col_end = (j == n - 1) ? nz : col_ptr[j + 1];

			for (int i = col_start; i < col_end; i++) {
				int row = row_idx[i];
				int value = values[i];

				matrix[row][j] = value;
			}
		}

		return matrix;		// возвращается двумерный вектор
	}


	
};




template<typename T>	// реализация шаблона для MyVector
class vectorr
{
public:
	vectorr();
	vectorr(int size);
	vectorr(const vectorr& right);
	~vectorr();
	
	T& operator[](int index);
	T operator[](int index)const;
	T& operator= (const vectorr& right);
	void push_back(T val);
	void pop_back();
	int size()const { return current; }
	void PrintMyVector()const;
	void resize(int newSize, int value);


private:
	T* arr;
	int current;
protected:
	int max_size;
};


template<typename T>			
vectorr<T>::vectorr() : current(0) 			// реализация конструктора
{
	arr = new T[max_size];
}

template<typename T>
vectorr<T>::vectorr(int size):max_size(size)
{
	if (max_size <= 0)
	{
		arr = nullptr;
		this->max_size = 0;
		return;
	}
	arr = new T[this->max_size = max_size];
	for (int i = 0; i < this->max_size; ++i)
		arr[i] = 0;
}

template<typename T>
vectorr<T>::~vectorr() { delete[] arr; }		// реализация деструктора

template<typename T>
inline vectorr<T>::vectorr(const vectorr& right) :current(right.current),
max_size(right.max_size)
{
	this->arr = new T[max_size];
	for (int i = 0; i < this->current; ++i)
	this->arr[i] = right.arr[i];
}




template<typename T>
T& vectorr<T>::operator[](int index)		// перегрузка не константного оператора []
{
	
	if (index < 0 || index >= current)
		throw std::out_of_range("index out of range");
	return arr[index];
}

template<typename T>
T vectorr<T>::operator[](int index)const		// перегрузка константного оператора []
{
	if (index < 0 || index >= current)
		throw std::out_of_range("index out of range");
	return arr[index];
}

template<typename T>
void vectorr<T>::push_back(T val)		//	добавление элемента в вектор
{
	
	if (current >= max_size)
		throw std::overflow_error("vector is full");
	if (current == max_size)
	{
		max_size = max_size * 2 + 1;
		T* temp = new T[max_size];
		for (int i = 0; i < current; ++i)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
	}
	arr[current++] = val;
	
}

template<typename T>
void vectorr<T>::pop_back()		//	удаление последнего элемента из вектора
{
	if (current <= 0)
		throw std::underflow_error("vector is empty");
	--current;
}
template<typename T>
inline void vectorr<T>::PrintMyVector() const
{
	for (int i = 0; i < current; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
template<typename T>
inline void vectorr<T>::resize(int newSize, int value)
{
	// метод для изменения размера вектора
	if (newSize == max_size) {
		// размер не изменился
		return;
	}

	T* newData = new T[newSize]; // выделяем новую память
	int minSize = (newSize < max_size) ? newSize : max_size; // находим минимальный размер

	// копируем существующие элементы в новую память
	for (int i = 0; i < minSize; i++) {
		newData[i] = value;
	}

	delete[] arr; // удаляем старую память

	arr = newData; // обновляем указатель на данные
	max_size = newSize; // обновляем размер вектора
}


template<typename T>
T& vectorr<T>::operator=(const vectorr<T>& right)	// перегрузка оператора присваивния
{
	if (this != &right)
	{
		delete[]arr;
		arr = new T[max_size = right.max_size];
		for (int i = 0; i < right.current; ++i)
			arr[i] = right[i];
		current = right.current;
	}
	return *this;
}
