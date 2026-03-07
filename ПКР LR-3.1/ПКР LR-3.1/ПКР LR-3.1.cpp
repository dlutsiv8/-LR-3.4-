#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* ptr1;
    Node* ptr2;
};

// Функція побудови структури
Node* buildStructure()
{
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    Node* n4 = new Node;

    // Заповнюємо дані
    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;

    // Зв'язки за схемою

    // вузол 1
    n1->ptr1 = nullptr;  // перекреслений блок
    n1->ptr2 = n2;

    // вузол 2
    n2->ptr1 = n1;
    n2->ptr2 = n4;

    // вузол 4
    n4->ptr1 = n1;
    n4->ptr2 = n3;

    // вузол 3
    n3->ptr1 = n1;
    n3->ptr2 = n2;

    return n1; // p → вузол 1
}

// Функція видалення структури
void deleteStructure(Node* p)
{
    // Знаходимо всі вузли через ptr2, ptr1
    Node* n1 = p;
    Node* n2 = n1->ptr2;
    Node* n4 = n2->ptr2;
    Node* n3 = n4->ptr2;

    // Видаляємо всі вузли
    delete n1;
    delete n2;
    delete n3;
    delete n4;
}

int main()
{
    Node* p = buildStructure();

    cout << "Structure created" << endl;

    deleteStructure(p);

    cout << "Structure deleted" << endl;

    return 0;
}