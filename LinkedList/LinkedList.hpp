#ifndef LINKED__LIST
#define LINKED__LIST

#include <iostream>

template <class T>
class LinkedList {

public:
	LinkedList() : head(NULL) {};
	LinkedList(T data) {
		this->head = new node();
		this->head->data = data;
		this->head->next = NULL;
	}
	bool isEmpty() {
		if (this->head != NULL)
			return false;
		return true;
	}

	/**
   * searchByValue: search for the index of a node that have a specified value
   * @param value : The value to search index for
   * @return      : The index of the node, if not exists, returns -1
   * */
	int searchByValue(T value) {
		if (isEmpty())
			return -1;
		node *tmp = new node();
		tmp = this->head;
		for (int i = 0; tmp != NULL; tmp = tmp->next, i++) {
			if (tmp->data == value) {
				return i;
			}
		}
		return -1;
	}

	/**
   * addAtStart   : add a value to the start of the linked list
   * @param value : the value of the data of the node
   * @return      : void
   * */
	void addAtStart(T value) {
		node *newNode = new node();
		newNode->data = value;
	if (!isEmpty()) {
			// Stack isn't empty
			// Change to a new head
			newNode->next = this->head;
			this->head = newNode;
			return;
		}
		this->head = newNode;
	}

	/**
   * deleteByIndex : delete the node at a specified index
   * @param index  : the index of the node
   * @return       : void
   * */
	void deleteByIndex(T index) {
		if (isEmpty())
			return;
		node *tmp = new node();
		tmp = this->head;
		if (index == 0) {
			// want to delete the head of the linked list
			this->head = tmp->next;
			delete tmp;
			return;
		}
		int z=0;
		for (z = 0; z < index - 1 && tmp->next != NULL; tmp = tmp->next, ++z) {
			// loop until we are on the previous node of the target
		}
		if (tmp == NULL || z != index-1)
			return;
		// save the target to be able to delete it
		node *tmp2 = new node();
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
	}

	void printElements() {
		std::cout << "BEGIN";
		for (node *tmp(this->head); tmp != NULL; tmp = tmp->next) {
			std::cout << "[" << tmp->data << "]";
		}
		std::cout << "END";
	}

	private:
		class node {
			public:
			T data;
			node *next;
		} * head;
};

#endif
