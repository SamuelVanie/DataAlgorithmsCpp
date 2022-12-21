#ifndef LINKED__LIST
#define LINKED__LIST

#include <cstdint>
#include <iostream>

template<class T>
class node {
  public:
    node() : data{}, next{ NULL } {}
    node(int d) : data{ d }, next{ NULL } {}

    T data;
    node *next;
};

template <class T> class LinkedList {
public:
  LinkedList() : head{ NULL } {};
  LinkedList(T data) {
    this->head = new node<T>(data);
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
    node<T> *tmp = new node<T>();
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
    node<T> *newNode = new node<T>();
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
    node<T> *tmp = new node<T>();
    tmp = this->head;
    if (index == 0) {
      // want to delete the head of the linked list
      this->head = tmp->next;
      delete tmp;
      return;
    }
    int z = 0;
    for (z = 0; z < index - 1 && tmp->next != NULL; tmp = tmp->next, ++z) {
      // loop until we are on the previous node of the target
    }
    if (tmp == NULL || z != index - 1)
      return;
    // save the target to be able to delete it
    node<T> *tmp2 = new node<T>();
    tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    delete tmp2;
  }

  /**
   * Insert a node at a given position */
  void insertAtPosition(int position, T data) {
    node<T> *new_el = new node<T>();
    new_el->data = data;
    new_el->next = NULL;

    if (position == 0) {
      new_el->next = this->head;
      this->head = new_el;
      return;
    }

    node<T> *temp = head;
    for (int i = 0; i < position - 1; i++)
      temp = temp->next;

    new_el->next = temp->next;
    temp->next = new_el;
  }

  /**
   * Print the elements of the linked list */
  void printElements() {
    std::cout << "BEGIN";
    for (node<T> *tmp(this->head); tmp != NULL; tmp = tmp->next) {
      std::cout << "[" << tmp->data << "]";
    }
    std::cout << "END";
  }

  /**
   * LinkedList reversing */
  void reverseLinkedList() {
    node<T> *current = head;
    node<T> *prev = NULL;
    node<T> *suiv = head;

    while (current != NULL) {
      suiv = suiv->next;
      current->next = prev;
      prev = current;
      current = suiv;
    }

    this->head = prev;
  }

  /**
   * Linkedlist reverse using recursion */
  void recursiveReverse(node<T> *first) {
    if (first->next == NULL) {
      this->head = first;
      return;
    }
    recursiveReverse(first->next);
    node<T> *p = first->next;
    p->next = first;
    first->next = NULL;
  }

  /**
   * Return the value of the head element of the list */
  T getHeadValue() {
    if (!this->isEmpty()) {
      return this->head->data;
    }
    return INT32_MIN;
  }

  node<T>* getHead(){
    return this->head;
  }

private:
	node<T> *head;
};

#endif
