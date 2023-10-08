#include <iostream>

/*
	������ 6 �� ����� ����������� N ����� ������� ����� � M ����� ������� ����. 
	������ ���� �� ���� ������� �������, �������������� ������ S -��� ������. 
	� ������ ��� ���� ���������� � �����. � ����� ������� ���� ���������� ������, 
	����� ����� K ����� ����� L �����, ������� ������� �����.
*/

/*
struct Node
{
    int value;
    Node* next;
};

class List  // ������ �������� �����
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

    void flipCoints(int k, int s)   // ������� ������ s ������
    {
        Node* current = head;
        for (int i = 0; i < k; ++i)
        {
            if (i % s == 0)
            {
                current->value = !current->value; // �������� �������� ������
            }
            current = current->next;
        }
    }

    void print()
    {
        if (head == nullptr)
        {
            std::cout << "������ ������!!!" << std::endl;
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
    std::cout << "������� ���-�� ����� ������� �����: ";
    //std::cin >> n;

    std::cout << "������� ���-�� ����� ������� ����: ";
    //std::cin >> m;

    std::cout << "���-�� �����: ";
    //std::cin >> k;

    std::cout << "������� ���-�� �����, ������� ������� ����� ����� K �����: ";
    //std::cin >> l;

    std::cout << "������� ���: ";
    //std::cin >> s;

   
    std::cout << '\n';


    List coins;
    for (int i = 0; i < n; ++i)
    {
        coins.add_elem(1); // ���
    }
    for (int i = 0; i < m; ++i)
    {
        coins.add_elem(0); // �����
    }
    
    std::cout << "��������� ���������:" << std::endl;
    coins.print(); // �������� ��������� �����

    for (int i = 0; i < k; ++i)
    {
        coins.flipCoints(i, s); // �������������� ������ k ���
    }
    
    std::cout << "����� �����������:" << std::endl;
    coins.print(); // ����� k �����


    std::cout << "������� ����������� �����:" << std::endl;
    for (int i = 0; i < n + m; ++i) // ������� ����������� �����, ����� �������� l ����� ������� �����
        if (coins.get_elem(i) == l)
        {
            std::cout << i << " ";
        }
            
	return 0;
}

*/



