#include <iostream>

// ������ 28. ������� ����������� ������� � ������ ������

//struct Node		// ��������� ��������
//{
//	int data;
//	Node* next;
//
//	Node(int data) :data(data), next(nullptr) {}
//};
//
//class List		// ���������� ������
//{
//public:
//	List(): head(nullptr){}
//
//	void add_elem(int data)	// ���������� �������� � ������
//	{
//		Node* newNode = new Node(data);
//
//		if (head == nullptr)
//		{
//			head = newNode;
//		}
//		else
//		{
//			Node* current = head;
//			while (current->next != nullptr)
//			{
//				current = current->next;
//			}
//			current->next = newNode;
//		}
//	}
//
//	void makeFirst(int data)
//	{
//		if (head == nullptr || head->data == data)
//		{
//			return;
//		}
//
//		Node* current = head;
//		Node* prev = nullptr;
//		while (current != nullptr && current->data != data)
//		{
//			prev = current;
//			current = current->next;
//		}
//		if (current != nullptr)
//		{
//			prev->next = current->next;
//			current->next = head;
//			head = current;
//		}
//	}
//
//	void print()
//	{
//		Node* current = head;
//		while (current != nullptr)
//		{
//			std::cout << current->data << " ";
//			current = current->next;
//		}
//		std::cout << std::endl;
//	}
//private:
//	Node* head;
//};

/*
int main()
{
	List list;
	list.add_elem(10);
	list.add_elem(24);
	list.add_elem(14);
	list.add_elem(236);
	list.add_elem(24);
	list.print();
	list.makeFirst(236);
	list.print();
	
	return 0;
}
*/