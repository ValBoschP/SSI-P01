#ifndef UTILS_H
#define UTILS_H

#include <string>

#ifdef _WIN32
  #define CLEAR_SCREEN "cls"
#else
  #define CLEAR_SCREEN "clear"
#endif

#define RESET       "\033[0m"
#define BOLD        "\033[1m"

#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"

void ShowMenu();
void ShowHelp();
void ProcessEncryption();
void ProcessDecryption();
void PrintBinary(const std::string& text);
char BinToChar(const std::string& binary);
std::string StringToBinary(const std::string& text);
std::string BinaryToString(const std::string& binary);

#endif // UTILS_H