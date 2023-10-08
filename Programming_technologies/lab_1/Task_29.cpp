#include <iostream>

/*
Задача 29. Реализовать удаление элементов из очереди с приоритетом. 
Очередь с приоритетом – первым включается – с высшим приоритетом исключается 
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
			std::cout << "Очередь с приоритетом полна!" << std::endl;
			return;
		}
		int i = size - 1;	// добавление элемента в очередь
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
			std::cout << "Очередь пустая!" << std::endl;
			return -1;
		}
		int value = arr[0];
		for (int i = 0; i < size - 1; ++i)		// удаление элемента из очереди
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
			std::cout << "Очередь пустая!" << std::endl;
			return;
		}
		std::cout << "Очередь с приоритетом:" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	int* arr;	// массив для хранения элементов
	int capacity;		// размер массива
	int size;		// число элементов в очереди
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