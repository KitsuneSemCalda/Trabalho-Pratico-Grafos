// Trabalho Prático de Algoritmos em Grafos
//
// Aluno: Arthur Augusto Magalhães
// Matricula: 202110830
// Turma: 10A


#include "common_api.hpp"
#include "enterprise.hpp"
#include "iostream"

Customer insert_customer(){
  std::cout << "Insert new id: ";
  int new_id = insert_to_int();
  break_line();
  std::cout << "Insert demand: ";
  int new_demand = insert_to_int();
  break_line();
  std::cout << "Insert service time: ";
  int new_service_time = insert_to_int();
  break_line();
  std::cout << "Insert arrival time lower bound: ";
  int new_arrival_time_lower_bound = insert_to_int();
  break_line();
  std::cout << "Insert arrival time upper bound: ";
  int new_arrival_time_upper_bound = insert_to_int();
  
  break_line();
  print_message_break("Data received with sucessful");

  return Customer(new_id, new_demand, new_service_time, new_arrival_time_lower_bound, new_arrival_time_upper_bound);
}

void menu(){
  char input;
  while (input != 'q'){
    print_message_break("Trabalho Prático de Algoritmos em Grafos");
    break_line();

    print_message_break("i -> Insert");
    print_message_break("q -> Sair");
    std::cin >> input;

    switch (input) {
      case 'i':
        char choose;
        print_message_break("What you want insert: ");
        print_message_break("c -> customer");
        print_message_break("d -> deposit");
        print_message_break("v -> vehicle");
        std::cin >> choose;

        switch (choose) {
          case 'c':
            insert_customer();
            break;
          case 'v':
            break;
          case 'd':
            break;
        }
        break;
      case 'q':
        break;
    }
  };
}

int main (int argc, char *argv[])
{
  menu(); 
  return 0;
}
