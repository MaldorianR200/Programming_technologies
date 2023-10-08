#include <iostream>

/*
������ 29. ����������� �������� ��������� �� ������� � �����������. 
������� � ����������� � ������ ���������� � � ������ ����������� ����������� 
*/

class PriorityQueue
{
public:
	PriorityQueue(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		this->arr = new int[capacity];
	}
	~PriorityQueue()
	{
		delete[]arr;
	}
	void add_elem(int value)
	{
		if (isFull())
		{
			std::cout << "������� � ����������� �����!" << std::endl;
			return;
		}
		int i = size - 1;	// ���������� �������� � �������
		while (i >= 0 && arr[i] > value)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = value;
		size++;
	}

	int del_elem()
	{
		if (isEmpty())
		{
			std::cout << "������� ������!" << std::endl;
			return -1;
		}
		int value = arr[0];
		for (int i = 0; i < size - 1; ++i)		// �������� �������� �� �������
		{
			arr[i] = arr[i + 1];
		}
		size--;

		return value;
	}

	bool isEmpty()
	{
		return 0 == capacity;
	}
	bool isFull()
	{
		return size == capacity;
	}
	void print()
	{
		if (isEmpty())
		{
			std::cout << "������� ������!" << std::endl;
			return;
		}
		std::cout << "������� � �����������:" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	int* arr;	// ������ ��� �������� ���������
	int capacity;		// ������ �������
	int size;		// ����� ��������� � �������
};

/*
int main()
{
	setlocale(LC_ALL, "ru");
	PriorityQueue queue(10);
	queue.add_elem(10);
	queue.add_elem(11);
	queue.add_elem(1);
	queue.add_elem(4);
	queue.add_elem(6);
	queue.print();
	queue.del_elem();
	queue.print();
	return 0;
}
*/