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