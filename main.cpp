
// Copyright 2022 Nam Ji-Won

#include "stdafx.h"

// Enum
const enum SimulationCode {
  kIntCode = 1,
  kStringCode = 2,
  kExitCode = 3
};

const enum OperationCode {
  kStatusCode = 1,
  kInsertFrontCode = 2,
  kInsertRearCode = 3,
  kRemoveFrontCode = 4,
  kRemoveRearCode = 5,
  kOutCode = 6
};

// Function declaration
void CheckInputError();

void SimulateIntList();
void SimulateStringList();

void SimulateExit();
void SimulateDLL();

// Function definition

// Display DLL simulation interface
void SimulateDLL() {
  std::cout << "< Doubly Linked List Simulation >" << std::endl;

  int simulation_key;

  do {
    std::cout << "[ Select the simulation code ]" << std::endl << std::endl;
    std::cout << "> 1. Integer list" << std::endl;
    std::cout << "> 2. String list" << std::endl;
    std::cout << "> 3. Exit " << std::endl << std::endl;
      
    std::cout << "Enter the code >> ";
    std::cin >> simulation_key;
    std::cin.ignore();

    std::cout << std::endl;

    switch (simulation_key)
    {
    case SimulationCode::kIntCode:
      SimulateIntList();
      break;
    case SimulationCode::kStringCode:
      SimulateIntList();
      break;
    case SimulationCode::kExitCode:
      SimulateExit();
      break;
    default:
      std::cout << "The key is not available. Please enter the exist code." << std::endl;
      break;
    }
    std::cout << "------------------------------------------------------" << std::endl;
  } while (true);
}

// Simulate integer DLL
void SimulateIntList() {
  DoublyLinkedList<int> integer_list;

  int operation_key, integer_data;

  do {
    std::cout << std::endl <<  "[ Select the operation code ]" << std::endl << std::endl;
    std::cout << "> 1. Status" << std::endl;
    std::cout << "> 2. Insert front" << std::endl;
    std::cout << "> 3. Insert rear" << std::endl;
    std::cout << "> 4. Remove front" << std::endl;
    std::cout << "> 5. Remove rear" << std::endl;
    std::cout << "> 6. Exit" << std::endl << std::endl;

    std::cout << "Enter the code >> ";
    std::cin >> operation_key;
    CheckInputError();

    std::cout << std::endl;

    switch (operation_key)
    {
    case OperationCode::kStatusCode:
      if (!integer_list.IsEmpty()) {
        integer_list.ListStatus();
      }
      break;

    case OperationCode::kInsertFrontCode:
      std::cout << "Enter the integer data >> ";
      std::cin >> integer_data;
      CheckInputError();

      if (typeid(integer_data) != typeid(int)) {
        std::cout << "The value is not available. Please enter the INTEGER data.";
      } else {
        integer_list.InsertFront(integer_data);
      }
      break;

    case OperationCode::kInsertRearCode:
      std::cout << "Enter the integer data >> ";
      std::cin >> integer_data;
      CheckInputError();

      if (typeid(integer_data) != typeid(int)) {
        std::cout << "The value is not available. Please enter the INTEGER data.";
      } else {
        integer_list.InsertRear(integer_data);
      }
      break;

    case OperationCode::kRemoveFrontCode:
      integer_list.RemoveFront();
      break;

    case OperationCode::kRemoveRearCode:
      integer_list.RemoveFront();
      break;

    case OperationCode::kOutCode:
      SimulateDLL();
      break;

    default:
      std::cout << "The key is not available. Please enter the exist code." << std::endl;
      break;
    }
    std::cout << "------------------------------------------------------" << std::endl;
  } while (true);
}

// Simulate string DLL
void SimulateStringList() {
  DoublyLinkedList<std::string> string_list;

  int operation_key;
  std::string string_data;

  do {
    std::cout << "[ Select the operation code ]" << std::endl << std::endl;
    std::cout << "> 1. Status" << std::endl;
    std::cout << "> 2. Insert front" << std::endl;
    std::cout << "> 3. Insert rear" << std::endl;
    std::cout << "> 4. Remove front" << std::endl;
    std::cout << "> 5. Remove rear" << std::endl;
    std::cout << "> 6. Exit" << std::endl << std::endl;

    std::cout << "Enter the code >> ";
    std::cin >> operation_key;
    CheckInputError();

    std::cout << std::endl;
    
    switch (operation_key)
    {
    case OperationCode::kStatusCode:
      if (!string_list.IsEmpty()) {
        string_list.ListStatus();
      }
      break;

    case OperationCode::kInsertFrontCode:
      std::cout << "Enter the string data >> ";
      getline(std::cin, string_data);
      CheckInputError();

      if (typeid(string_data) != typeid(std::string)) {
        std::cout << "The value is not available. Please enter the STRING data.";
      }
      else {
        string_list.InsertFront(string_data);
      }

      std::cout << std::endl;
      break;

    case OperationCode::kInsertRearCode:
      std::cout << "Enter the string data >> ";
      getline(std::cin, string_data);
      CheckInputError();

      if (typeid(string_data) != typeid(std::string)) {
        std::cout << "The value is not available. Please enter the STRING data.";
      }
      else {
        string_list.InsertRear(string_data);
      }

      std::cout << std::endl;
      break;

    case OperationCode::kRemoveFrontCode:
      string_list.RemoveFront();
      break;

    case OperationCode::kRemoveRearCode:
      string_list.RemoveFront();
      break;

    case OperationCode::kOutCode:
      SimulateDLL();
      break;

    default:
      std::cout << "The key is not available. Please enter the exist code." << std::endl;
      break;
    }
    std::cout << "------------------------------------------------------" << std::endl;
  } while (true);
}

// Check the input error
void CheckInputError() {
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore();
  }
  return;
}

// Exit Simulation
void SimulateExit() {
  std::cout << "Simulation Exit. . ." << std::endl;
  std::cout << "Thank You !" << std::endl;
  exit(0);
}

int main() {
  SimulateDLL();
  return 0;
}