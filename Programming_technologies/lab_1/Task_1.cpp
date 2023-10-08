#include <iostream>
#include <strstream>
/*
	
Задача 1. Вводится последовательность, состоящая из N пар символов (ai,bi). 
Каждая пара определяет порядок предшествования символов, например, пара (b,с) 
означает, что символ "b" предшествует символу "с". Из порядка (b,с) и (с,a) 
следует порядок (b,a). Необходимо определить, является ли введенная последовательность:

а) полной, т.е. все использованные для формирования пар символы (выбросив повторяющиеся) 
можно выстроить в цепочку (A1,A2,...,As) в порядке предшествования;

б) противоречивой, т.е. для некоторых символов x,y можно получить 
одновременно порядок как (x,y) так и (y,x);


*/

template<typename T>
class Vector {


public:
    Vector() : capacity(10), size(0) {      // конструктор
        arr = new T[capacity];  // инициализация массива
    }

    Vector(int initialCapacity) : capacity(initialCapacity), size(0) {  // конструктор с параметрами
        arr = new T[capacity];          // инициализация массива
    }
    Vector(const Vector& right):size(right.size),                   // конструктор копирования 
                                             capacity(right.capacity)
    {               
        this->arr = new T[capacity];      // инициализация массива
        for (int i = 0; i < this->size; ++i)    // копирование элементов
        {
            this->arr[i] = right.arr[i];
        }
    }

    ~Vector() {                 // деструктор
        delete[] arr;
    }

    void push_back(T element) {     // добавление элементов в вектор
        if (size == capacity) {     // если число элементов = размеру вектора
            T* newArr = new T[2 * capacity]; // увеличиваем вместимость вектора в 2 раза
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            capacity *= 2;
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = element;      // присваеиваем ячейке элемент, далее смещаем позицию
    }


    T& operator[](int index) {      // перегрузка оператора []
       
        if (index < 0 || index >= size) {       // выбрасываем исключение, 
                                                // если индекс вне диапазона
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() const {       // возвращаем размер вектора
        return size;
    }

    bool empty() const {    // проверка на пустоту
        return size == 0;
    }

private:
    T* arr;     // указатель на динамический массив элементов
    int capacity;   // вместимость вектора
    int size;   // текущий размер вектора
};

bool check(Vector<std::string>&a)       // проверка элементов по диагонали
{                                       
    bool flag;
    for (int i = 0; i < a.getSize() - 1; i++)
    {
        flag = false;                    // элементы не равны - вернём лож
        if (a[i][1] == a[i + 1][0])     // если элементы равны, то возвращаем истину
            flag = true;                   
    }
    return flag;                    
}
bool checkBut(Vector<std::string> a)
{
    bool flagbut = false;
    for (int i = 0; i < a.getSize() - 1; i++)
    {
        if (a[i][1] == a[i + 1][0] && a[i][0] == a[i + 1][1])
            flagbut = true;
    }
    return flagbut;
}
void func(Vector<std::string> b, bool t, bool e)        // основная функция 
{
    std::string str1, str2;             // вспомогательные переменные
    if (t == true && e == true)             // если обе функции вернуть истину
    {
        for (int i = 0; i < b.getSize(); ++i)       // добавление элементов в строку
            for (int j = 0; j < b[i].size(); ++j)
                str1.push_back(b[i][j]);
        for (int a = 0; a < str1.size(); a++)
        {
            if (str2.find(str1[a]) == -1)
                str2.push_back(str1[a]);
        }
        std::cout << "Последовательность противоречива: " << str2 << std::endl;     // выведем, что последовательность противоречива
        t = false; 
        return;
    }
    if (t == true)          // если проверка по диагонали будет true
    {
        for (int i = 0; i < b.getSize(); ++i)
            for (int j = 0; j < b[i].size(); ++j)
                str1.push_back(b[i][j]);        // добавление элементов в строку
        for (int a = 0; a < str1.size(); a++)
        {
            if (str2.find(str1[a]) == -1)
                str2.push_back(str1[a]);
        }
        std::cout << "Последовательность полная: " << str2 << std::endl;        // выведем, что последовательность полная
    }
    else 
        std::cout << "Последовательность противоречива:" << std::endl;      // выведем, что последовательность противоречива
}
/*
void main()
{
  
    
    
    std::cout << "Введите число пар: ";     
    std::cin >> n;      // ввод кол-ва пар
    if (n <= 1)             // проверка на правильность ввода
    {
        std::cout << "Число пар = 1 или < 0! Ошибка!\nНажмите любую кнопку для выхода"; std::cin.get(); std::cin.get(); exit(0);
    }
    Vector<std::string> temp(n);
    
    std::cout << "Введите пары" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cout << "Пара - " << i + 1 << ": ";
        std::cin >> str;
        temp.push_back(str);

        if (temp[i].size() > 2)     // проверка на правильность ввода
        {
            std::cout << "Вы ввели больше двух чисел. Ошибка!" << std::endl; 
            break;
        }
    }
    Vector<std::string> temp1(temp);
    std::cout << "Введёные символы: ";      // вывод введённых символов
    for (int i = 0; i < n; ++i)
        std::cout << temp[i];
    std::cout << std::endl;
    func(temp, check(temp1), checkBut(temp));
}


*/









