#include <iostream>
#include "Heap.hpp"
#include "Heap.cpp"

using std::cout;
using std::endl;

int main(){
  Heap<int> test;
  test.insert(10);
  test.insert(20);
  test.insert(30);
  test.insert(5);

  test.print();

  cout << "insertions ended" << endl;


  cout << "the one with the most priority is " << test.peek() << std::endl;

  cout << "I got and deleted " << test.poll() << endl;

  test.print();
}
