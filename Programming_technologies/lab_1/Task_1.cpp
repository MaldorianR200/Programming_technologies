#include <iostream>
#include <strstream>
/*
	
������ 1. �������� ������������������, ��������� �� N ��� �������� (ai,bi). 
������ ���� ���������� ������� ��������������� ��������, ��������, ���� (b,�) 
��������, ��� ������ "b" ������������ ������� "�". �� ������� (b,�) � (�,a) 
������� ������� (b,a). ���������� ����������, �������� �� ��������� ������������������:

�) ������, �.�. ��� �������������� ��� ������������ ��� ������� (�������� �������������) 
����� ��������� � ������� (A1,A2,...,As) � ������� ���������������;

�) ��������������, �.�. ��� ��������� �������� x,y ����� �������� 
������������ ������� ��� (x,y) ��� � (y,x);


*/

template<typename T>
class Vector {


public:
    Vector() : capacity(10), size(0) {      // �����������
        arr = new T[capacity];  // ������������� �������
    }

    Vector(int initialCapacity) : capacity(initialCapacity), size(0) {  // ����������� � �����������
        arr = new T[capacity];          // ������������� �������
    }
    Vector(const Vector& right):size(right.size),                   // ����������� ����������� 
                                             capacity(right.capacity)
    {               
        this->arr = new T[capacity];      // ������������� �������
        for (int i = 0; i < this->size; ++i)    // ����������� ���������
        {
            this->arr[i] = right.arr[i];
        }
    }

    ~Vector() {                 // ����������
        delete[] arr;
    }

    void push_back(T element) {     // ���������� ��������� � ������
        if (size == capacity) {     // ���� ����� ��������� = ������� �������
            T* newArr = new T[2 * capacity]; // ����������� ����������� ������� � 2 ����
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            capacity *= 2;
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = element;      // ������������ ������ �������, ����� ������� �������
    }


    T& operator[](int index) {      // ���������� ��������� []
       
        if (index < 0 || index >= size) {       // ����������� ����������, 
                                                // ���� ������ ��� ���������
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() const {       // ���������� ������ �������
        return size;
    }

    bool empty() const {    // �������� �� �������
        return size == 0;
    }

private:
    T* arr;     // ��������� �� ������������ ������ ���������
    int capacity;   // ����������� �������
    int size;   // ������� ������ �������
};

bool check(Vector<std::string>&a)       // �������� ��������� �� ���������
{                                       
    bool flag;
    for (int i = 0; i < a.getSize() - 1; i++)
    {
        flag = false;                    // �������� �� ����� - ����� ���
        if (a[i][1] == a[i + 1][0])     // ���� �������� �����, �� ���������� ������
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
void func(Vector<std::string> b, bool t, bool e)        // �������� ������� 
{
    std::string str1, str2;             // ��������������� ����������
    if (t == true && e == true)             // ���� ��� ������� ������� ������
    {
        for (int i = 0; i < b.getSize(); ++i)       // ���������� ��������� � ������
            for (int j = 0; j < b[i].size(); ++j)
                str1.push_back(b[i][j]);
        for (int a = 0; a < str1.size(); a++)
        {
            if (str2.find(str1[a]) == -1)
                str2.push_back(str1[a]);
        }
        std::cout << "������������������ �������������: " << str2 << std::endl;     // �������, ��� ������������������ �������������
        t = false; 
        return;
    }
    if (t == true)          // ���� �������� �� ��������� ����� true
    {
        for (int i = 0; i < b.getSize(); ++i)
            for (int j = 0; j < b[i].size(); ++j)
                str1.push_back(b[i][j]);        // ���������� ��������� � ������
        for (int a = 0; a < str1.size(); a++)
        {
            if (str2.find(str1[a]) == -1)
                str2.push_back(str1[a]);
        }
        std::cout << "������������������ ������: " << str2 << std::endl;        // �������, ��� ������������������ ������
    }
    else 
        std::cout << "������������������ �������������:" << std::endl;      // �������, ��� ������������������ �������������
}
/*
void main()
{
  
    
    
    std::cout << "������� ����� ���: ";     
    std::cin >> n;      // ���� ���-�� ���
    if (n <= 1)             // �������� �� ������������ �����
    {
        std::cout << "����� ��� = 1 ��� < 0! ������!\n������� ����� ������ ��� ������"; std::cin.get(); std::cin.get(); exit(0);
    }
    Vector<std::string> temp(n);
    
    std::cout << "������� ����" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cout << "���� - " << i + 1 << ": ";
        std::cin >> str;
        temp.push_back(str);

        if (temp[i].size() > 2)     // �������� �� ������������ �����
        {
            std::cout << "�� ����� ������ ���� �����. ������!" << std::endl; 
            break;
        }
    }
    Vector<std::string> temp1(temp);
    std::cout << "������� �������: ";      // ����� �������� ��������
    for (int i = 0; i < n; ++i)
        std::cout << temp[i];
    std::cout << std::endl;
    func(temp, check(temp1), checkBut(temp));
}


*/









