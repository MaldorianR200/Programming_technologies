#pragma once

#include <iostream>



class MyVector {
	static int counter;
public:
	static int GetCounter();
	MyVector();
	MyVector(int max_size);
	MyVector(int* arr, int size);
	MyVector(const MyVector& right);
	~MyVector();
	int GetElemByIndex(int index)const;
	int& GetElemByIndex(int index);
	void PrintMyVector()const;
	void AddElemToMyVector(int val);
	void RemoveElemFromMyVector(int val);
	void RemoveElemFromBack();
	int GetSize()const { return current; }	
	MyVector& operator= (const MyVector& right);
	int& operator[](int index);
	int operator[](int index)const;
	MyVector operator+ (const MyVector& right)const;
	MyVector& operator += (int a);
	MyVector& operator++();
	MyVector operator++(int);
protected:
	int GetCapacity()const { return max_size; }
private:
	int* arr;
	int max_size;
	int current;
};

int operator+(int left, const MyVector& right);
std::ostream& operator<<(std::ostream& out, const MyVector& obj);
std::istream& operator>> (std::istream& in, MyVector& obj);

