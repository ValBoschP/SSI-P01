/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 1: Cifrado de Vernam
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 23/01/2025
 * Archivo: main.cc: Programa principal que permite al usuario cifrar y descifrar mensajes utilizando el cifrado de Vernam.
 */


#include "vernam_cipher.h"
#include "utils.h"

#include <iostream>

int main() {
  int option;
  do {
    ShowMenu();
    std::cin >> option;
    std::cin.ignore();

    if (option == 1) {
      ProcessEncryption();
      std::cout << std::endl << "Press ENTER to continue...";
      std::cin.get();
      system(CLEAR_SCREEN);
    } else if (option == 2) {
      ProcessDecryption();
      std::cout << std::endl << "Press ENTER to continue...";
      std::cin.get();
      system(CLEAR_SCREEN);
    } else if (option == 3) {
      ShowHelp();
    }

  } while (option != 0);
  
  return 0;
}