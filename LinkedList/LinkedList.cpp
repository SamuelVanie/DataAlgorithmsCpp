#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(NULL) {}

LinkedList::LinkedList(int data) {
  this->head = new LinkedList::node();
  this->head->data = data;
  this->head->next = NULL;
}

bool LinkedList::isEmpty() {
  if (this->head != NULL)
    return false;
  return true;
}

int LinkedList::searchByValue(int value) {
  if (LinkedList::isEmpty())
    return -1;
  LinkedList::node *tmp = new LinkedList::node();
  tmp = this->head;
  for (int i = 0; tmp != NULL; tmp = tmp->next, i++) {
    if (tmp->data == value) {
      return i;
    }
  }
  return -1;
}

void LinkedList::addAtStart(int value) {
  LinkedList::node *newNode = new LinkedList::node();
  newNode->data = value;
  if (!LinkedList::isEmpty()) {
    // Stack isn't empty
    // Change to a new head
    newNode->next = this->head;
    this->head = newNode;
    return;
  }
  this->head = newNode;
}

void LinkedList::deleteByIndex(int index) {
  if (LinkedList::isEmpty())
    return;
  LinkedList::node *tmp = new LinkedList::node();
  tmp = this->head;
  if (index == 0) {
    // want to delete the head of the linked list
    this->head = tmp->next;
    delete tmp;
    return;
  }
  int i;
  for (i = 0; i < index - 1, tmp->next != NULL; tmp = tmp->next, i++) {
    // loop until we are on the previous node of the target
  }
  if (tmp == NULL || i != index)
    return;
  // save the target to be able to delete it
  LinkedList::node *tmp2 = new LinkedList::node();
  tmp2 = tmp->next;
  tmp->next = tmp->next->next;
  delete tmp2;
}

void LinkedList::printElements() {
  if (LinkedList::isEmpty())
    return;
  std::cout << "BEGIN";
  for (LinkedList::node *tmp(this->head); tmp != NULL; tmp = tmp->next) {
    std::cout << "[" << tmp->data << "]";
  }
  std::cout << "END";
}
