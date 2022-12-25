#include "LinkedList.hpp"
#include <memory>

template <class T>
LinkedList<T>::LinkedList() : head { NULL } {};


template <class T>
LinkedList<T>::LinkedList(T data) {
    this->head = std::make_shared<node<T>>(data);
}

template <class T>
void LinkedList<T>::clean() {
  while( this->head ){
    this->head = std::move(this->head->next);
  }
}

template <class T>
LinkedList<T>::~LinkedList() {
  this->clean();
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
int LinkedList<T>::searchByValue(T value) const {
  if (isEmpty())
    return -1;
  std::shared_ptr<node<T>> tmp{this->head};
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
  std::shared_ptr<node<T>> newNode = std::make_shared<node<T>>(value);
  if (!isEmpty()) {
    // Stack isn't empty
    // Change to a new head
    newNode->next = std::move(this->head);
    this->head = std::move(newNode);
    return;
  }
  this->head = std::move(newNode);
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
  std::shared_ptr<node<T>> tmp{this->head};
  if (index == 0) {
    // want to delete the head of the linked list
    this->head = std::move(tmp->next);
    return;
  }
  int z = 0;
  // loop until we are on the previous node of the target
  for (z = 0; z < index - 1 && tmp->next != NULL; tmp = tmp->next, ++z) {}
  if (tmp == NULL || z != index - 1)
    return;
  // save the target to be able to delete it
  std::shared_ptr<node<T>> tmp2{tmp->next};
  tmp->next = std::move(tmp->next->next);
}


  /**
   * Print the elements of the linked list */
template <class T>
void LinkedList<T>::printElements() const {
  std::cout << "BEGIN";
  for (std::shared_ptr<node<T>> tmp(this->head); tmp != NULL; tmp = tmp->next) {
    std::cout << "[" << tmp->data << "]";
  }
  std::cout << "END";
}



/**
 * Return the value of the head element of the list */
template <class T>
T LinkedList<T>::getHeadValue() const {
  if (!this->isEmpty()) {
    return this->head->data;
  }
  return INT32_MIN;
}
