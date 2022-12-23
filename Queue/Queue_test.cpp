#include "Queue.hpp"
#include "Queue.cpp"
#include <gtest/gtest.h>
#include "iostream"

TEST(queueCreation, shouldEmptyQueue){
    EXPECT_NO_THROW({Queue<int> test;});
}

TEST(queueInsertion, shouldBeEmpty){
    Queue<int> test;
    EXPECT_TRUE(test.isEmpty());
}

TEST(queueInsertion, shouldNotBeEmpty){
    Queue<int> test;
    test.push(8);
    EXPECT_FALSE(test.isEmpty());
}

TEST(queueInsertion, shouldAddAnewElement){
    Queue<int> test;
    test.push(7);
    EXPECT_FALSE(test.isEmpty());
}

TEST(queueRemove, shouldPopAtTheFront) {
    Queue<int> test;
    test.push(7);
    test.push(8);
    test.push(9);

    EXPECT_TRUE(test.pop() == 7);
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
