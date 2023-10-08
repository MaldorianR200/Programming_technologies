#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
/*
	Task 12.
Using the list, remove comments from the program text and place them in a separate text file.
*/


bool checkGlob = true;
bool isValidComment(const std::string& line) {
	bool inQuotes = false; // a flag indicating being inside quotation marks
	bool isValid = true; // flag indicating the validity of the comment

	for (int i = 0; i < line.length(); i++) {
		// Search for a one-line comment
		if (line[i] == '/' && line[i + 1] == '/' && !inQuotes) {
			return isValid;
		}
		// Search for a multiline comment
		else if (line[i] == '/' && line[i + 1] == '*' && line[i+2] == '/' && line[i+3] == '*' && !inQuotes)
		{
			isValid = false; // the comment overlaps, becomes invalid
			break;
			return isValid;
		}
		else if (line[i] == '/' && line[i + 1] == '*' && !inQuotes) {
			// Checking that the comment does not overlap
			for (int j = i + 2; j < line.length() - 1; j++) {
				if (line[j] == '*' && line[j + 1] == '/') {
					isValid = false; // the comment overlaps, becomes invalid
					break;
				}
			}
			return isValid;
		}

		// Checking whether inside quotes or not
		else if (line[i] == '\"') {
			if (inQuotes) {
				inQuotes = false; // we are outside the quotation marks
			}
			else {
				inQuotes = true; // we are inside the quotation marks
			}
		}
	}

	return isValid;
}

class List		// creating a class: "List"
{
public:
	List() :head(nullptr) {}		// implementation of the constructor
	void add_elem(std::string data)		//adding an item to a list
	{
		Node* newNode = new Node;		// creating a new node
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)		// check the very first node
		{							// if it is null ptr, then we pass it a new node
			head = newNode;
		}
		else						// otherwise, we just get to next == nullptr and  
		{							// passing next a new node
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void print()		// output to the console
	{
		Node* temp = head;			
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
	void removeComments()			// deleting comments and writing them to a file
	{
		std::ofstream file("Task_12.txt");		// creating a stream for recording
		Node* temp = head;
		while (temp != nullptr)
		{
			std::string line = temp->data;
			if (line.find("//") != std::string::npos)	// substring search
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
					file << temp->data << std::endl;	// writing a line to a file
					temp->data = line.substr(0, line.find("/*"));
				}
				file << temp->next->data << std::endl;	// Writing a closing line */ to a file

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
	// getting a window handle
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, GREEN);

	List list;
	
	bool check = 1;
	std::string line;

	std::ofstream out("text_programm.txt");		//file to write
	if (!out.is_open())
	{
		SetConsoleTextAttribute(hConsole, RED);
		check = 0;
		std::cout << "Mistake! The file for recording did not open!" << std::endl;
	}

	// If it is necessary to read data from a file
	/*
	std::ifstream in("text_programm.txt");	// opening the file for reading
	if (in.is_open())		// checking the file
	{
		while (std::getline(in, line))
		{
			list.add_elem(line);
		}
	}
	else
		{
			check = 0;
			std::cout << "Mistake! The file for recording did not open!" << std::endl;
			return 0;
		}
	in.close();		// closing the file
	*/

	
	std::cout << "Enter the code (exiting the loop allows you to make a keyword 'end'):" << std::endl;
	SetConsoleTextAttribute(hConsole, YELLOW);
	bool found = false;
	do
	{
		std::getline(std::cin, line);
		if (line == "end")
		{
			checkGlob = true;
			break;
		}
		if (!isValidComment(line))
		{
			
			std::cout << "Mistake! Incorrect comment format!" << std::endl;
		}
		else
		{
			out << line << '\n';
			list.add_elem(line);
		}
	} while (true);
	
	
	if (check)
	{
		
		SetConsoleTextAttribute(hConsole, GREEN);
		std::cout << "The source code of the program:" << std::endl;
		SetConsoleTextAttribute(hConsole, YELLOW);
		list.print();
		std::cout << std::endl;
		if (checkGlob)
		{
			list.removeComments();
			SetConsoleTextAttribute(hConsole, GREEN);
			std::cout << "Updated program code:" << std::endl;
			SetConsoleTextAttribute(hConsole, YELLOW);
			list.print();
		}
		
	}

	_getch();
	return 0;
}




