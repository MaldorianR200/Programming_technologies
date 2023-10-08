#include <iostream>
#include <unordered_set>
/*
	������ 5.  �������� ������ ����� ����� �� ����������� ��������� �����. 
	�������� ������������������ �� N ��� ����� (�����, ����, �����, ������, 
	�����-����� � �.�.).�������� ���������, ������������ ������� �� ������ 
	������ �� ����� � ��� �� ���� �� ���������� ��������� 
	��� �������� N ����� ����������.
*/

struct Move	// ����������� 
{
	int x, y;
	Move(int x, int y)	
	{
		this->x = x;
		this->y = y;
	}
};

class ChessBoard	// ����
{
public:
	ChessBoard()
	{
		currentField = hash(0, 0);
		visitedFields.insert(currentField);
	}
	bool makeMove(Move move)	// ������ ���
	{
		int newX = getX() + move.x;
		int newY = getY() + move.y;
		int newField = hash(newX, newY);

		if (visitedFields.count(newField) > 0)	// �������� �� ������������
		{
			return true;
		}
		visitedFields.insert(newField);	// ���������� � ���������� �����
		currentField = newField;	// �������� ���� ����������� �����
		return false;
	}
	int getX()
	{
		return currentField / 1000000;
	}
	int getY()
	{
		return currentField % 1000000;
	}

private:
	std::unordered_set<int>visitedFields; // ���������� ����
	int currentField; // ������� ����
	int hash(int x, int y)	// �������� ����
	{
		return x * 1000 + y;
	}

};
/*
int main()
{
	setlocale(LC_ALL, "ru");
	int n = 5;
	std::cout << "������� ���-�� ����� ������:";
	std::cin >> n;
	try
	{
		if(n < 1)
			throw std::invalid_argument("����� ����� ������ ������");
	}
	catch(std::string error_massage)
	{
		std::cout << error_massage;
	}
	
	ChessBoard chessBoard;
	bool visitedTwice = false;
	std::cout << "\n���������� ����� ����� � ������������� ��������!" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "\n������� ��� - " << i + 1 << ": ";
		int x, y;
		std::cin >> x >> y;
		Move move(x, y);

		visitedTwice = chessBoard.makeMove(move);
		if (visitedTwice)
			break;
	}
	if (visitedTwice)
		std::cout << "������ ������� �� ����� � ��� �� ���� ������!" << std::endl;
	else
		std::cout << "������ �� ��� �� ���� ������!" << std::endl;

	return 0;
}
*/