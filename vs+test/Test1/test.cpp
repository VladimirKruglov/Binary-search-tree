#include <gtest/gtest.h>
// Include the header file for your BST class
#include "C:\Users\DiGSt\Documents\GitHub\TKI-442_Zinchenko\task2\ConsoleApplication4\ConsoleApplication4\bst.h"  // Replace with the actual header file name
// Define a fixture class to set up common test data
// Create a fixture for your tests
template<typename T>
class BSTTest : public testing::Test {
protected:
    // Declare the BST object
    BST<T> bst;

    // Helper function to insert multiple keys into the BST
    void insertKeys(const std::vector<T>& keys) {
        for (const auto& key : keys) {
            bst.insert(key);
        }
    }
};

// Test cases
TEST_F(BSTTest, InsertAndSearch) {
    // Test insertion and search functionality
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);

    EXPECT_TRUE(bst.search(5) != nullptr);
    EXPECT_TRUE(bst.search(3) != nullptr);
    EXPECT_TRUE(bst.search(7) != nullptr);
    EXPECT_TRUE(bst.search(4) == nullptr);
}

TEST_F(BSTTest, Delete) {
    // Test deletion functionality
    insertKeys({ 5, 3, 7, 2, 4, 6, 8 });

    // Delete leaf node
    bst.deleteKey(2);
    EXPECT_TRUE(bst.search(2) == nullptr);

    // Delete node with one child
    bst.deleteKey(7);
    EXPECT_TRUE(bst.search(7) == nullptr);

    // Delete node with two children
    bst.deleteKey(5);
    EXPECT_TRUE(bst.search(5) == nullptr);
    EXPECT_TRUE(bst.search(3) != nullptr);
    EXPECT_TRUE(bst.search(4) != nullptr);
}

TEST_F(BSTTest, PrintTree) {
    // Test tree printing functionality
    insertKeys({ 5, 3, 7, 2, 4, 6, 8 });

    // Redirect std::cout to a stringstream to capture the output
    testing::internal::CaptureStdout();
    bst.printTree();
    std::string output = testing::internal::GetCapturedStdout();

    // Compare the printed tree with the expected output
    EXPECT_EQ(output, "2 3 4 5 6 7 8 \n");
}

// Add more test cases as needed

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}