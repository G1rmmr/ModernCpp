#include "stdafx.h"

int main() {
  DoublyLinkedList<int> integer_list;
  std::cout << std::endl;

  int integer_data;
  std::cout << "Enter the integer data >> ";

  for (short i = 0; i < 10; ++i) {
    std::cin >> integer_data;
    integer_list.InsertNode(integer_data);
  }
  
  for (short i = 0; i < 10; ++i) {
    integer_list.ListStatus();
    integer_list.RemoveRoot();
  }

  DoublyLinkedList<std::string> string_list;
  std::cout << std::endl;

  std::string string_data;
  std::cout << "Enter the string data >> ";

  for (short i = 0; i < 10; ++i) {
    std::cin >> string_data;
    string_list.InsertNode(string_data);
  }

  for (short i = 0; i < 10; ++i) {
    string_list.ListStatus();
    string_list.RemoveRoot();
  }
  return 0;
}