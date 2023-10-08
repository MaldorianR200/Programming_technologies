#include <iostream>
#include <string>

//������ 12. ���� �������� ������. ����� � ������ ����� ������� (������) ���������, ������� �������� ����� �������.


struct Node // ��������� ���� ������
{           
    int value;
    Node* left;
    Node* right;
};


struct Trunk
{
    Trunk* prev;
    std::string str;

    Trunk(Trunk* prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

class BinaryTree 
{      // ����� �������� ������
public:
    Node* root; // ��������� �� ������ ������

  
    BinaryTree() : root(nullptr) {}      // �����������


    ~BinaryTree()       // ����������
    {
        destroyTree(root);
    }

   
    void destroyTree(Node* node)         // ����������� ������� ��� �������� ���� ����� ������
    {
        if (node != NULL) 
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

   
  
    void insert(int value)  // ������� ��� ���������� �������� � ������
    {
        if (!checkIfExists(root, value))
        {
            root = insertNode(root, value);
        }
        else
            return;
    }
    
    bool checkIfExists(Node* root, int element)        // ������� ��� �������� ������� �������� � �������� ������
    {
        if (root == nullptr) {
            return false;   // ������ ������, ������� �� ������
        }

        if (root->value == element) {
            return true;    // ������� ������
        }

       
        bool leftExists = checkIfExists(root->left, element);        // ���������� ��������� ����� � ������ ���������
        bool rightExists = checkIfExists(root->right, element);

        return leftExists || rightExists;   // ���� ������� ������ � ����� ��� ������ ���������, ���������� true
    }
   


    int countLeaves(Node* node)   // ������� �������� � ������
    {     
        if (node == nullptr) 
        {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) 
        {
            return 1;
        }
        else 
        {
            return countLeaves(node->left) + countLeaves(node->right);
        }
    }

   
   


    int heightOfTree(Node* node)        // ����� ����� ������� �����
    {
        if (node == 0)
            return 0;
        int left, right;
        if (node->left != nullptr) {
            left = heightOfTree(node->left);
        }
        else
            left = -1;
        if (node->right != nullptr) {
            right = heightOfTree(node->right);
        }
        else
            right = -1;
        int max = left > right ? left : right;
        return max + 1;

    }

    int minimalOfTree(Node* node)   // ����� ������ ��������� �����
    {
        if (node == 0)
            return 0;
        int left, right;
        if (node->left != nullptr) {
            left = minimalOfTree(node->left);
        }
        else
            left = -1;
        if (node->right != nullptr) {
            right = minimalOfTree(node->right);
        }
        else
            right = -1;
        int min = left < right ? left : right;
        return min + 1;

    }


    int findMax(Node* root)     // ����� �������� ������� ��������� �� ������������ �����
    {
        if (root == nullptr)    // ���� ��� �����
            return 1;

        int res = root->value;
        int lres = findMax(root->left);
        int rres = findMax(root->right);
        if (lres > res)
            res = lres;
        if (rres > res)
            res = rres;
        return res;
    }

   

    int findMin(Node* root)
    {
        if (root->left != nullptr) {
            return findMin(root->left);
        }
        else {
            return root->value;
        }
    }
   

   
    void showTrunks(Trunk* p)    // ��������������� ������� ��� ������ ������ ��������� ������
    {
        if (p == nullptr) {
            return;
        }

        showTrunks(p->prev);
        std::cout << p->str;
    }

    void printBinaryTree(Node* root) {      // ����������� ����� ������

        if (root == nullptr) {
            return;
        }

        // ���������� ������� ����� ���������
        printBinaryTree(root->left);

        // ������� �������� ����
        std::cout << root->value << " ";

        // ���������� ������� ������ ���������
        printBinaryTree(root->right);
    }

    void printTree(Node* root, Trunk* prev, bool isLeft)        // ����� ������
    {
        if (root == nullptr) {
            return;
        }

        std::string prev_str = "    ";
        Trunk* trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev) {
            trunk->str = "���";
        }
        else if (isLeft)
        {
            trunk->str = ".���";
            prev_str = "   |";
        }
        else {
            trunk->str = "`���";
            prev->str = prev_str;
        }

        showTrunks(trunk);
        std::cout << " " << root->value << std::endl;

        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }

    private:
        Node* insertNode(Node* node, int value)     // ����������� ������� ��� ������� �������� � ������
        {
            if (node == nullptr)
            {

                Node* newNode = new Node;   // ���� ������ ������, ������� ����� ����
                newNode->value = value;
                newNode->left = nullptr;
                newNode->right = nullptr;
                return newNode;
            }
            else
            {      // ����� ���������� ���������� ����� ��� ������

                if (value < node->value)
                {
                    node->left = insertNode(node->left, value);
                }
                else
                {
                    node->right = insertNode(node->right, value);
                }
                return node;
            }
        }

  
};

bool isNumber(std::string str)
{
    for (char const& c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}



int main() {
    setlocale(LC_ALL, "ru");
    BinaryTree tree;
    std::cout << "��������� �������� ������(����� �������� ����� ������� end):" << std::endl;
    std::string temp;
    do
    {
        std::cin >> temp;
        if (temp == "end")
        {
            break;
        }
        else if (!isNumber(temp))
        {
            std::cout << "������! ���� ������� �� �����" << std::endl;
           
        }
        else
        {
            tree.insert(std::stoi(temp));
        }
    } while (temp != "end");
    
    std::cout << "�������� ������:" << std::endl;
    
        
    tree.printTree(tree.root, nullptr, false);
    std::cout << std::endl;
 
 

    std::cout << "����� ������� �������� ������: " << tree.findMax(tree.root) << std::endl;
    std::cout << "���-�� ������� ��������� ������������ ������: " << tree.heightOfTree(tree.root) << std::endl;
    std::cout << "����� ��������� �������� ������: " << tree.findMin(tree.root) << std::endl;
   std::cout << "���-�� ������� ��������� ����������� ������: " << tree.minimalOfTree(tree.root) << std::endl;

    return 0;
}

















