#include "bst.hpp"
#include <memory>


template <class T>
BST<T>::BST(T data){
  this->head = std::make_shared<node<T>>(data);
}

template <class T>
void BST<T>::clean(std::shared_ptr<node<T>> &head) {
  std::shared_ptr<node<T>> tmp = std::make_shared<node<T>>();
  if (head == NULL)
    return;
  this->clean(head->left_child);
  this->clean(head->right_child);
  tmp = std::move(head);
}


template <class T>
BST<T>::~BST(){
 this->clean(this->head);
}


template <class T>
void BST<T>::insert(std::shared_ptr<node<T>> &head, T value){
  if( head == NULL ){
    std::shared_ptr<node<T>> new_ptr = std::make_shared<node<T>>(value);
    head = std::move(new_ptr);
  }
  
  if( value > head->data ){
    this->insert(head->right_child, value);
  }else if( value < head->data ){
    this->insert(head->left_child, value);
  }
}

template <class T>
void BST<T>::insert(T value) {
  this->insert(this->head, value);
}

template <class T>
std::shared_ptr<node<T>> BST<T>::findMin(std::shared_ptr<node<T>> head){
  std::shared_ptr<node<T>> tmp { head->right_child };
  while (tmp->left_child->data < tmp->data) {
    tmp = tmp->left_child;
  }
  return tmp;
}

template <class T>
std::shared_ptr<node<T>> BST<T>::remove(std::shared_ptr<node<T>> &head, T value){
  if (head == NULL) {
   return NULL; 
  } else if (head->data > value) {
    head->left_child = remove(head->left_child, value);
  } else if (head->data < value) {
    head->right_child = remove(head->right_child, value);
  } else {
    if (head->left_child == NULL && head->right_child == NULL) {
      std::shared_ptr<node<T>> tmp;
      tmp = std::move(head);
      head = NULL;
    } else if (head->left_child != NULL && head->right_child == NULL) { // replace the node by his child
      std::shared_ptr<node<T>> tmp;
      tmp = std::move(head);
      head = std::move(tmp->left_child);
    } else if (head->left_child == NULL && head->right_child != NULL) {
      std::shared_ptr<node<T>> tmp;
      tmp = std::move(head);
      head = std::move(tmp->right_child);
    } else {
      std::shared_ptr<node<T>> tmp = this->findMin(head); 
      head->data = tmp->data;
      head->right_child = remove(head->right_child, tmp->data);
    }
    return head;
  }
  return NULL;
}

template <class T>
void BST<T>::remove(T value) {
  this->head = this->remove(this->head, value);
}


template <class T>
bool BST<T>::contains(T value) const {
  std::shared_ptr<node<T>> tmp { this->head };
  while(tmp != NULL) {
    if (tmp->data > value) {
      tmp = tmp->left_child;
    } else if (tmp->data < value) {
      tmp = tmp->right_child;
    } else {
      return true;
    }
  }
  return false;
}

template <class T>
void BST<T>::print(std::shared_ptr<node<T>> head) const { // inorder
  if (head == NULL)
    return;
  this->print(head->left_child);
  std::cout << head->data << " ";
  this->print(head->right_child);
}

template <class T>
void BST<T>::inorder() const {
  this->print(this->head);
}
