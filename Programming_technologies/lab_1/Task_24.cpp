#include <iostream>

/*
	������ 24.. ���������� n ������� � ���� ������
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
	List() : head(0) {}

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

		++count;
	}
	bool isEmpty()
	{
		return head == nullptr;
	}

	int getCount()
	{
		return count;
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

	Node* getHead()
	{
		return head;
	}

	

	List operator+(List& right)  {
		List result = *this;	// �������� ������ ������ + ������������ ������ ������ 
		Node* temp = right.head;
		while(temp != nullptr)
		{
			result.addElem(temp->data);
			temp = temp->next;
		}
		return result;
	}

	List& operator=(const List& right) {
		

		// �������� �������� �� ������� ������
		count = right.count;
		this->head = right.head;
		
		return *this;
	}
	int count = 0;


private:
	Node* head;
	
	
};





/*
int main()
{
	setlocale(LC_ALL, "ru");
	

	List list, list2, list3, final;

	list.addElem(1);
	list.addElem(2);
	list.print();

	list2.addElem(3);
	list2.addElem(4);
	list2.print();

	list3.addElem(5);
	list3.addElem(6);
	list3.print();
	
	
	final = list + list2 + list3;

	final.print();

	return 0;
}
*/

