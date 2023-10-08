#include <iostream>

// Задача 30. Реализовать функции работы со стеком (удаление, вставка).

class Stack1
{
public:
	Stack1()
	{
		top = -1;
	}
	bool isEmpty()
	{
		return this->top == -1;
	}
	bool isFull()	// Проверка на заполненость стека
	{
		return top == SIZE - 1;
	}
	void push_back(int value)	// добавление элемента в стек
	{
		if (isFull())
		{
			std::cout << "Стек полон!" << std::endl;
			return;
		}
		this->top += 1;
		this->arr[top] = value;
		std::cout << "Элемент: " << value << " добавлен в стек!" << std::endl;
	}
	void pop()
	{
		if (isEmpty())
		{
			std::cout << "Стек пуст!" << std::endl;
			return;
		}
		int value = arr[top];
		top--;
		std::cout << "Элемент " << value << " удалён из стека!" << std::endl;
	}
	void printStack()
	{
		std::cout << "Содержимое стека:" << std::endl;
		for (int i = top; i >= 0; --i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
private:
	static const int SIZE = 100;
	int arr[SIZE];
	int top;
};
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	Stack1 stack;
//	stack.push_back(1);
//	stack.push_back(2);
//	stack.push_back(3);
//	stack.printStack();
//	return 0;
//}