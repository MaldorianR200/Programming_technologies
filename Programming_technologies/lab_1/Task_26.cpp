#include <iostream>

/*
	������ 26. �������� ����� ������� � ������ ����� �������� ���������
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

	void addElem(int data)	// ���������� �������� � ������
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

	void addBefore(int new_elem, int data)		// ����������� �������� / ����� ����� ����� ���������
	{
		
		
		if (isEmpty())		// �������� �� ������� ������
		{
			head = new Node(data);
		}
		else if (head->data == data)		// ���� ������� ��������� � ���������� ������
		{
			Node* newNode = new Node(new_elem);
			newNode->next = head;
			head = newNode;
			return;
		}
		else		// ���� ������� �� ��������� data ��� ���� �� ��������� ����� ������
		{
			Node* current = head;
			while (current->next != nullptr && current->next->data != data)
			{
				current = current->next;
			}
			if (current->next == nullptr)		// ���� �������� ����� ������
			{
				std::cout << "�������: " << data << " �� ������ � ������!" << std::endl;
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
