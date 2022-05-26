#include <iostream>
#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(testLinkedListInit, initLinkedListEmptyConstructor){
	LinkedList<int> list;
	EXPECT_EQ(list.isEmpty(), true);
}

TEST(testLinkedListInit, initLinkedListFilledConstructor){
	LinkedList<int> list(5);
	EXPECT_EQ(list.isEmpty(), false);
}

TEST(testLinkedListSearch, shouldReturnNegativeIndexGivenAValueForAnEmptyLinkedList){
	LinkedList<int> list;
	EXPECT_EQ(-1, list.searchByValue(5));
}

TEST(testLinkedListSearch, shouldReturnIndexGivenAValueForALinkedList){
	LinkedList<int> list(5);
	EXPECT_EQ(0, list.searchByValue(5));
}

TEST(testLinkedListAdd, shouldAddToTheBeginningOfList){
	LinkedList<int> list(4);
	list.addAtStart(5);
	EXPECT_EQ(0, list.searchByValue(5));
}

TEST(testLinkedListAdd, shouldAddRemoveAtTheIndex){
	LinkedList<int> list(5);
	list.addAtStart(4);
	list.addAtStart(6);
	list.deleteByIndex(1);
	EXPECT_EQ(-1, list.searchByValue(4));
}

int main(int argc, char* argv[]){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
