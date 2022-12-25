#pragma once
#include <memory>
#include <iostream>

template <class Q>
class node {

public:
  Q data;
  std::shared_ptr<node<Q>> left_child;
  std::shared_ptr<node<Q>> right_child;

  node(): data{}, left_child { NULL }, right_child{ NULL } {};
  node(Q data): data{ data }, left_child{ NULL }, right_child{ NULL } {};
  ~node() = default;
};


template <class T>
class BST {
private:
  std::shared_ptr<node<T>> head;
  void print(std::shared_ptr<node<T>> head) const;
  void insert(std::shared_ptr<node<T>> &head, T value);
  void clean(std::shared_ptr<node<T>> &head);
  std::shared_ptr<node<T>> remove(std::shared_ptr<node<T>> &head, T value);
  std::shared_ptr<node<T>> findMin(std::shared_ptr<node<T>> head);

public:
    BST() : head { NULL } {};
    BST(T data);
    ~BST();
    void insert(T value);
    void remove(T value);
    bool contains(T value) const;
    void inorder() const;
};

