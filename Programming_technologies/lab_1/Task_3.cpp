#include <iostream>

/*
	������ 3. ���� �������� ������������������, ��������� �� ����� � 
	������ ������ p�������� �������� �����( �(� �{� �[��)� �}� �]�). 
	����������, ����� �� �������� � ��� ����� � ����� �������������� �������� ���, 
	����� ���������� ���������� �������������� ���������.
*/


class Stack
{
public:
	Stack()
	{
		arr = new char[CAPASITY];
		top = -1;
	}

	void push_ba�k(char element) // ���������� �������� 
	{
		if (top == CAPASITY - 1)
		{
			std::cout << "Stack Overflow" << std::endl;
		}
		else
		{
			arr[++top] = element;
		}
	}

	char pop() // �������� ��������
	{
		if (top == -1)
		{
			std::cout << "Stack Underflow" << std::endl;
			return -1;
		}
		else
		{
			return arr[top--];
		}
	}

	char peek() // ������� ������� �����
	{
		if (top == -1)
		{
			std::cout << "Stack is empty" << std::endl;
		}
		else
		{
			return arr[top];
		}
	}

	bool isEmpty() // �������� �� �������
	{
		return top == -1;
	}

	~Stack()
	{
		delete[]arr;
	}
private:
	std::string str;
	char* arr; // ��������� �� ������������ ������
	const int CAPASITY = 100; // ������� �����
	int top; // ������ �������� �������� �����
};

bool isBalanced(std::string sequence)
{
	Stack brackets; // ���� ������
	for (char br : sequence)
	{
		if (br == '(' || br == '{' || br == '[')
			brackets.push_ba�k(br);
		else if (br == ')' || br == '}' || br == ']')
		{
			if (brackets.isEmpty())
				return false;
			
			char top = brackets.peek();
			brackets.pop();

			if ( (br == ')' && top != '(') || (br == '}' && top != '{') || (br == ']' && top != '['))
			{
				return false;
			}
		}
	}
	return brackets.isEmpty();

}
/*
int main()
{
	setlocale(LC_ALL, "ru");
	std::string sequence = "({[]})";
	std::cout << "������� ������������������ ������:" << std::endl;
	//std::cin >> sequence;

	if (isBalanced(sequence))
		std::cout << "������������������ ������ �������� ������!" << std::endl;
	else
		std::cout << "������������������ ������ �� �������� ������!" << std::endl;



	return 0;
}
*/