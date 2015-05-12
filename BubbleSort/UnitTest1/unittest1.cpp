#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\BubbleSort\p2DynArray.h"
#include <Assert.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			p2DynArray<int> bubble;

			bubble.PushBack(5);
			bubble.PushBack(4);
			bubble.PushBack(10);
			bubble.PushBack(8);
			bubble.PushBack(3);

			int i = bubble.BubbleSort();


			Assert::AreEqual(bubble[0], 3);
			Assert::AreEqual(bubble[1], 4);
			Assert::AreEqual(bubble[2], 5);
			Assert::AreEqual(bubble[3], 8);
			Assert::AreEqual(bubble[4], 10);
			

		}

	};
}