#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 🔹 Створення списку
Node* createList(int n) {
    if (n <= 0) return nullptr;

    Node* head = nullptr;
    Node* last = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = head; // робимо список кільцевим
    return head;
}

// 🔹 Вивід списку
void printList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// 🔹 Збільшення елементів
void increaseList(Node* head, int value) {
    if (!head) return;

    Node* temp = head;
    do {
        temp->data += value;
        temp = temp->next;
    } while (temp != head);
}

// 🔹 Звільнення пам’яті
void deleteList(Node* head) {
    if (!head) return;

    Node* temp = head->next;
    while (temp != head) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    delete head;
}

// 🔹 main
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    Node* list = createList(n);

    cout << "Original list:\n";
    printList(list);

    int k;
    cout << "Enter value to add: ";
    cin >> k;

    increaseList(list, k);

    cout << "Updated list:\n";
    printList(list);

    deleteList(list);

    return 0;
}