#include <iostream>

/*
	������ 25. �������� ������� ��� �������� � ������
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

	void swapElem(int elem1, int elem2)		// ����������� �������� / ����� ����� ����� ���������
	{
		Node* curr1 = head;	// ����� 1-�� �������� � ������
		Node* prev1 = nullptr;

		while (curr1 != nullptr && curr1->data != elem1)
		{
			prev1 = curr1;
			curr1 = curr1->next;
		}
		Node* curr2 = head;	// ����� 2-�� �������� � ������
		Node* prev2 = nullptr;

		while (curr2 != nullptr && curr2->data != elem2)
		{
			prev2 = curr2;
			curr2 = curr2->next;
		}

		if (curr1 != nullptr && curr2 != nullptr)	// ������ ������� �������� ���� ���� �������
		{
			if (prev1 != nullptr)	// ���� ���������� ������� ����
			{
				prev1->next = curr2;
			}
			else
			{
				head = curr2;
			}
			if (prev2 != nullptr)
			{
				prev2->next = curr1;
			}
			else
			{
				head = curr1;
			}
			Node* temp = curr1->next;
			curr1->next = curr2->next;
			curr2->next = temp;
		}
	}
	bool isEmpty()
	{
		return head == nullptr;
	}

	void print()
	{
		std::cout << "������:" << std::endl;
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

	list.addElem(1);
	list.addElem(2);
	list.addElem(3);
	list.addElem(4);
	list.addElem(5);
	list.print();
	list.swapElem(1, 5);
	list.print();

	return 0;
}
*/

