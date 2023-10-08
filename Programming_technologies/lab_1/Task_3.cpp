#include <iostream>

/*
	Задача 3. Дана конечная последовательность, состоящая из левых и 
	правых скобок pазличных заданных типов( «(» «{» «[»«)» «}» «]»). 
	Определить, можно ли добавить в нее цифры и знаки арифметических действий так, 
	чтобы получилось правильное арифметическое выражение.
*/


class Stack
{
public:
	Stack()
	{
		arr = new char[CAPASITY];
		top = -1;
	}

	void push_baсk(char element) // добавление элемента 
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

	char pop() // удаление элемента
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

	char peek() // верхний элемент стека
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

	bool isEmpty() // Проверка на пустоту
	{
		return top == -1;
	}

	~Stack()
	{
		delete[]arr;
	}
private:
	std::string str;
	char* arr; // указатель на динамический массив
	const int CAPASITY = 100; // ёмкость стека
	int top; // индекс верхнего элемента стека
};

bool isBalanced(std::string sequence)
{
	Stack brackets; // стек скобок
	for (char br : sequence)
	{
		if (br == '(' || br == '{' || br == '[')
			brackets.push_baсk(br);
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
	std::cout << "Введите последовательность скобок:" << std::endl;
	//std::cin >> sequence;

	if (isBalanced(sequence))
		std::cout << "Последовательность скобок является верной!" << std::endl;
	else
		std::cout << "Последовательность скобок не является верной!" << std::endl;



	return 0;
}
*/