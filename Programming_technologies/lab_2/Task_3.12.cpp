#include <iostream>
#include <string>

//Задача 12. Дано бинарное дерево. Найти в дереве самое высокое (низкое) поддерево, имеющее заданное число листьев.


struct Node // Структура узла дерева
{           
    int value;
    Node* left;
    Node* right;
    /*
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
    */
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
{      // Класс Бинарное дерево
public:
    Node* root; // указатель на корень дерева

  
    BinaryTree() : root(nullptr) {}      // Конструктор


    ~BinaryTree()       // Деструктор
    {
        destroyTree(root);
    }

   
    void destroyTree(Node* node)         // Рекурсивная функция для удаления всех узлов дерева
    {
        if (node != NULL) 
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

   
  
    void insert(int value)  // Функция для добавления значения в дерево
    {
        if (!checkIfExists(root, value))
        {
            root = insertNode(root, value);
        }
        else
            return;
    }
    
    bool checkIfExists(Node* root, int element)        // Функция для проверки наличия элемента в бинарном дереве
    {
        if (root == nullptr) {
            return false;   // Дерево пустое, элемент не найден
        }

        if (root->value == element) {
            return true;    // Элемент найден
        }

       
        bool leftExists = checkIfExists(root->left, element);        // Рекурсивно проверяем левое и правое поддерево
        bool rightExists = checkIfExists(root->right, element);

        return leftExists || rightExists;   // Если элемент найден в левом или правом поддереве, возвращаем true
    }
   


    int countLeaves(Node* node)   // подсчёт листьтев в дереве
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

   
   


    int heightOfTree(Node* node)        // поиск самой длинной ветки
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

    int minimalOfTree(Node* node)   // поиск самого маленькой ветки
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


    int findMax(Node* root)     // вывод значения которое содржится на максимальной ветке
    {
        if (root == nullptr)    // если нет веток
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
   

   
    void showTrunks(Trunk* p)    // Вспомогательная функция для печати ветвей бинарного дерева
    {
        if (p == nullptr) {
            return;
        }

        showTrunks(p->prev);
        std::cout << p->str;
    }

    void printBinaryTree(Node* root) {      // рекурсивный вывод дерева

        if (root == nullptr) {
            return;
        }

        // Рекурсивно выводим левое поддерево
        printBinaryTree(root->left);

        // Выводим значение узла
        std::cout << root->value << " ";

        // Рекурсивно выводим правое поддерево
        printBinaryTree(root->right);
    }

    void printTree(Node* root, Trunk* prev, bool isLeft)        // Вывод дерева
    {
        if (root == nullptr) {
            return;
        }

        std::string prev_str = "    ";
        Trunk* trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev) {
            trunk->str = "———";
        }
        else if (isLeft)
        {
            trunk->str = ".———";
            prev_str = "   |";
        }
        else {
            trunk->str = "`———";
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
        Node* insertNode(Node* node, int value)     // Рекурсивная функция для вставки значения в дерево
        {
            if (node == nullptr)
            {

                Node* newNode = new Node;   // Если дерево пустое, создаем новый узел
                newNode->value = value;
                newNode->left = nullptr;
                newNode->right = nullptr;
                return newNode;
            }
            else
            {      // Иначе рекурсивно спускаемся влево или вправо

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
    std::cout << "Заполните бинарное дерево(после окончния ввода введите end):" << std::endl;
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
            std::cout << "Ошибка! Было введено не число" << std::endl;
           
        }
        else
        {
            tree.insert(std::stoi(temp));
        }
    } while (temp != "end");
    
    std::cout << "Бинарное дерево:" << std::endl;
    
        
    tree.printTree(tree.root, nullptr, false);
    std::cout << std::endl;
 
 

    std::cout << "Самое большое значание дерева: " << tree.findMax(tree.root) << std::endl;
    std::cout << "Кол-во листьев поддерева максимальной высоты: " << tree.heightOfTree(tree.root) << std::endl;
    std::cout << "Самое маленькое значание дерева: " << tree.findMin(tree.root) << std::endl;
   std::cout << "Кол-во листьев поддерева минимальной высоты: " << tree.minimalOfTree(tree.root) << std::endl;

    return 0;
}

















/*
    Node* findHighestSubtree(Node* node, int& highestLeavesCount) {     // рекурсивный поиск самого высокого поддерева
        if (node == nullptr) {
            return nullptr;
        }

        int currentLeavesCount = countLeaves(node);

        if (currentLeavesCount > highestLeavesCount) {
            highestLeavesCount = currentLeavesCount;
            return node;
        }

        Node* leftSubtree = findHighestSubtree(node->left, highestLeavesCount);
        Node* rightSubtree = findHighestSubtree(node->right, highestLeavesCount);

        if (countLeaves(leftSubtree) > countLeaves(rightSubtree)) {
            return leftSubtree;
        }
        else {
            return rightSubtree;
        }
    }

     int findMaxHeightSubtree(Node* node, int& maxLeaves)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int numLeaves = countLeaves(node);

        if (numLeaves == maxLeaves)
        {
            return numLeaves;
        }
        else if (numLeaves > maxLeaves)
        {
            maxLeaves = numLeaves;
        }
        int leftHeight = findMaxHeightSubtree(node->left, maxLeaves);
        int rightHeight = findMaxHeightSubtree(node->right, maxLeaves);

        return 1 + std::max(leftHeight, rightHeight);

    }

    int findMinHeightSubtree(Node* node, int& minLeaves)
    {
        if (node == nullptr) {
            return 0;
        }

        int numLeaves = countLeaves(node);

        if (numLeaves == minLeaves) 
        {
            return numLeaves;
        }
        else if (numLeaves < minLeaves) 
        {
            minLeaves = numLeaves;
        }

        int leftHeight = findMinHeightSubtree(node->left, minLeaves);
        int rightHeight = findMinHeightSubtree(node->right, minLeaves);

        return 1 + std::min(leftHeight, rightHeight);
    }

     int findMaxHeight()
    {
        int maxLeaves = 0;
        findMaxHeightSubtree(root, maxLeaves);
        return maxLeaves;
    }

    int findMinHeight()
    {
        int minLeaves = countLeaves(root);
        findMinHeightSubtree(root, minLeaves);
        return minLeaves;
    }
    */




/*
     
    // Функция для поиска значения в дереве
    bool search(int value) 
    {
        Node* result = searchNode(root, value);
        return (result != NULL);
    }

     Node* searchNode(Node* node, int value)     // Рекурсивная функция для поиска значения в дереве
    {
        if (node == NULL || node->value == value)
        {
            return node;
        }
        else if (value < node->value)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }
    }

*/