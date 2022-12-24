#include <gtest/gtest.h>
#include "Heap.hpp"
#include "Heap.cpp"


TEST(insertIntoHeap, shouldInsertInAnEmptyHeap){
  Heap<int> test;
  EXPECT_NO_THROW({ test.insert(4); });   
}

TEST(insertIntoHeap, shouldRespectHeapProperty){
  Heap<int> test;
  test.insert(4);
  test.insert(5);
  test.insert(6);
  EXPECT_TRUE( test.peek() == 6 );
}

TEST(removeTest, shouldRemoveInHeap){
  Heap<int> test;
  test.insert(4);
  test.insert(6);
  int taken = test.poll();
  EXPECT_TRUE( test.peek() == 4 && taken == 6 );
}

TEST(removeTest, shouldNotRemoveInEmptyHeap){
  Heap<int> test;
  EXPECT_THROW({ test.poll(); }, const char *);
}

TEST(peekTest, shouldNotBeAbleToTakeInEmptyHeap){
  Heap<int> test;
  EXPECT_THROW({ test.peek(); }, const char *);
}


int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
