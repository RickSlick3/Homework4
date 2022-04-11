#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework4/Nodey.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
	TEST_CLASS(NodeyTests) {
	public:
		TEST_METHOD(EqualsOperator) {
			// Arrange
			Nodey<int, int>* n1 = new Nodey<int, int>(1, 5);
			Nodey<int, int>* n2 = new Nodey<int, int>(2, 1);
			Nodey<int, int>* n3 = new Nodey<int, int>(2, 3);

			// Act
			bool result1 = n1->operator==(n2);
			bool result2 = n2->operator==(n3);
			delete n1, n2, n3;
			
			// Assert
			Assert::AreEqual(false, result1);
			Assert::AreEqual(true, result2);
		}

		TEST_METHOD(LessThanOperator) {
			// Arrange
			Nodey<int, int>* n1 = new Nodey<int, int>(1, 5);
			Nodey<int, int>* n2 = new Nodey<int, int>(2, 1);
			Nodey<int, int>* n3 = new Nodey<int, int>(3, 3);

			// Act
			bool result1 = n1->operator<(n2);
			bool result2 = n3->operator<(n2);
			delete n1, n2, n3;

			// Assert
			Assert::AreEqual(true, result1);
			Assert::AreEqual(false, result2);
		}

		TEST_METHOD(GreaterThanOperator) {
			// Arrange
			Nodey<int, int>* n1 = new Nodey<int, int>(1, 5);
			Nodey<int, int>* n2 = new Nodey<int, int>(2, 1);
			Nodey<int, int>* n3 = new Nodey<int, int>(3, 3);

			// Act
			bool result1 = n1->operator>(n2);
			bool result2 = n3->operator>(n2);
			delete n1, n2, n3;

			// Assert
			Assert::AreEqual(false, result1);
			Assert::AreEqual(true, result2);
		}
	};

}