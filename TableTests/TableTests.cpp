#include "pch.h"
#include "CppUnitTest.h"
#include "../Table/table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TableTests
{
	TEST_CLASS(TableTests)
	{
	public:
		
		TEST_METHOD(AddTest)
		{
			Table T;
			T.addToTable("Element 1", "3567f");
			std::string data = "Element 1";

			Assert::AreEqual(data, T.findInTable("3567f"));
		}

		TEST_METHOD(FindTest)
		{
			Table T;
			T.addToTable("Element 1", "3567f");
			T.addToTable("Element 2", "5685f");
			T.addToTable("Element 3", "9895a");
			T.addToTable("Element 4", "4573d");

			std::string result1 = "Element 3";
			std::string result2 = "Element 1";
			Assert::AreEqual(result1, T.findInTable("9895a"));
			Assert::AreEqual(result2, T.findInTable("3567f"));
		}

		TEST_METHOD(RemoveTest) {
			Table T;
			T.addToTable("Element 1", "3567f");
			T.addToTable("Element 2", "5685f");
			T.addToTable("Element 3", "9895a");
			T.addToTable("Element 4", "4573d");

			std::string remove = "Element 2";

			Assert::AreEqual(remove, T.remove("5685f"));

			std::string notFound = T.findInTable("5685f");
			std::string notFoundExpected = "There were 0 elements found";
			Assert::AreEqual(notFound, notFoundExpected);
		}
	};
}
