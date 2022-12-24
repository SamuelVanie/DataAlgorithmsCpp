#pragma once
#include <vector>

template <class T>
class Heap {
private:
  std::vector<T> heap;
  int parent(int child_idx);
  int left_child(int parent_idx);
  int right_child(int parent_idx);
  void heapifyUp();
  void heapifyDown();

public:
  Heap(){};
  void insert(T data);
  T peek();
  T poll();
  void remove();
  void print() const;
};
