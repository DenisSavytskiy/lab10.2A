#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№10.2A/AP_Lab№10.2A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSort)
        {
            const int N = 3;
            Student* s = new Student[N];

            s[0].prizv = "Петров";
            s[0].spec = COMPUTER_SCIENCE;
            s[0].informatics = 5;

            s[1].prizv = "Іванов";
            s[1].spec = COMPUTER_SCIENCE;
            s[1].informatics = 5;

            s[2].prizv = "Сидоров";
            s[2].spec = INFORMATICS;
            s[2].informatics = 4;

            Sort(s, N);

            Assert::AreEqual(s[0].prizv, string("Іванов"));
            Assert::AreEqual(s[1].prizv, string("Петров"));
            Assert::AreEqual(s[2].prizv, string("Сидоров"));

            delete[] s;
        }

        TEST_METHOD(TestBinSearch)
        {
            const int N = 3;
            Student* s = new Student[N];

            s[0].prizv = "Іванов";
            s[0].spec = COMPUTER_SCIENCE;
            s[0].informatics = 5;

            s[1].prizv = "Петров";
            s[1].spec = COMPUTER_SCIENCE;
            s[1].informatics = 5;

            s[2].prizv = "Сидоров";
            s[2].spec = INFORMATICS;
            s[2].informatics = 4;

            int result = BinSearch(s, N, "Петров", COMPUTER_SCIENCE, 5);
            Assert::AreEqual(1, result);

            result = BinSearch(s, N, "Неіснуючий", COMPUTER_SCIENCE, 5);
            Assert::AreEqual(-1, result);

            delete[] s;
        }
    };
}