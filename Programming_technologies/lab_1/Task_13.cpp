#include <iostream>

/*
	������ 13.
��� ������ ������������ �����. ��� ��� ��������, �� ������ ����, 
����������, �������� �������, � ������ ������, � ������� �������� 
� ����� ������. ����� ������ �������� ������.

*/

class Node			// ����������� ������ �������� ������
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

class List		// ���������� ���������� ������
{
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	void add_elem(double data)			//����� ���������� �������� � ����� ������
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

	void moveNonZero()		// ����������� ��������� ��������� � ������ ������
	{
		if (head == nullptr)	// �������� ���� �� �������
		{
			return;
		}
		List result;	// �������� ������ ������ + ������������ ������ ������ 
		Node* temp = this->head;	// ��������� ������
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
		List result = *this;	// �������� ������ ������ + ������������ ������ ������ 
		Node* temp = right.head;
		while (temp != nullptr)
		{
			result.add_elem(temp->data);
			temp = temp->next;
		}
		return result;
	}

	List& operator=(const List& right) {
		// �������� �������� �� ������� ������
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
	std::cout << "��������� ������:" << std::endl;
	list.print();
	std::cout << "����� �����������:" << std::endl;
	list.moveNonZero();
	list.print();
	return 0;
}

*/
