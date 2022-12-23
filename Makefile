##
# Data algorithms
#
# @file
# @version 0.1


cur-dir := $(shell pwd)
linkedlist_root := /LinkedList
linkedlist_dir := $(cur-dir)$(linkedlist_root)

stack_root := /Stack
stack_dir := $(cur-dir)$(stack_root)


buildLinkedList: ${linkedlist_dir}/LinkedList_test.cpp ${linkedlist_dir}/LinkedList.hpp
	g++ ${linkedlist_dir}/LinkedList.hpp ${linkedlist_dir}/LinkedList_test.cpp -o ${linkedlist_dir}/LinkedList -g -lgtest

LinkedList: buildLinkedList
	${linkedlist_dir}/LinkedList



buildStack: ${stack_dir}/Stack.cpp ${stack_dir}/Stack.hpp ${stack_dir}/Stack_test.cpp
	g++ ${stack_dir}/Stack.hpp ${stack_dir}/Stack_test.cpp -o ${stack_dir}/Stack -g -lgtest

Stack: buildStack
	${stack_dir}/Stack



buildQueue: ${queue_dir}/Queue.cpp ${queue_dir}/Queue.hpp ${queue_dir}/Queue_test.cpp
	g++ ${Queue_dir}/Queue.hpp ${Queue_dir}/Queue_test.cpp -o ${Queue_dir}/Queue -g -lgtest

Queue: buildQueue
	${queue_dir}/Queue


clean:
	rm *.o



# end
