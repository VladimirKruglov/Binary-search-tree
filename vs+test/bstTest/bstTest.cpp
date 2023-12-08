#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication4\bst.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace bstTest
{
	TEST_CLASS(bstTest)
	{
	public:
		
        TEST_METHOD(TestInsertAndSearch)
        {
            // Arrange
            BST<int> bst;

            // Act
            bst.insert(5);
            bst.insert(3);
            bst.insert(7);
            bst.insert(1);

            // Assert
            Assert::IsNotNull(bst.search(5));
            Assert::IsNotNull(bst.search(3));
            Assert::IsNotNull(bst.search(7));
            Assert::IsNotNull(bst.search(1));
            Assert::IsNull(bst.search(9));
        }

        // Test the deletion functionality
        TEST_METHOD(TestDelete)
        {
            // Arrange
            BST<int> bst;

            // Act
            bst.insert(5);
            bst.insert(3);
            bst.insert(7);
            bst.insert(1);

            // Assert before deletion
            Assert::IsNotNull(bst.search(5));
            Assert::IsNotNull(bst.search(3));
            Assert::IsNotNull(bst.search(7));
            Assert::IsNotNull(bst.search(1));

            // Act - Delete node with key 5
            bst.deleteKey(5);

            // Assert after deletion
            Assert::IsNull(bst.search(5));
            Assert::IsNotNull(bst.search(3));
            Assert::IsNotNull(bst.search(7));
            Assert::IsNotNull(bst.search(1));
        }

        // Test the printTree functionality
        TEST_METHOD(TestPrintTree)
        {
            // Arrange
            BST<int> bst;
            std::ostringstream output;

            // Act
            bst.insert(5);
            bst.insert(3);
            bst.insert(7);
            bst.insert(1);

            // Redirect cout to capture the output
            std::streambuf* coutRedirect = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());

            // Act - Print the tree
            bst.printTree();

            // Reset cout redirection
            std::cout.rdbuf(coutRedirect);

            // Assert
            Assert::AreEqual(std::string("1 3 5 7 \n"), output.str());
        }
    };

    };

