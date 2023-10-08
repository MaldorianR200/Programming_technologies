#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
/*
	������ 12.
��������� ������, ������� �� ������ ��������� ����������� � ��������� �� � ��������� ��������� ����.
*/


bool checkGlob = true;
bool isValidComment(const std::string& line) {
	bool inQuotes = false; // ����, ����������� �� ���������� ������ �������
	bool isValid = true; // ����, ����������� �� ���������������� �����������

	for (int i = 0; i < line.length(); i++) {
		// ����� ������������� �����������
		if (line[i] == '/' && line[i + 1] == '/' && !inQuotes) {
			return isValid;
		}
		// ����� �������������� �����������
		else if (line[i] == '/' && line[i + 1] == '*' && line[i+2] == '/' && line[i+3] == '*' && !inQuotes)
		{
			isValid = false; // ����������� �������������, ���������� ����������������
			break;
			return isValid;
		}
		else if (line[i] == '/' && line[i + 1] == '*' && !inQuotes) {
			// ��������, ��� ����������� �� �������������
			for (int j = i + 2; j < line.length() - 1; j++) {
				if (line[j] == '*' && line[j + 1] == '/') {
					isValid = false; // ����������� �������������, ���������� ����������������
					break;
				}
			}
			return isValid;
		}

		// ��������, ������ ������� ��� ���
		else if (line[i] == '\"') {
			if (inQuotes) {
				inQuotes = false; // ��������� ��� �������
			}
			else {
				inQuotes = true; // ��������� ������ �������
			}
		}
	}

	return isValid;
}

class List		// �������� ������: "������"
{
public:
	List() :head(nullptr) {}		// ���������� ������������
	void add_elem(std::string data)		// ���������� �������� � ������
	{
		Node* newNode = new Node;		// ������ ����� ����
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)		// ��������� ����� ������ ����
		{							// ���� �� nullptr, �� ������� ��� ����� ����
			head = newNode;
		}
		else						// ����� ������ ������� �� next == nulptr �  
		{							// ������� next ����� ����
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void print()		// ����� � �������
	{
		Node* temp = head;			
		while (temp != nullptr)
		{
			if (!isValidComment(temp->data))
			{
				checkGlob = false;
				std::cout << "������! �������� ������ ������������!" << std::endl;
				break;
			}
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
	void removeComments()			// �������� ������������ � ������ �� � ����
	{
		std::ofstream file("Task_12.txt");		// ������ ����� ��� ������
		Node* temp = head;
		while (temp != nullptr)
		{
			std::string line = temp->data;
			if (line.find("//") != std::string::npos)	// ����� ���������
			{
				file << line << std::endl;
				temp->data = line.substr(0, line.find("//"));
			}
			else if (line.find("/*") != std::string::npos && line.find("*/") != std::string::npos)
			{
				file << line << std::endl;
				temp->data = line.substr(0, line.find("/*")) + line.substr(line.find("*/") + 2);
			}
			else if (line.find("/*") != std::string::npos)
			{
				file << line << std::endl;
				temp->data = line.substr(0, line.find("/*"));
				while (temp->next != nullptr && temp->next->data.find("*/") == std::string::npos)
				{
					temp = temp->next;
					file << temp->data << std::endl;	// ������ ������ � ����
					temp->data = line.substr(0, line.find("/*"));
				}
				file << temp->next->data << std::endl;	// ������ ������������� ������ */ � ����

				temp->data += temp->next->data.substr(temp->next->data.find("*/")+2);
				temp->next = temp->next->next;
			}
			temp = temp->next;
		}
		file.close();
	}
private:
	struct Node
	{
		std::string data;
		Node* next;
	};
	Node* head;

};

HANDLE hConsole;

enum ColorConsole
{
	GREEN = 2,
	RED = 4,
	YELLOW = 6
};

int main()
{
	setlocale(LC_ALL, "ru");
	// ��������� ����������� ����
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, GREEN);

	List list;
	
	bool check = 1;
	std::string line;

	std::ofstream out("text_programm.txt");		// ���� ��� ������
	if (!out.is_open())
	{
		SetConsoleTextAttribute(hConsole, RED);
		check = 0;
		std::cout << "������! ���� ��� ������ �� ��������!" << std::endl;
	}

	// ���� ���������� ������ ������ �� �����
	/*
	std::ifstream in("text_programm.txt");	// ��������� ���� ��� ������
	if (in.is_open())		// �������� �����
	{
		while (std::getline(in, line))
		{
			list.add_elem(line);
		}
	}
	else
		{
			check = 0;
			std::cout << "������! ���� ��� ������ �� ��������!" << std::endl;
			return 0;
		}
	in.close();		// ��������� ����
	*/

	
	std::cout << "������� ���(����� �� ����� ��������� ������� �������� ����� 'end'):" << std::endl;
	SetConsoleTextAttribute(hConsole, YELLOW);
	bool found = false;
	while (true)
	{
		std::getline(std::cin, line);
		
		if (line == "end")
		{
			break;
		}
		
		out << line;
		list.add_elem(line);
	}
	
	if (check)
	{
		
		SetConsoleTextAttribute(hConsole, GREEN);
		std::cout << "�������� ��� ���������:" << std::endl;
		SetConsoleTextAttribute(hConsole, YELLOW);
		list.print();
		std::cout << std::endl;
		if (checkGlob)
		{
			list.removeComments();
			SetConsoleTextAttribute(hConsole, GREEN);
			std::cout << "����������� ��� ���������:" << std::endl;
			SetConsoleTextAttribute(hConsole, YELLOW);
			list.print();
		}
		
	}

	_getch();
	return 0;
}




