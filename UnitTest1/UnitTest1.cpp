#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.1/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int** tmpArr = new int* [2];// { {2, 0, 1}, { -1, 0, 2 }, { 3, 0, -1 } };
			for (int i = 0; i < 2;)tmpArr[i++] = new int[2];
			tmpArr[0][0] = 2;
			tmpArr[0][1] = 0;		//  2 0
			tmpArr[1][0] = -1;		// -1 1
			tmpArr[1][1] = 1;

			Change(tmpArr, 0, 1, 2);
			//  0  2
			//  1 -1
			Assert::AreEqual(2, tmpArr[0][1]);
		}
	};
}