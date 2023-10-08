#include <iostream>


/*
	N ����� � M ����� ����� ����� �� �����. ����� ����� �� ����� �� ������� ������� 
	� ������� ������ S -��� �����. � ������ ��� ���� ���������� � ����� �����. 
	��������� �������� ������������ ������� � ������� ������ �����, 
	���� ����� ��������� ����� �������� K ����� � L ����� �����.
*/

struct Mouse {
    int color = 0;      // 0 - ��������� ����, 1 - ����� ����� , 2 - ����� ����� 
    Mouse* next = nullptr;  // ��������� �������
};

class CircleMice {
private: 
    Mouse* start = nullptr; // ������ �������
public: 
    int N, M, S, K, L; // �������� ����� 
                       // [N - ����� / M - ����� / S - ��� / K - ������� ����� / L - ������� �����]
    ~CircleMice() 
    {
        if (start) {        // ��������! �������� �� ������ ��� start
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
    bool ADD()           // ������� ADD - ������ ��������� ������ �� ����� �                    
    {                    // ���� ��� �������� ���������� true, ����� false.  
        int F[5]; F[0] = N; F[1] = M; F[2] = S; F[3] = K; F[4] = L; // �������� ���������� ������� ����
       
        if (N < 0 || M < 0 || K < 0 || L < 0)    // ������� ��� ������� ��������� �� ����� ��������
        {
            std::cout << "�� ���������� ������� ������!" << std::endl; return false;
        }
        if (N < 1)
        {
            std::cout << "���-�� ����� ����� ������ ���� ������ ����!" << std::endl; return false;
        }
        if (S < 1)  
        {
            std::cout << "S - �� ����� ���� ������ �������!" << std::endl; 
            return false;
        }
        if ((K > N) || (L > M))
        {
            std::cout << "�������� �������� �������� ������ ���������!" << std::endl;
            return false;
        }
        if ((K == N) && (L == M))
        {
            std::cout << "���-�� ���������� ����� == ����� ���������� ����� ����� " << std::endl;
            return false;
        }
        if (K == N)
        {
            std::cout << "����� ����� ����� �� == ����� �����! �� ��������� ������� ������" << std::endl;
            return false;
        }

        if ((!K && M == L) || (!L && N == K))
            std::cout << "����� ����� ���� ����� ������ �����!" << std::endl;
        if (!(K + L))
            std::cout << "����� ����� ���� ����� ������ �����!" << std::endl;

        for (int i = 0; i < M + N; i++) {    // ���������� ������� ����� �� N+M ��������� 
            if (!start)
            {
                start = new Mouse; start->next = start;
            }
            else {
                Mouse* NEW = new Mouse;
                NEW->next = start->next; start->next = NEW;
            }
        }
        // ����������� ����� �� ������
        start->color = 1; N--; // ����� ������ ����� ����� � ������
        Mouse* temp = start, * tmp; for (int i = 0; i < S; i++) temp = temp->next; // ���� � S ��������
        while (N + M)
        { // ���������, ���� �� ������ ����
            tmp = temp; while (temp->color)
            {
                temp = temp->next;
                if (tmp == temp)
                {
                    std::cout << "��������� ��������� ���������!" << std::endl;
                    return false;
                }
            }; 
            if (K < N)      // ���� ������� ��� ��� ����
            {
                temp->color = 1; 
                N--;       // ���� ���� ������ ����� ����, �� ������ �����
            } 
            else if (L < M)
            {
                temp->color = 2; 
                M--;       // ���� ���� ������ ����� ����, �� ������ �����
            } 
            else if (N)
            {
                temp->color = 1;
                N--;       // ��������� ����� ����� �� ���������, �� ������� ����� �� ���������
            } 
            else if (M)
            {
                temp->color = 2; 
                M--;       // ��������� ����� ����� �� ���������, �� ������� ����� �� ���������
            } 
            
            if (!(N + M))
                break;
            for (int i = 0; i < S; i++)
            {
                temp = temp->next;  // ���� � k*S ��������
                if (temp->color) 
                    i--;     
            }
        }
        
        N = F[0]; M = F[1]; S = F[2]; K = F[3]; L = F[4];
        return true;
    }

    void SHOW(Mouse* START) // ����� ������������ �����
    {
        std::cout << " [ ";
        Mouse* temp = start;
        if (temp)
            do
            { // ���� � ��� ���� ��������
                if (temp->color == 1) 
                    std::cout << "�����";
                else if (temp->color == 2) 
                    std::cout << "�����"; else std::cout << "     "; // ������� ����� �� �����

                temp = temp->next; 
                if (temp != start) 
                    std::cout << " ] "; // ������ ������� ����� �������
            } while (temp != start); // ���� �� �� ����� �� ������� �����, �� ����������
            std::cout << " ] " << std::endl;
            if (M == L && N == K) 
                return; // ��������� - ���� �� ����� �����
            if (start->color) 
            { 
                start->color = 0; 
                N--; 
                START = start; 
            } // ���� �� �� ������ �������� �� ������� �����
            else 
            { 
                for (int i = 0; i < S; i++) 
                { 
                    START = START->next; 
                    if (!START->color) i--; 
                } 
                (START->color == 1) ? N-- : M--; START->color = 0; 
            } // ������� ��� ��������
            SHOW(START); // ��������� ������
    }
};
/*
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    CircleMice mouseHunting; // ������� ������ 

    std::cout << "������� ���������� ����� �����: ";
    std::cin >> mouseHunting.N;

    std::cout << "������� ���������� ����� �����: ";
    std::cin >> mouseHunting.M;

    std::cout << std::endl;

    std::cout << "������� ����� ����� �� ������� ������� �����: ";
    std::cin >> mouseHunting.S;
    std::cout << std::endl;

    std::cout << "������� ����� ���������� ����� ����� ��������: ";
    std::cin >> mouseHunting.K;
    std::cout << "������� ����� ���������� ����� ����� ��������: ";
    std::cin >> mouseHunting.L;

    std::cout << std::endl;

    if (mouseHunting.ADD()) 
    { // ��������� ������� ������� ��� �������� �����
        std::cout << "��� ��� ���� ����������� �����: " << std::endl;
        mouseHunting.SHOW(nullptr);
        if (mouseHunting.N || mouseHunting.M)
            std::cout << "���������� ����!" << std::endl;
        else 
            std::cout << "��� ���� ���� �������!" << std::endl;
    }
    return 0;
}
*/




