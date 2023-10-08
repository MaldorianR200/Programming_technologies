#include <iostream>

// ������ 30. ����������� ������� ������ �� ������ (��������, �������).

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
	bool isFull()	// �������� �� ������������ �����
	{
		return top == SIZE - 1;
	}
	void push_back(int value)	// ���������� �������� � ����
	{
		if (isFull())
		{
			std::cout << "���� �����!" << std::endl;
			return;
		}
		this->top += 1;
		this->arr[top] = value;
		std::cout << "�������: " << value << " �������� � ����!" << std::endl;
	}
	void pop()
	{
		if (isEmpty())
		{
			std::cout << "���� ����!" << std::endl;
			return;
		}
		int value = arr[top];
		top--;
		std::cout << "������� " << value << " ����� �� �����!" << std::endl;
	}
	void printStack()
	{
		std::cout << "���������� �����:" << std::endl;
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