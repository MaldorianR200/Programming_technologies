#include <iostream>
/*
    Задача 8.
Имеется n черных и белых карточек, сложенных в стопку. 
Карточки раскладываются на стол в одну линию следующим образом: 
первая кладется на стол, вторая под низ стопки, третья- на стол, 
четвертая - под низ стопки и т.д., пока все карточки не будут выложены на стол. 
Каким должно быть исходное расположение карточек в стопке, 
чтобы разложенные на столе карточки чередовались по цвету: белая, черная, белая, черная и т.д.

*/

class Stack {
private:
    int* data;          // Указатель на массив данных
    int size;      // Текущий размер вектора
    int capacity;  // Вместимость вектора

public:
    Stack() : size(0), capacity(1), data(new int[capacity]) {}  // конструктор
    ~Stack() {          // деструктор
        delete[] data;
    }
    void push_back(const int& value) {      // добавление элемента в стек
        if (size >= capacity) {
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            data = newData;
        }
        data[size++] = value;
    }
    int& operator[](int index) {        // перегрузка оператора []
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

void arrangedCards(int n) {     // перекладывание карточек
    Stack stack;
    int m =n / 2;
    for (int i = 0; i < n; i++) {
        if (n % 2 == 0) {
            if (i < m) {
                stack.push_back(true);
            }
            else {
                stack.push_back(false);
            }
        }
        else {
            if (i < m+1) {
                stack.push_back(true);
            }
            else {
                stack.push_back(false);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (stack[i]) {
            std::cout << "White ";
        }
        else {
            std::cout << "Black ";
        }
    }
}

/*
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    std::cout << "Введите количество карточек (n): ";
    std::cin >> n;

    //stolCards(n);
    arrangedCards(n);



    return 0;
}
*/