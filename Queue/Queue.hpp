#pragma once

#include <vector>

template <class T>
class Queue {
    private:
        std::vector<T> element;

    public:
        Queue(){};
        void push(T data);
        T pop();
        T top() const;
        bool isEmpty() const;
        int size() const;
};
