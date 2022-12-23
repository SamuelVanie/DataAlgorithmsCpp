#pragma once
#include <cstdint>
#include <iostream>
#include <memory>


template <class T> class LinkedList {

private:

  template<class Q>
  class node {
    public:
      node() : data{}, next{ NULL } {}
      node(int d) : data{ d }, next{ NULL } {}
      ~node(){
        std::cout << "A node was deleted" << std::endl;
      }

      Q data;
      std::shared_ptr<node<T>> next;
  };

  std::shared_ptr<node<T>> head;

public:

  LinkedList();
  LinkedList(T data);


  bool isEmpty() const;
  int searchByValue(T value) const;
  void addAtStart(T value);
  void deleteByIndex(T index);
  void printElements() const;
  T getHeadValue() const;


};
