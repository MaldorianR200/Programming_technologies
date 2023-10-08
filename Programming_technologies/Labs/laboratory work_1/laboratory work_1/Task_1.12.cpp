#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
/*
	Задача 12.
Используя список, удалить из текста программы комментарии и поместить их в отдельный текстовый файл.
*/


bool checkGlob = true;
bool isValidComment(const std::string& line) {
	bool inQuotes = false; // флаг, указывающий на нахождение внутри кавычек
	bool isValid = true; // флаг, указывающий на действительность комментария

	for (int i = 0; i < line.length(); i++) {
		// Поиск однострочного комментария
		if (line[i] == '/' && line[i + 1] == '/' && !inQuotes) {
			return isValid;
		}
		// Поиск многострочного комментария
		else if (line[i] == '/' && line[i + 1] == '*' && line[i+2] == '/' && line[i+3] == '*' && !inQuotes)
		{
			isValid = false; // комментарий перекрывается, становится недействительным
			break;
			return isValid;
		}
		else if (line[i] == '/' && line[i + 1] == '*' && !inQuotes) {
			// Проверка, что комментарий не перекрывается
			for (int j = i + 2; j < line.length() - 1; j++) {
				if (line[j] == '*' && line[j + 1] == '/') {
					isValid = false; // комментарий перекрывается, становится недействительным
					break;
				}
			}
			return isValid;
		}

		// Проверка, внутри кавычек или нет
		else if (line[i] == '\"') {
			if (inQuotes) {
				inQuotes = false; // находимся вне кавычек
			}
			else {
				inQuotes = true; // находимся внутри кавычек
			}
		}
	}

	return isValid;
}

class List		// создание класса: "Список"
{
public:
	List() :head(nullptr) {}		// реализация конструктора
	void add_elem(std::string data)		// добавление элемента в список
	{
		Node* newNode = new Node;		// создаём новый узел
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)		// проверяем самый первый узел
		{							// если он nullptr, то передаём ему новый узел
			head = newNode;
		}
		else						// иначе просто доходим до next == nulptr и  
		{							// передаём next новый узел
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void print()		// вывод в консоль
	{
		Node* temp = head;			
		while (temp != nullptr)
		{
			if (!isValidComment(temp->data))
			{
				checkGlob = false;
				std::cout << "Ошибка! Неверный формат комминатария!" << std::endl;
				break;
			}
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
	void removeComments()			// удаление комментариев и записи их в файл
	{
		std::ofstream file("Task_12.txt");		// создаём поток для записи
		Node* temp = head;
		while (temp != nullptr)
		{
			std::string line = temp->data;
			if (line.find("//") != std::string::npos)	// поиск подстроки
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
					file << temp->data << std::endl;	// запись строки в файл
					temp->data = line.substr(0, line.find("/*"));
				}
				file << temp->next->data << std::endl;	// Запись закрывающейся строки */ в файл

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
	// получение дескриптора окна
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, GREEN);

	List list;
	
	bool check = 1;
	std::string line;

	std::ofstream out("text_programm.txt");		// файл для записи
	if (!out.is_open())
	{
		SetConsoleTextAttribute(hConsole, RED);
		check = 0;
		std::cout << "Ошибка! Файл для записи не открылся!" << std::endl;
	}

	// Если необходимо чтения данных из файла
	/*
	std::ifstream in("text_programm.txt");	// открываем файл для чтения
	if (in.is_open())		// проверка файла
	{
		while (std::getline(in, line))
		{
			list.add_elem(line);
		}
	}
	else
		{
			check = 0;
			std::cout << "Ошибка! Файл для записи не открылся!" << std::endl;
			return 0;
		}
	in.close();		// закрываем файл
	*/

	
	std::cout << "Введите код(выход из цикла позволяет сделать ключевое слово 'end'):" << std::endl;
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
		std::cout << "Исходный код программы:" << std::endl;
		SetConsoleTextAttribute(hConsole, YELLOW);
		list.print();
		std::cout << std::endl;
		if (checkGlob)
		{
			list.removeComments();
			SetConsoleTextAttribute(hConsole, GREEN);
			std::cout << "Обновленный код программы:" << std::endl;
			SetConsoleTextAttribute(hConsole, YELLOW);
			list.print();
		}
		
	}

	_getch();
	return 0;
}




