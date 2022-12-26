#include "Node.h"

template <typename Data>
Node<Data>::Node(){}

Node::Node(int input) {
  SetRoot(input);
}

void Node::SetRoot(int input) {
  root_data = input;
}