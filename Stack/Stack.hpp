#pragma once

#include <vector>

template <typename T>
class Stack {

private:
	std::vector<T> stack;

public:
    Stack();
    Stack(T data);
    bool isEmpty() const;
    void pop();
    void push(T data);
    int size();


};
