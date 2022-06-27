#ifndef STACK
#define STACK

#include <vector>

template <typename T>
class Stack {

private:
	std::vector<T> stack;

public:
	Stack(T data){
		this->stack.push_back(data);	
	};

	int size(){
		return this->stack.size();
	}

	bool isEmpty(){
		return this->stack.empty();			
	}

	void pop(){
		this->stack.pop_back();
	}

	void push(T data){
		this->stack.push_back(data);
	}
};
#endif /* ifndef STACK */
