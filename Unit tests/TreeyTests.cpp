#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework4/Treey.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
	TEST_CLASS(TreeyTests) {
	public:
		TEST_METHOD(numNodes) {
			// Arrange
			Treey<int, int>* tree1 = new Treey<int, int>();
			Treey<int, int>* tree2 = new Treey<int, int>();
			tree2->insert(1, 3);
			tree2->insert(3, 2);
			tree2->insert(5, 6);

			// Act
			int result1 = tree1->numNodes();
			int result2 = tree2->numNodes();

			delete tree1, tree2;

			// Assert
			Assert::AreEqual(0, result1);
			Assert::AreEqual(3, result2);
		}

		TEST_METHOD(remove) {
			// Arrange
			Treey<int, int>* tree1 = new Treey<int, int>();
			tree1->insert(1, 2);
			tree1->insert(3, 6);
			tree1->insert(7, 1);

			// Act
			int result1 = tree1->remove(1);
			int result2 = tree1->remove(7);

			delete tree1;
			
			// Assert
			Assert::AreEqual(2, result1);
			Assert::AreEqual(1, result2);
		}

		TEST_METHOD(find) {
			// Arrange
			Treey<int, int>* tree1 = new Treey<int, int>();
			tree1->insert(1, 2);
			tree1->insert(3, 6);
			tree1->insert(7, 1);

			// Act
			int result1 = *tree1->find(3);
			int result2 = *tree1->find(7);

			delete tree1;

			// Assert
			Assert::AreEqual(6, result1);
			Assert::AreEqual(1, result2);
		}

	};

}