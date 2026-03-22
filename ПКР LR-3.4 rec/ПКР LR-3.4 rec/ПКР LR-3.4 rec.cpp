#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 🔹 Рекурсивне створення списку
Node* createListRecursive(int n, Node* head = nullptr, Node* prev = nullptr) {
    if (n == 0) {
        if (prev) prev->next = head; // замикання в кільце
        return head;
    }

    int value;
    cin >> value;

    Node* newNode = new Node{ value, nullptr };

    if (!head)
        head = newNode;

    if (prev)
        prev->next = newNode;

    return createListRecursive(n - 1, head, newNode);
}

// 🔹 Рекурсивний вивід
void printListRecursiveHelper(Node* current, Node* head) {
    if (!current) return;

    cout << current->data << " ";

    if (current->next == head)
        return;

    printListRecursiveHelper(current->next, head);
}

void printListRecursive(Node* head) {
    if (!head) return;
    printListRecursiveHelper(head, head);
    cout << endl;
}

// 🔹 Рекурсивне збільшення
void increaseListRecursiveHelper(Node* current, Node* head, int value) {
    if (!current) return;

    current->data += value;

    if (current->next == head)
        return;

    increaseListRecursiveHelper(current->next, head, value);
}

void increaseListRecursive(Node* head, int value) {
    if (!head) return;
    increaseListRecursiveHelper(head, head, value);
}

// 🔹 Рекурсивне видалення
void deleteListRecursiveHelper(Node* current, Node* head) {
    if (!current) return;

    if (current->next == head) {
        delete current;
        return;
    }

    Node* next = current->next;
    delete current;
    deleteListRecursiveHelper(next, head);
}

void deleteListRecursive(Node* head) {
    if (!head) return;
    deleteListRecursiveHelper(head, head);
}

// 🔹 main
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    Node* list = createListRecursive(n);

    cout << "Original list:\n";
    printListRecursive(list);

    int k;
    cout << "Enter value to add: ";
    cin >> k;

    increaseListRecursive(list, k);

    cout << "Updated list:\n";
    printListRecursive(list);

    deleteListRecursive(list);

    return 0;
}