#pragma once

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "stdafx.h"

template <typename Data>
class Node {
private:
  Data data;
  Node* left_link;
  Node* right_link;

public:
  Node() {}

  Node(const Data input) : data(input),
    left_link(nullptr), right_link(nullptr) {}

  Node(const Data input, const Node* front, const Node* rear) :
    data(input), left_link(front), right_link(rear) {}

  ~Node(){
    std::cout << "Node is deleted" << std::endl;
  }

  void SetData(const Data input) {
    this->data = input;
  }

  void SetFront(const Node* front_link) {
    this->left_link = front_link;
  }

  void SetRear(const Node* rear_link) {
    this->right_link = rear_link;
  }

  Data GetData() const { return data; }
  Node* GetFrontPointer() { return left_link; }
  Node* GetRearPointer() { return right_link; }
};

template <typename Data>
class DoublyLinkedList {
private:
  Node<Data> root_node;

public:
  DoublyLinkedList() {
    this->root_node.SetData(NULL);
  }

  ~DoublyLinkedList(){
    std::cout << "List is deleted" << std::endl;
  }

  void ListStatus() {
    Node<Data> node;
    node = *root_node.GetRearPointer();

    std::cout << std::endl;

    while (node != root_node) {
      std::cout << "<< [" << node.GetData() << "] >>";
      node = *node.GetRearPointer();
    }
    std::cout << std::endl;
  }

  void InsertNode(Data input_data) {
    Node<Data> node(input_data);

    if (root_node.GetData() == NULL) {
      this->root_node = node;
      this->root_node.SetFront(&node);
      this->root_node.SetRear(&node);

      return;
    }
    
    node.SetFront(&root_node);
    root_node.SetRear(&node);
    this->root_node = node;
  }

  void RemoveRoot() const {
    if (this->root_node == *this->root_node.GetRearPointer()) {
      std::cout << std::endl << "*****!! LIST EMPTY ERROR !!*****" <<
        std::endl;
    }
    
    Node<Data> front_node = *this->root_node.GetFrontPointer();
    Node<Data> rear_node = *this->root_node.GetRearPointer();

    front_node.SetRear(&rear_node);
    rear_node.SetFront(&front_node);

    this->root_node.~Node();
    this->root_node = front_node;
  }
};

#endif // !DOUBLYLINKEDLIST_H