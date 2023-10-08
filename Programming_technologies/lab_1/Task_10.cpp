#include <iostream>

/*
	Задача 10.
	Написать процедуру, которая меняла бы в односвязном списке крайние элементы.
*/

/*
class Node
{
public:
	int value;
	Node* next;

	Node(char value)
	{
		this->value = value;
		next = nullptr;
	}
};

class List
{
public:
	List()
	{
		head = nullptr;
	}
	void add_elem(int value)
	{
		Node* newNode = new Node(value);

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void swapEnds()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}
		Node* prev = nullptr;
		Node* current = head;

		while (current->next != nullptr)
		{
			prev = current;
			current = current->next;
		}
		prev->next = head;
		current->next = head->next;
		head->next = nullptr;
		head = current;
	}
	void print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
private:
	Node* head;
};

*/

/*
int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	list.add_elem(10);
	list.add_elem(20);
	list.add_elem(30);
	std::cout << "Изначальный список:" << std::endl;
	list.print();
	list.swapEnds();
	std::cout << "Конечный список:" << std::endl;
	list.print();
	return 0;
}
*/