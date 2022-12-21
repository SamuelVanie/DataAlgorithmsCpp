##
# Data algorithms
#
# @file
# @version 0.1

# Linked list

cur-dir := $(shell pwd)
linkedlist_root := /LinkedList
linkedlist_dir := $(cur-dir)$(linkedlist_root)


LinkedList_test.o: ${linkedlist_dir}/LinkedList_test.cpp
	g++ ${linkedlist_dir}/LinkedList_test.cpp -o ${linkedlist_dir}/LinkedList_test.o

testLinkedList: ${linkedlist_dir}/LinkedList_test.o ${linkedlist_dir}/LinkedList.hpp
	g++ ${linkedlist_dir}/LinkedList.hpp ${linkedlist_dir}/LinkedList_test.o -o ${linkedlist_dir}/test -lgtest

run testLinkedList: ${linkedlist_dir}/test
	${linkedlist_dir}/test

clean:
	rm *.o



# end
