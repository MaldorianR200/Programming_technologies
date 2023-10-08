#include <iostream>

/*
	������ 23.
����������� ����������� ����� ��������� ������������ ������ �� k ������� ����� (�� �� ����������� ��������)

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

	void shiftList(int numberOfShift)		// ����� - ����� ������ �� �������� ���-�� �������
	{
		if (isEmpty())
		{
			std::cout << "������ ����!" << std::endl;
			return;
		}
		else if (head->next = nullptr)
		{
			std::cout << "������ �������� ������ ���� �������!" << std::endl;
			return;
		}
		int len = 1; // ����� ������
		Node* tail = head;
		while (tail != nullptr)
		{
			tail = tail->next;
			++len;
		}
		
		List result = *this;	// �������� ������ ������ + ������������ ������ ������ 
		Node* temp = this->head;
		Node* shift = new Node(0);
		for (int i = 0; i < len; ++i)
		{
			if (i > numberOfShift)
			{
				result.addElem(temp->data);
				temp = temp->next;
			}
			else
			{
				shift->data = temp->data;
				shift = shift->next;
				temp = temp->next;
			}
		}
		while (shift != nullptr)
		{
			result.addElem(shift->data);
			shift = shift->next;
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

	list.addElem(5);
	list.addElem(4);
	list.addElem(9);
	list.addElem(2);
	list.addElem(4);
	std::cout << "������ �� ������:" << std::endl;
	list.print();
	list.shiftList(3);
	std::cout << "������ ����� ������:" << std::endl;
	list.print();
	return 0;
}
*/
