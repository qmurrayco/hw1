/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{

  Node* in = nullptr;
  Node* evens = nullptr;
  Node* odds = nullptr;

  in = new Node(0, nullptr);
  in->next = new Node(11, nullptr);
  in->next->next = new Node(20, nullptr);

  split(in, odds, evens);

  std::cout << evens->value << std::endl;
  std::cout << evens->next->value << std::endl;
  std::cout << odds->value << std::endl;

  // Node* in = nullptr;
  // Node* evens = nullptr;
  // Node* odds = nullptr;

  // split(in, odds, evens);

  // std::cout << "out of split" << std::endl;
  // std::cout << in << std::endl;
  // std::cout << "ping" << std::endl;
  // std::cout << evens << std::endl;
  // std::cout << "pingping" << std::endl;
  // std::cout << odds << std::endl;
  // std::cout << "pingpingping" << std::endl;


}
