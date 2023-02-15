#include <iostream>

void print_message_break(std::string message){
  std::cout << message << std::endl;
}

void print_message(std::string message){
  std::cout << message;
}
void break_line(){
  std::cout << std::endl;
}

int insert_to_int(){
  int value;
  std::cin >> value;
  return value;
}

