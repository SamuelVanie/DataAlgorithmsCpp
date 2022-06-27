#include <cstddef>
#include <iostream>
#include "Stack.hpp"
#include "gtest/gtest.h"

TEST(testEmptyStack, isEmptyStackOnNonEmptyStack){
	Stack<int> stack(5);
	EXPECT_FALSE(stack.isEmpty());
}

TEST(testPush, shouldAddElementToTheTopOfStack){
	Stack<int> stack(6);
	stack.push(7);
	EXPECT_EQ(stack.size(), 2);
}

TEST(testPopStack, shouldPopTheTopOfStack){
	Stack<int> stack(5);
	stack.pop();
	EXPECT_EQ(stack.size(), 0);
}

TEST(testEmptyStack, isEmptyStackOnEmptyStack){
	Stack<int> stack(6);
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());
}

int main(int argc, char* argv[]){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
