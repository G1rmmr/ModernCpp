#include "stdafx.h"

void SimulateIntList();
void SimulateStringList();
void SimulateDLL();

int main() {
  SimulateDLL();
  SimulateIntList();
  SimulateStringList();
  return 0;
}

void SimulateDLL() {
  std::cout << "// Double Linked List Simulation" << std::endl;


}

void SimulateIntList() {
  DoublyLinkedList<int> integer_list;
  std::cout << std::endl;

  int integer_data;
  std::cout << "Enter the integer data >> ";

  for (short i = 0; i < 10; ++i) {
    std::cin >> integer_data;
    integer_list.InsertFront(integer_data);
    integer_list.ListStatus();
  }

  for (short i = 0; i < 10; ++i) {
    integer_list.ListStatus();
    integer_list.RemoveRear();
  }
}

void SimulateStringList() {
  DoublyLinkedList<std::string> string_list;
  std::cout << std::endl;

  std::string string_data;
  std::cout << "Enter the string data >> ";

  for (short i = 0; i < 10; ++i) {
    std::cin >> string_data;
    string_list.InsertFront(string_data);
    string_list.ListStatus();
  }

  for (short i = 0; i < 10; ++i) {
    string_list.ListStatus();
    string_list.RemoveRear();
  }
}
