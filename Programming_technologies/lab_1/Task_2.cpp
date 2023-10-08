#include <iostream>

/*
	«адача 2. ¬округ считающего стоит N человек, из которых выделен первый, а 
	остальные занумерованы по часовой стрелке числами от 2 до N. —читающий, начина€ 
	с кого-то, ведет счет до M. „еловек, на котором остановилс€ счет, выходит из круга. 
	—чет продолжаетс€ со следующего человека и так до тех пор, пока не останетс€ один человек. 
ќпределить:
a) номер оставшегос€ человека, если известно M и то, что счет начиналс€ с первого человека;
-----------------------------------------------------------------------------------------------
b) номер человека c которого начиналс€ счет, если известно M и номер оставшегос€ человека L.


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
	head->prev = head;		// ѕредыдущий узел
	head->next = head;		// —ледующий узел

	Node* current = head; // “екущий узел

	for (int i = 2; i <= N; ++i)	//—оздание списка
	{
		Node* newPerson = new Node;
		newPerson->number = i;
		newPerson->prev = current;
		newPerson->next = newPerson;
		current = newPerson;
	}

	current->next = head;
	head->prev = current;

	while (current != current->next) //”далние из списка пока не останетс€ один элемент
	{
		for (int i = 1; i < M; ++i)
		{
			current = current->next;
		}
		current->prev->next = current->next; //”дал€ем текущий элемент
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
	std::cout << "Enter the number of people: ";	// ол-во человек
	//std::cin >> n;
	std::cout << std::endl;

	std::cout << "Enter the number of the final person: "; //ѕоследний человек
	//std::cin >> m;
	std::cout << std::endl;

	std::cout << "Enter the number of the remaining person: "; //Ќомер оставшегос€ человека
	//std::cin >> l;
	std::cout << std::endl;

	std::cout << "Number of the remaining person: " << getRemainingPerson(n, m) << std::endl;
	std::cout << "The number of the person who started: " << getStartingPerson(n, m, l);
	return 0;
}
*/