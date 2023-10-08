#include <iostream>


/*
	������ 27. ������� �� ������ ��������������� ���������
*/


struct Node		// ��������� ��������
{
	int data;
	Node* next;

	Node(int data) :data(data), next(nullptr) {}
};

class List		// ���������� ������
{
public:
	List() : head(nullptr) {}

	void add_elem(int data)	// ���������� �������� � ������
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

	void removeSublists()
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->next != nullptr && current->next->data < current->data)
			{
				Node* sublistStart = current->next;
				while (sublistStart != nullptr && sublistStart->data < current->data)
				{
					Node* temp = sublistStart;
					sublistStart = sublistStart->next;
					delete temp;
				}
				current->next = sublistStart; // ���������� ��� �������� � ��������� 
			}
			current = current->next;
		}
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
	List list;
	list.add_elem(1);
	list.add_elem(5);
	list.add_elem(8);
	list.add_elem(3);
	list.add_elem(2);
	list.print();
	list.removeSublists();
	list.print();

	return 0;
}
*/
