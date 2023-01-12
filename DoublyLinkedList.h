#pragma once

template <typename T>
class DoublyLinkedList {
private:
  Node<T>* head;
  Node<T>* tail;
  size_t size;

public:
  DoublyLinkedList() : size(0) {
    head = new Node<T>(0, nullptr, nullptr);
    tail = new Node<T>(0, nullptr, nullptr);

    head->SetNext(tail);
    tail->SetPrev(head);
  }

  ~DoublyLinkedList(){
    while (head->GetNext() != tail) {
      RemoveFront();
    }
    delete head, tail;
    std::cout << "List is deleted" << std::endl;
  }

  const size_t GetSize() {
    return size;
  }

  const bool IsEmpty() {
    if (GetSize() == 0) {
      std::cout << std::endl;
      std::cout << "*****LIST IS EMPTY*****" << std::endl;

      return true;
    }
    return false;
  }

  void ListStatus() {
    std::cout << std::endl;

    for (Node<T>* node = head->GetNext(); node != nullptr;
      node = node->GetNext()) {
      std::cout << "<<[" << node->GetData() << "]>>";
    }
    std::cout << std::endl;
  }

  void InsertFront(T data) {
    Node<T>* node = new Node<T>(data, nullptr, nullptr);
    Node<T>* prev = head;
    Node<T>* next = head->GetNext();
    
    next->SetPrev(node);
    prev->SetNext(node);

    node->SetNext(next);
    node->SetPrev(prev);

    size++;
  }

  void InsertRear(T data) {
    Node<T>* node = new Node<T>(data, nullptr, nullptr);
    Node<T>* prev = tail->GetPrev();
    Node<T>* next = tail;

    next->SetPrev(node);
    prev->SetNext(node);

    node->SetNext(next);
    node->SetPrev(prev);

    size++;
  }

  void RemoveFront() {
    if (IsEmpty()) {
      std::cout << "No more nodes can be removed." << std::endl;
      return;
    }
    
    Node<T>* node = head->GetNext();
    Node<T>* next = node->GetNext();

    head->SetNext(next);
    next->SetPrev(head);

    size--;
    node->~Node();
  }

  void RemoveRear() {
    if (IsEmpty()) {
      std::cout << "No more nodes can be removed." << std::endl;
      return;
    }

    Node<T>* node = tail->GetPrev();
    Node<T>* prev = node->GetPrev();

    prev->SetNext(tail);
    tail->SetPrev(prev);

    size--;
    node->~Node();
  }
};