#include "menu.hpp"
#include "common_api.hpp"

Vehicle insert_vehicle(){
  break_line();
  print_message("Insert new id: ");
  int new_id = insert_to_int();
  break_line();
  print_message("Insert new capacity: ");
  int new_capacity = insert_to_int();
  break_line();
  print_message_break("Data received with sucessful");
  return Vehicle(new_id, new_capacity);
}

Deposity insert_deposity(){
  break_line();
  print_message("Insert new id: ");
  int new_id = insert_to_int();
  break_line();
  print_message("Insert a new arrival time lower bound: ");
  int new_arrival_time_lower_bound = insert_to_int();
  break_line();
  print_message("Insert a new arrival time upper bound: ");
  int new_arrival_time_upper_bound = insert_to_int();
  break_line();
  print_message_break("Data received with sucessful");

  return Deposity(new_id, new_arrival_time_lower_bound, new_arrival_time_upper_bound);
}

Customer insert_customer(){
  break_line();
  print_message("Insert new id: ");
  int new_id = insert_to_int();
  break_line();
  print_message("Insert demand: ");
  int new_demand = insert_to_int();
  break_line();
  print_message("Insert service time: ");
  int new_service_time = insert_to_int();
  break_line();
  print_message("Insert arrival time lower bound: ");
  int new_arrival_time_lower_bound = insert_to_int();
  break_line();
  print_message("Insert arrival time upper bound: ");
  int new_arrival_time_upper_bound = insert_to_int();
  break_line();
  print_message_break("Data received with sucessful");

  return Customer(new_id, new_demand, new_service_time, new_arrival_time_lower_bound, new_arrival_time_upper_bound);
}

void menu(){
  char input;
  while (input != 'q'){
    break_line();
    print_message_break("Trabalho Prático de Algoritmos em Grafos");
    break_line();

    print_message_break("i -> Insert");
    print_message_break("q -> Sair");
    break_line();
    print_message("Your choose: ");
    std::cin >> input;

    switch (input) {
      case 'i':
        char choose;
        break_line();
        print_message_break("What you want insert: ");
        print_message_break("c -> customer");
        print_message_break("d -> deposit");
        print_message_break("v -> vehicle");
        break_line();
        print_message("Your choose: ");
        std::cin >> choose;

        switch (choose) {
          case 'c':
            insert_customer();
            break;
          case 'v':
            insert_vehicle();
            break;
          case 'd':
            insert_deposity();
            break;
          default:
            break;
        }
        break;
      case 'q':
        break;
      default:
        break;
    }
  };
}


