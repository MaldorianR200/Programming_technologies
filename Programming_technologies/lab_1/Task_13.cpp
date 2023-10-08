#include <iostream>

/*
	«адача 13.
ƒан список вещественных чисел. ¬се его элементы, не равные нулю, 
переписать, сохран€€ пор€док, в начало списка, а нулевые элементы 
в конец списка. Ќовый список заводить нельз€.

*/

class Node			// определение класса элемента списка
{
public:
	double data;
	Node* next;
	Node(double data)
	{
		this->data = data;
		next = nullptr;
	}
};

class List		// определние св€занного списка
{
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	void add_elem(double data)			//метод добавлени€ элемента в конец списка
	{
		Node* newNode = new Node(data);

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
	}

	void moveNonZero()		// перемещение ненулевых элементов в начало списка
	{
		if (head == nullptr)	// проверка узла на пустоту
		{
			return;
		}
		List result;	// создание нового списка + присваивание левого списка 
		Node* temp = this->head;	// временный список
		while (temp != nullptr)
		{
			if (temp->data != 0.0)
			{
				result.add_elem(temp->data);
				temp = temp->next;
			}
			else
			{
				temp = temp->next;
			}
		}

		temp = this->head;
		while (temp != nullptr)
		{
			if(temp->data == 0.0)
			{
				result.add_elem(temp->data);
				temp = temp->next;
			}
			else
			{
				temp = temp->next;
			}
			
		}
		this->head = result.head;
	}

	void print()
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}

	List operator+(List& right) {
		List result = *this;	// создание нового списка + присваивание левого списка 
		Node* temp = right.head;
		while (temp != nullptr)
		{
			result.add_elem(temp->data);
			temp = temp->next;
		}
		return result;
	}

	List& operator=(const List& right) {
		// копируем элементы из другого списка
		this->head = right.head;
		return *this;
	}
private:
	Node* head;
	Node* tail;
};


/*
int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	list.add_elem(0);
	list.add_elem(2);
	list.add_elem(0);
	list.add_elem(4);
	list.add_elem(24);
	std::cout << "Ќачальный список:" << std::endl;
	list.print();
	std::cout << "ѕосле перемещени€:" << std::endl;
	list.moveNonZero();
	list.print();
	return 0;
}

*/
