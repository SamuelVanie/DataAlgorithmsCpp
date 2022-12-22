#pragma once
#include <cstdint>
#include <iostream>


template <class T> class LinkedList {

private:

  template<class Q>
  class node {
    public:
      node() : data{}, next{ NULL } {}
      node(int d) : data{ d }, next{ NULL } {}

      Q data;
      node *next;
  };

	node<T> *head;

public:

  LinkedList();
  LinkedList(T data);

  ~LinkedList(){}


  bool isEmpty() const;
  int searchByValue(T value);
  void addAtStart(T value);
  void deleteByIndex(T index);
  void insertAtPosition(int position, T data);
  void printElements();
  void reverseLinkedList();
  void recursiveReverse(node <T> *first);
  T getHeadValue();
  node<T>* getHead() const;


};
