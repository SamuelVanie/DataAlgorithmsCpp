#include <iostream>
#include <vector>
#include "Stack.hpp"

template <typename T>
Stack<T>::Stack(){
  this->stack = new std::vector<T>();
}

template <typename T>
Stack<T>::Stack(T data){
  this->stack.push_back(data);
}

template <typename T>
bool Stack<T>::isEmpty(){
  return this->stack.empty();
}

template <typename T>
void Stack<T>::pop(){
  return this->stack.pop_back();
}

template <typename T>
void Stack<T>::push(T data){
  this->stack.push_back(data);
}
