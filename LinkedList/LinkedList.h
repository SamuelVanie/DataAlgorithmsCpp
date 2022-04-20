#ifndef LINKED__LIST
#define LINKED__LIST

#include <iostream>

class LinkedList {

public:
  LinkedList();
  LinkedList(int data);
  bool isEmpty();

  /**
   * searchByValue: search for the index of a node that have a specified value
   * @param value : The value to search index for
   * @return      : The index of the node, if not exists, returns -1
   * */
  int searchByValue(int value);

  /**
   * addAtStart   : add a value to the start of the linked list
   * @param value : the value of the data of the node
   * @return      : void
   * */
  void addAtStart(int value);

  /**
   * deleteByIndex : delete the node at a specified index
   * @param index  : the index of the node
   * @return       : void
   * */
  void deleteByIndex(int index);

  void printElements();

public:
  class node {
  public:
    int data;
    node *next;
  } * head;
};

#endif
