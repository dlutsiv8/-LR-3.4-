#include "pch.h"
#include "CppUnitTest.h"
#include "../ПКР LR-3.4 іт/ПКР LR-3.4 іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLinkedList
{
    TEST_CLASS(UnitTestLinkedList)
    {
    public:

        TEST_METHOD(TestIncreaseList)
        {
            // створюємо список вручну: 1 -> 2 -> 3 -> (назад до 1)
            Node* head = new Node{ 1, nullptr };
            Node* second = new Node{ 2, nullptr };
            Node* third = new Node{ 3, nullptr };

            head->next = second;
            second->next = third;
            third->next = head; // кільцевість

            // збільшуємо всі елементи на 5
            increaseList(head, 5);

            // перевіряємо перший елемент
            Assert::AreEqual(6, head->data);
        }
    };
}