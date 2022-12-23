#include "Queue.hpp"


template <class T>
void Queue<T>::push(T data){
    this->element.push_back(data);
}


template <class T>
T Queue<T>::pop() {
    T last = this->element[0];
    this->element.erase(this->element.begin());
    return last;
}

template <class T>
T Queue<T>::top() const {
    return this->element[0];
}

template <class T>
bool Queue<T>::isEmpty() const {
    return this->element.empty();
}


template <class T>
int Queue<T>::size() const {
    return this->element.size();
}
