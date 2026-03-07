#include "pch.h"
#include "CppUnitTest.h"
#include "../ПКР LR-3.1/ПКР LR-3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestStructure
{
    TEST_CLASS(UnitTestStructure)
    {
    public:

        TEST_METHOD(TestNode1)
        {
            // Побудова структури
            Node* p = buildStructure();

            // Перевірка: вузол 1 data = 1, ptr1 = nullptr
            Assert::AreEqual(1, p->data);
            Assert::IsNull(p->ptr1);

            // Звільнення пам'яті
            deleteStructure(p);
        }
    };
}