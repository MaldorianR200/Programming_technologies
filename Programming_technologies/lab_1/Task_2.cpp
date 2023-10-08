#include <iostream>

/*
	������ 2. ������ ���������� ����� N �������, �� ������� ������� ������, � 
	��������� ������������ �� ������� ������� ������� �� 2 �� N. ���������, ������� 
	� ����-��, ����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����. 
	���� ������������ �� ���������� �������� � ��� �� ��� ���, ���� �� ��������� ���� �������. 
����������:
a) ����� ����������� ��������, ���� �������� M � ��, ��� ���� ��������� � ������� ��������;
-----------------------------------------------------------------------------------------------
b) ����� �������� c �������� ��������� ����, ���� �������� M � ����� ����������� �������� L.


*/

struct Node
{
	int number;
	Node* prev;
	Node* next;
};

int getRemainingPerson(int N, int M)
{
	Node* head = new Node;
	head->number = 1;
	head->prev = head;		// ���������� ����
	head->next = head;		// ��������� ����

	Node* current = head; // ������� ����

	for (int i = 2; i <= N; ++i)	//�������� ������
	{
		Node* newPerson = new Node;
		newPerson->number = i;
		newPerson->prev = current;
		newPerson->next = newPerson;
		current = newPerson;
	}

	current->next = head;
	head->prev = current;

	while (current != current->next) //������� �� ������ ���� �� ��������� ���� �������
	{
		for (int i = 1; i < M; ++i)
		{
			current = current->next;
		}
		current->prev->next = current->next; //������� ������� �������
		current->next->prev = current->prev;

		Node* temp = current;
		current = current->next;
		//delete temp;

		int remainingPerson = current->number;

		delete current;

		return remainingPerson;
	}
}

int getStartingPerson(int N, int M, int L)
{
	int startingPerson = (L + 1) % N;
	return startingPerson;
}

/*
int main()
{
	int n = 5, m = 2, l = 1; 
	std::cout << "Enter the number of people: ";	//���-�� �������
	//std::cin >> n;
	std::cout << std::endl;

	std::cout << "Enter the number of the final person: "; //��������� �������
	//std::cin >> m;
	std::cout << std::endl;

	std::cout << "Enter the number of the remaining person: "; //����� ����������� ��������
	//std::cin >> l;
	std::cout << std::endl;

	std::cout << "Number of the remaining person: " << getRemainingPerson(n, m) << std::endl;
	std::cout << "The number of the person who started: " << getStartingPerson(n, m, l);
	return 0;
}
*/