#include <iostream>

/*
	Задача 6 По кругу расположено N монет гербами вверх и M монет гербами вниз. 
	Обходя круг по ходу часовой стрелки, переворачивает каждую S -тую монету. 
	В первый раз счет начинается с герба. В каком порядке надо расставить монеты, 
	чтобы после K ходов стало L монет, лежащих гербами вверх.
*/

/*
struct Node
{
    int value;
    Node* next;
};

class List  // Список хранения монет
{
public:
    List()
    {
        head = nullptr;
        size = 0;
    }
    int getSize() {
        return size;
    }

    void add_elem(int element) {
        Node* node = new Node;
        node->value = element;
        if (head == nullptr)
        {
            head = node;
            node->next = head;
        }
        else
        {
            Node* last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            last->next = node;
            node->next = head;
        }
        size++;
    }

    int get_elem(int index)
    {
        if (index < 0 && index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->value;
    }

    void flipCoints(int k, int s)   // поворот каждой s монеты
    {
        Node* current = head;
        for (int i = 0; i < k; ++i)
        {
            if (i % s == 0)
            {
                current->value = !current->value; // инверсия значения монеты
            }
            current = current->next;
        }
    }

    void print()
    {
        if (head == nullptr)
        {
            std::cout << "Пустой список!!!" << std::endl;
            return;
        }
        Node* current = head;
        do
        {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
    

private:
    Node* head; 
    int size;
};

*/

/*
int main()
{
    setlocale(LC_ALL, "ru");
    //    m = 4, n = 5, s = 2, k = 4, l = 2;
	int n = 5, m = 4, s = 2, k = 4, l = 2;
    std::cout << "Введите кол-во монет гербами вверх: ";
    //std::cin >> n;

    std::cout << "Введите кол-во монет гербами вниз: ";
    //std::cin >> m;

    std::cout << "Кол-во ходов: ";
    //std::cin >> k;

    std::cout << "Введите кол-во монет, лежащих гербами вверх после K ходов: ";
    //std::cin >> l;

    std::cout << "Введите шаг: ";
    //std::cin >> s;

   
    std::cout << '\n';


    List coins;
    for (int i = 0; i < n; ++i)
    {
        coins.add_elem(1); // орёл
    }
    for (int i = 0; i < m; ++i)
    {
        coins.add_elem(0); // решка
    }
    
    std::cout << "Начальное состояние:" << std::endl;
    coins.print(); // исходное состояние монет

    for (int i = 0; i < k; ++i)
    {
        coins.flipCoints(i, s); // переворачиваем монеты k раз
    }
    
    std::cout << "После переворотов:" << std::endl;
    coins.print(); // после k ходов


    std::cout << "Порядок расстановки монет:" << std::endl;
    for (int i = 0; i < n + m; ++i) // порядок расстановки монет, чтобы осталось l монет гербами вверх
        if (coins.get_elem(i) == l)
        {
            std::cout << i << " ";
        }
            
	return 0;
}

*/



