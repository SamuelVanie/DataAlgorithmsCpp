#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList() : head { NULL } {};


template <class T>
LinkedList<T>::LinkedList(T data) {
    this->head = new node<T>(data);
}


template <class T>
bool LinkedList<T>::isEmpty() const{
  if (this->head != NULL)
    return false;
  return true;
}

/**
   * searchByValue: search for the index of a node that have a specified value
   * @param value : The value to search index for
   * @return      : The index of the node, if not exists, returns -1
   * */
template <class T>
int LinkedList<T>::searchByValue(T value) {
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
template <class T>
void LinkedList<T>::addAtStart(T value) {
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
template <class T>
void LinkedList<T>::deleteByIndex(T index) {
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
template <class T>
void LinkedList<T>::insertAtPosition(int position, T data) {
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
template <class T>
void LinkedList<T>::printElements() {
  std::cout << "BEGIN";
  for (node<T> *tmp(this->head); tmp != NULL; tmp = tmp->next) {
    std::cout << "[" << tmp->data << "]";
  }
  std::cout << "END";
}


  /**
   * LinkedList reversing */
template <class T>
void LinkedList<T>::reverseLinkedList() {
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
template <class T>
void LinkedList<T>::recursiveReverse(node<T> *first) {
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
template <class T>
T LinkedList<T>::getHeadValue() {
  if (!this->isEmpty()) {
    return this->head->data;
  }
  return INT32_MIN;
}


template <class T>
typename LinkedList<T>::template node<T>* LinkedList<T>::getHead() const{
  return this->head;
}
