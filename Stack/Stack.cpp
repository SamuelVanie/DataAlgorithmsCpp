#include "Stack.hpp"

template <class T>
Stack<T>::Stack(){
  this->stack = new std::vector<T>();
}

template <class T>
Stack<T>::Stack(T data){
  this->stack.push_back(data);
}

template <class T>
bool Stack<T>::isEmpty() const {
  return this->stack.empty();
}

template <class T>
void Stack<T>::pop() {
  return this->stack.pop_back();
}

template <class T>
void Stack<T>::push(T data){
  this->stack.push_back(data);
}

template <class T>
int Stack<T>::size(){
	return this->stack.size();
}
