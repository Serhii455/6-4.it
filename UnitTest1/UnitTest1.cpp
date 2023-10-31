#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr_6.4_IT/6.4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[5] = { 2, 3, 5, 1, 5 };
			int g = Find_Max(a, 5);
			Assert::AreEqual(g, 5);
		}
	};
}
