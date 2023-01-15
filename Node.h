
// Copyright 2023 Nam-Jiwon

#pragma once

template <typename T>
class Node {
private:
  T data;
  Node* next;
  Node* prev;

public:
  Node() {}
  Node(T data) : data(data) {}
  Node(T data, Node* next, Node* prev) : data(data), next(next), prev(prev) {}

  ~Node() { std::cout << "Node is deleted" << std::endl;  }

  void SetData(T data) { this->data = data; }
  void SetNext(Node* next) { this->next = next; }
  void SetPrev(Node* prev) { this->prev = prev; }

  T GetData() const { return data; }
  Node* GetNext() const { return next; }
  Node* GetPrev() const { return prev; }
};