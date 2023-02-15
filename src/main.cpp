// Trabalho Prático de Algoritmos em Grafos
//
// Aluno: Arthur Augusto Magalhães
// Matricula: 202110830
// Turma: 10A


#include "common_api.hpp"
#include "enterprise.hpp"
#include "iostream"

void menu(){
  char input;
  while (input != 'q'){
    print_message_break("Trabalho Prático de Algoritmos em Grafos");
    break_line();

    print_message_break("i -> Inserir elementos");
    print_message_break("q -> Sair");
    std::cin >> input;

    switch (input) {
      case 'i':
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
