#include "bst.hpp"
#include "bst.cpp"


int main() {
  BST<int> tree { 5 };
  tree.inorder();
  for( int i=6; i<50000; i++ ){
    tree.insert(i);
  }
  tree.inorder();
}
