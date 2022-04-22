#ifndef STACK
#define STACK

#include <vector>

template <typename T>
class Stack {

  private:
    std::vector<T> stack;

  public:
    Stack();
    Stack(T data);
    bool isEmpty();

    void pop();
    void push(T data);
};
#endif /* ifndef STACK */
