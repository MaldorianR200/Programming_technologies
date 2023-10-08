#include <iostream>


/*
	N серых и M белых мышей сидят по кругу. Кошка ходит по кругу по часовой стрелке 
	и съедает каждую S -тую мышку. В первый раз счет начинается с серой мышки. 
	Составить алгоритм определяющий порядок в котором сидели мышки, 
	если через некоторое время осталось K серых и L белых мышей.
*/

struct Mouse {
    int color = 0;      // 0 - пойманная мышь, 1 - серая мышка , 2 - белая мышка 
    Mouse* next = nullptr;  // Следующий элемент
};

class CircleMice {
private: 
    Mouse* start = nullptr; // Первый элемент
public: 
    int N, M, S, K, L; // Элементы ввода 
                       // [N - серые / M - белые / S - шаг / K - остаток серых / L - остаток белых]
    ~CircleMice() 
    {
        if (start) {        // Проверка! Выделена ли память для start
            Mouse* temp = start->next;
            start->next = nullptr;
            start = temp;
            while (start) {
                temp = start->next;
                delete start;
                start = temp;
            }
        }
    }
    bool ADD()           // Функция ADD - строит кольцевой список из мышей и                    
    {                    // если это возможно возвращает true, иначе false.  
        int F[5]; F[0] = N; F[1] = M; F[2] = S; F[3] = K; F[4] = L; // Запомним переменные которые были
       
        if (N < 0 || M < 0 || K < 0 || L < 0)    // Условия при которых программа не будет работать
        {
            std::cout << "Не выполненно условие задачи!" << std::endl; return false;
        }
        if (N < 1)
        {
            std::cout << "Кол-во серых мышей должно быть больше нуля!" << std::endl; return false;
        }
        if (S < 1)  
        {
            std::cout << "S - не может быть меньше еденицы!" << std::endl; 
            return false;
        }
        if ((K > N) || (L > M))
        {
            std::cout << "Введённые значения нарушают логику программы!" << std::endl;
            return false;
        }
        if ((K == N) && (L == M))
        {
            std::cout << "Кол-во оставшихся мышей == числу начальному числу мышей " << std::endl;
            return false;
        }
        if (K == N)
        {
            std::cout << "Число серых мышей до == числу после! Не выполнено условие задачи" << std::endl;
            return false;
        }

        if ((!K && M == L) || (!L && N == K))
            std::cout << "Кошка съела всех мышей одного цвета!" << std::endl;
        if (!(K + L))
            std::cout << "Кошка съела всех мышей одного цвета!" << std::endl;

        for (int i = 0; i < M + N; i++) {    // Построение пустого круга из N+M элементов 
            if (!start)
            {
                start = new Mouse; start->next = start;
            }
            else {
                Mouse* NEW = new Mouse;
                NEW->next = start->next; start->next = NEW;
            }
        }
        // Расставляем мышей по кольцу
        start->color = 1; N--; // сразу ставим серую мышку в начало
        Mouse* temp = start, * tmp; for (int i = 0; i < S; i++) temp = temp->next; // идем к S элементу
        while (N + M)
        { // Проверяем, есть ли вообще мыши
            tmp = temp; while (temp->color)
            {
                temp = temp->next;
                if (tmp == temp)
                {
                    std::cout << "Программа экстренно закрылась!" << std::endl;
                    return false;
                }
            }; 
            if (K < N)      // Ищем элемент где нет мыши
            {
                temp->color = 1; 
                N--;       // Если есть лишние серые мыши, то кормим кошке
            } 
            else if (L < M)
            {
                temp->color = 2; 
                M--;       // Если есть лишние белые мыши, то кормим кошке
            } 
            else if (N)
            {
                temp->color = 1;
                N--;       // Заполняем серых мышей по элементам, до которых кошка не доберется
            } 
            else if (M)
            {
                temp->color = 2; 
                M--;       // Заполняем белых мышей по элементам, до которых кошка не доберется
            } 
            
            if (!(N + M))
                break;
            for (int i = 0; i < S; i++)
            {
                temp = temp->next;  // идем к k*S элементу
                if (temp->color) 
                    i--;     
            }
        }
        
        N = F[0]; M = F[1]; S = F[2]; K = F[3]; L = F[4];
        return true;
    }

    void SHOW(Mouse* START) // Вывод расположения мышей
    {
        std::cout << " [ ";
        Mouse* temp = start;
        if (temp)
            do
            { // Если у нас есть элементы
                if (temp->color == 1) 
                    std::cout << "СЕРАЯ";
                else if (temp->color == 2) 
                    std::cout << "БЕЛАЯ"; else std::cout << "     "; // Выводим мышку на экран

                temp = temp->next; 
                if (temp != start) 
                    std::cout << " ] "; // Ставим пробелы между мышками
            } while (temp != start); // Если мы не пошли по второму кругу, то продолжаем
            std::cout << " ] " << std::endl;
            if (M == L && N == K) 
                return; // Проверяем - всех ли съела кошка
            if (start->color) 
            { 
                start->color = 0; 
                N--; 
                START = start; 
            } // если мы на первом элементе то съедаем серую
            else 
            { 
                for (int i = 0; i < S; i++) 
                { 
                    START = START->next; 
                    if (!START->color) i--; 
                } 
                (START->color == 1) ? N-- : M--; START->color = 0; 
            } // Съедаем что попалось
            SHOW(START); // следующий проход
    }
};
/*
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    CircleMice mouseHunting; // Создаем объект 

    std::cout << "Введите количество серых мышей: ";
    std::cin >> mouseHunting.N;

    std::cout << "Введите количество белых мышей: ";
    std::cin >> mouseHunting.M;

    std::cout << std::endl;

    std::cout << "Введите какую мышку по очереди съедает кошка: ";
    std::cin >> mouseHunting.S;
    std::cout << std::endl;

    std::cout << "Введите какое количество серых мышей осталось: ";
    std::cin >> mouseHunting.K;
    std::cout << "Введите какое количество белых мышей осталось: ";
    std::cin >> mouseHunting.L;

    std::cout << std::endl;

    if (mouseHunting.ADD()) 
    { // Запускаем функцию объекта для создания круга
        std::cout << "Вот так были расположены мышки: " << std::endl;
        mouseHunting.SHOW(nullptr);
        if (mouseHunting.N || mouseHunting.M)
            std::cout << "Оставшиеся мыши!" << std::endl;
        else 
            std::cout << "Все мыши были съедены!" << std::endl;
    }
    return 0;
}
*/




