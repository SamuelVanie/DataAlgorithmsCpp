#include "Heap.hpp"
#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

// Max implementation but it's the same for min heap
// Just change comparision in heapify functions

template <class T>
int Heap<T>::parent(int child_idx){
  return (child_idx - 1) / 2;
}

template <class T>
int Heap<T>::left_child(int parent_idx){
  return parent_idx * 2 + 1;
}

template <class T>
int Heap<T>::right_child(int parent_idx){
  return parent_idx * 2 + 2;
}

template <class T>
void Heap<T>::print() const{
  for(const auto i : this->heap){
    cout << i << ", ";
  }
  cout << endl;
}


template <class T>
void Heap<T>::heapifyUp(){
  if(this->heap.size() <= 0)
    return;

  int current_idx = this->heap.size() - 1;
  int parent_idx { parent(current_idx) };

  int current { this->heap[current_idx] };
  int parent { this->heap[parent_idx] };


  while(parent_idx >= 0 && current > parent){
    std::swap(this->heap[current_idx], this->heap[parent_idx]);
    current_idx = parent_idx;
    parent_idx = this->parent(current_idx);
    current = this->heap[current_idx];
    parent = this->heap[parent_idx];
  }
}


template <class T>
void Heap<T>::heapifyDown(){

  if(this->heap.size() <= 0)
    return;

  int current_idx { 0 };
  int left_child_idx { this->left_child(current_idx) };
  int right_child_idx { this->right_child(current_idx) };

  int current { this->heap[current_idx] };
  int left_child { this->heap[left_child_idx] };
  int right_child { this->heap[right_child_idx] };

  int greatest_idx = left_child_idx;

  while(left_child_idx <= this->heap.size() - 1 && right_child_idx <= this->heap.size()){
    if(right_child > left_child)
      greatest_idx = right_child_idx;

    std::swap(this->heap[current_idx], this->heap[greatest_idx]);
    current_idx = greatest_idx;
    left_child_idx = this->left_child(current_idx);
    right_child_idx = this->right_child(current_idx);
    greatest_idx = left_child_idx;
  }

}

template <class T>
void Heap<T>::insert(T data){
  this->heap.push_back(data);
  this->heapifyUp();
}

template <class T>
T Heap<T>::peek(){
  if(this->heap.size() != 0)
    return this->heap[0];
  throw "heap is empty"; 
}

template <class T>
T Heap<T>::poll(){
  if(this->heap.size() == 0) 
    throw "heap is empty";
  int most_prioritised = this->heap[0]; 
  this->heap[0] = this->heap[-1];
  this->heap.pop_back();
  this->heapifyDown();
  return most_prioritised;
}
