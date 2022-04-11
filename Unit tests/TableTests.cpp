#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework4/table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
	TEST_CLASS(TableTests) {
	public:
		TEST_METHOD(size) {
			// Arrange
			table* table1 = new table(200);
			table* table2 = new table(300);
			table* table3 = new table(50);
			
			// Act
			int result1 = table1->getSize();
			int result2 = table2->getSize();
			int result3 = table3->getSize();

			delete table1, table2, table3;

			// Assert
			Assert::AreEqual(200, result1);
			Assert::AreEqual(300, result2);
			Assert::AreEqual(50, result3);
		}

		TEST_METHOD(numItems) {
			// Arrange
			table* table1 = new table(200);
			table* table2 = new table(300);
			table* table3 = new table(50);
			table1->insert(1);
			table1->insert(2);
			table1->insert(3);
			table1->insert(4);
			table2->insert(1);
			table2->insert(2);
			table2->insert(3);

			// Act
			int result1 = table1->getNumItems();
			int result2 = table2->getNumItems();
			int result3 = table3->getNumItems();
			
			delete table1, table2, table3;

			// Assert
			Assert::AreEqual(4, result1);
			Assert::AreEqual(3, result2);
			Assert::AreEqual(0, result3);
		}

		TEST_METHOD(hash) {
			// Arrange
			table* table1 = new table(200);
			table* table2 = new table(300);
			table* table3 = new table(50);

			// Act
			int result1 = table1->hash(205);
			int result2 = table2->hash(51);
			int result3 = table3->hash(632);
			
			delete table1, table2, table3;

			// Assert
			Assert::AreEqual(5, result1);
			Assert::AreEqual(51, result2);
			Assert::AreEqual(32, result3);
		}
	};

}