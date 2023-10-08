#include <iostream>

/*
	������ 4. � ������ � ������� N ���������� ������ ������� �������� �� ��������� 
	��������� �� ��� �������, ������� ������ ���. ���� ������ �������� ���, �� �������� ��� �� ����.
	������ �= 1 3 2 5 3 4
	����� �= 3 5 5 0 4 0

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
		Node* current = head;	// ������� ������� 
		Node* nextLarge = nullptr;	// ���������, ������� �������

		while (current != nullptr) // ���� ������� ������� �� nullptr
		{
			nextLarge = nullptr;
			Node* temp = current->next; // ��������� (��������� current) �������
			while (temp != nullptr)	// ���� ��������� ������� �� nullptr
			{
				if (temp->data > current->data)	// ���� ���������(��������� current) ������� ������ �������� 
				{
					nextLarge = temp;
					break;
				}
				temp = temp->next; // ������ �����
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
	int size; // ������� ������ ������
	
	

};

*/

/*
int main()
{
	std::srand(std::time(0));
	setlocale(LC_ALL, "ru");
	int n = 5;
	List list;
	std::cout << "������� ������ ������:" << std::endl;
	//std::cin >> n;
	std::cout << "��������� ������:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		list.addTail(std::rand() % 101 - 50);
	}
	std::cout << "������ ��������� �� �������:" << std::endl;

	list.printList();

	std::cout << "\n������ ��������� ����� �������:" << std::endl;

	list.replaceNumber();
	list.printList();
	

	return 0;
}
*/