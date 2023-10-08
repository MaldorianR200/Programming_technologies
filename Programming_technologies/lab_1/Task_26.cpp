#include <iostream>

/*
	Задача 26. Добавить новый элемент в список перед заданным элементом
*/


struct Node		// структура элемента
{
	int data;
	Node* next;

	Node(int data) :data(data), next(nullptr) {}
};

class List		// реализация списка
{
public:
	List() : head(nullptr) {}

	void addElem(int data)	// добавление элемента в список
	{
		Node* newNode = new Node(data);

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

	void addBefore(int new_elem, int data)		// добавляемое значание / перед каким число добавляем
	{
		
		
		if (isEmpty())		// Проверка на пустоту списка
		{
			head = new Node(data);
		}
		else if (head->data == data)		// если элемент совпадает с заголовком списка
		{
			Node* newNode = new Node(new_elem);
			newNode->next = head;
			head = newNode;
			return;
		}
		else		// Ищем элемент со значением data или пока не достигнем конца списка
		{
			Node* current = head;
			while (current->next != nullptr && current->next->data != data)
			{
				current = current->next;
			}
			if (current->next == nullptr)		// если достигли конца списка
			{
				std::cout << "Элемент: " << data << " не найден в списке!" << std::endl;
				return;
			}
			Node* newNode = new Node(new_elem);
			newNode->next = newNode;
			
		}
		
		
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	
	void print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
private:
	Node* head;
};

/*
int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	
	list.addBefore(1, 7);
	list.addElem(10);
	list.addBefore(3, 10);
	list.addElem(15);
	list.addBefore(1, 15);
	list.addBefore(5, 7);
	list.print();

	return 0;
}
*/
