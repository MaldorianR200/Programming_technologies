#include <iostream>

/*
	Задача 4. В списке А размера N необходимо каждый элемент заменить на ближайший 
	следующий за ним элемент, который больше его. Если такого элемента нет, то заменить его на ноль.
	ПРИМЕР А= 1 3 2 5 3 4
	ОТВЕТ А= 3 5 5 0 4 0

*/

/*
class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		next = nullptr;
	}
};
class List
{
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void addTail(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void replaceNumber()
	{
		Node* current = head;	// текущий элемент 
		Node* nextLarge = nullptr;	// следующий, больщой элемент

		while (current != nullptr) // пока текущий элемент не nullptr
		{
			nextLarge = nullptr;
			Node* temp = current->next; // временный (следующий current) элемент
			while (temp != nullptr)	// пока временный элемент не nullptr
			{
				if (temp->data > current->data)	// если временный(следующий current) элемент больше текущего 
				{
					nextLarge = temp;
					break;
				}
				temp = temp->next; // делаем сдвиг
			}
			current->data = (nextLarge != nullptr) ? nextLarge->data : 0;
			current = current->next;
		}
	}

	void printList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
	}
private:
	Node* head;
	Node* tail;
	int size; // текущий размер списка
	
	

};

*/

/*
int main()
{
	std::srand(std::time(0));
	setlocale(LC_ALL, "ru");
	int n = 5;
	List list;
	std::cout << "Введите размер списка:" << std::endl;
	//std::cin >> n;
	std::cout << "Заполните список:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		list.addTail(std::rand() % 101 - 50);
	}
	std::cout << "Список элементов до задания:" << std::endl;

	list.printList();

	std::cout << "\nСписок элементов после задания:" << std::endl;

	list.replaceNumber();
	list.printList();
	

	return 0;
}
*/