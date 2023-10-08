#include <iostream>
#include <unordered_set>
/*
	Задача 5.  Одинокий король долго ходил по бесконечной шахматной доске. 
	Известна последовательность из N его ходов (вверх, вниз, влево, вправо, 
	вверх-влево и т.п.).Написать программу, определяющую побывал ли король 
	дважды на одном и том же поле за минимально возможное 
	при заданном N число вычислений.
*/

struct Move	// перемещение 
{
	int x, y;
	Move(int x, int y)	
	{
		this->x = x;
		this->y = y;
	}
};

class ChessBoard	// поле
{
public:
	ChessBoard()
	{
		currentField = hash(0, 0);
		visitedFields.insert(currentField);
	}
	bool makeMove(Move move)	// делаем шаг
	{
		int newX = getX() + move.x;
		int newY = getY() + move.y;
		int newField = hash(newX, newY);

		if (visitedFields.count(newField) > 0)	// проверка на посещаемость
		{
			return true;
		}
		visitedFields.insert(newField);	// добавление к посещённым полям
		currentField = newField;	// текущему полю присваиваем новое
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
	std::unordered_set<int>visitedFields; // посещённое поле
	int currentField; // текущее поле
	int hash(int x, int y)	// создание поля
	{
		return x * 1000 + y;
	}

};
/*
int main()
{
	setlocale(LC_ALL, "ru");
	int n = 5;
	std::cout << "Введите кол-во ходов короля:";
	std::cin >> n;
	try
	{
		if(n < 1)
			throw std::invalid_argument("Число ходов меньше одного");
	}
	catch(std::string error_massage)
	{
		std::cout << error_massage;
	}
	
	ChessBoard chessBoard;
	bool visitedTwice = false;
	std::cout << "\nКоординаты могут иметь и отрицательные значения!" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "\nВведите ход - " << i + 1 << ": ";
		int x, y;
		std::cin >> x >> y;
		Move move(x, y);

		visitedTwice = chessBoard.makeMove(move);
		if (visitedTwice)
			break;
	}
	if (visitedTwice)
		std::cout << "Король побывал на одном и том же поле дважды!" << std::endl;
	else
		std::cout << "Король не был на поле дважды!" << std::endl;

	return 0;
}
*/