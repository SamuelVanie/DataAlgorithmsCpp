#include <iostream>
#include "bst.hpp"
#include "bst.cpp"
#include <gtest/gtest.h>


TEST(bstCreation, shouldCreateEmptyBST){
  EXPECT_NO_THROW({ BST<int> test; });
}

TEST(bstInsertion, shouldInsertInEmptyBST){
  EXPECT_NO_THROW({
                    BST<int> test;
                    test.insert(5);
                  });
}

TEST(bstInsertion, shouldInsertInAlreadyFilledBST){
  EXPECT_NO_THROW({
                    BST<int> test {3};
                    test.insert(6);
                  });
}

TEST(bstRemove, shouldNotRemoveInEmptyBST){
  EXPECT_NO_THROW({
                    BST<int> test;
                    test.remove(4);
                  });
}

TEST(bstRemove, shouldRemoveAnElInBST){
  EXPECT_NO_THROW({
                    BST<int> test(6);
                    test.remove(6);
                  });
}


TEST(bstContains, shouldReturnFalseIfElementNotInBST){
  BST<int> test(6);
  test.insert(7);
  EXPECT_FALSE(test.contains(5));
}

TEST(bstContains, shouldReturnFalseInEmptyBST){
  BST<int> test;
  EXPECT_FALSE(test.contains(6));
}

TEST(bstContains, shouldGetElementInBST){
  BST<int> test(6);
  EXPECT_TRUE(test.contains(6));
}

int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
