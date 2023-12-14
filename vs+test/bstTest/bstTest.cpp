#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication4\bst.h"
#include <iostream>
#include<string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace bstTest
{
	TEST_CLASS(bstTest)
	{
	public:

		
		
			TEST_METHOD(TestConstructorIntSuccess)
			{
				// Arrange
				BST<int>* bst = new BST<int>();
				bst->insert(5);
				bst->insert(3);
				bst->insert(7);
				// Act & Assert
				Assert::IsNotNull(bst);
				Assert::IsNotNull(bst->search(5));
				Assert::IsNotNull(bst->search(3));
				Assert::IsNotNull(bst->search(7)); // Tree is notempty initially

				
				
			}

			TEST_METHOD(TestConstructorStringSuccess)
			{
				// Arrange
				BST<std::string>* bst = new BST<std::string>();
				bst->insert("5");
				bst->insert("3");
				bst->insert("7");
				// Act & Assert
				Assert::IsNotNull(bst);
				Assert::IsNotNull(bst->search("5"));
				Assert::IsNotNull(bst->search("3"));
				Assert::IsNotNull(bst->search("7")); // Tree is notempty initially

				
				
			}

		TEST_METHOD(Insert_Int_Success)
		{	// Arrange
			BST<int>* bst = new BST<int>();
			bst->insert(5);
			bst->insert(3);
			bst->insert(7);
			// Act & Assert
			Assert::IsNotNull(bst);
			Assert::IsNotNull(bst->search(5));
			Assert::IsNotNull(bst->search(3));
			Assert::IsNotNull(bst->search(7)); 
			
			
		}

		TEST_METHOD(Insert_String_Success)
		{	// Arrange
			BST<std::string>* bst = new BST<std::string>();
			bst->insert("5");
			bst->insert("3");
			bst->insert("7");
			// Act & Assert
			Assert::IsNotNull(bst);
			Assert::IsNotNull(bst->search("5"));
			Assert::IsNotNull(bst->search("3"));
			Assert::IsNotNull(bst->search("7")); 
			
			
		}
		
		

		TEST_METHOD(DeleteStringSuccess)
		{
			BST<std::string>* bst = new BST<std::string>();
			bst->insert("5");
			bst->insert("3");
			bst->insert("7");
			
			// Act & Assert
			Assert::IsNotNull(bst);
			Assert::IsNotNull(bst->search("5"));
			Assert::IsNotNull(bst->search("3"));
			Assert::IsNotNull(bst->search("7"));
			bst->deleteKey("7");
			Assert::IsNull(bst->search("7"));
			
			
		}

		TEST_METHOD(DeleteIntSuccess)
		{
			// Arrange
			BST<int>* bst = new BST<int>();
			bst->insert(5);
			bst->insert(3);
			bst->insert(7);

			//Assert
			Assert::IsNotNull(bst);
			Assert::IsNotNull(bst->search(5));
			Assert::IsNotNull(bst->search(3));
			Assert::IsNotNull(bst->search(7));
			bst->deleteKey(7);
			Assert::IsNull(bst->search(7));
			
			
		}
		TEST_METHOD(SearchIntSuccess)
		{
			BST<int>* bst = new BST<int>();
			bst->insert(5);
			bst->insert(3);
			bst->insert(7);
			// Act & Assert
			Assert::IsNotNull(bst);
			Assert::IsNotNull(bst->search(5));
			Assert::IsNotNull(bst->search(3));
			Assert::IsNotNull(bst->search(7));
			
			
		}

		TEST_METHOD(SearchStringSuccess)
		{	// Arrange
			BST<std::string>* bst = new BST<std::string>();
			bst->insert("5");
			bst->insert("3");
			bst->insert("7");
			// Act & Assert
			Assert::IsNotNull(bst);
			Assert::IsNotNull(bst->search("5"));
			Assert::IsNotNull(bst->search("3"));
			Assert::IsNotNull(bst->search("7"));
			
			
		}

		
	};

    };

