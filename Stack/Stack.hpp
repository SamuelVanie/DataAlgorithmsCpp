#ifndef STACK
#define STACK

#include <vector>

template <typename T>
class Stack {

private:
	std::vector<T> stack;

public:

Stack(){
  this->stack = new std::vector<T>();
}

Stack(T data){
  this->stack.push_back(data);
}

bool isEmpty(){
  return this->stack.empty();
}

void pop(){
  return this->stack.pop_back();
}

void push(T data){
  this->stack.push_back(data);
}

int size(){
	return this->stack.size();
}

};
#endif /* ifndef STACK */
