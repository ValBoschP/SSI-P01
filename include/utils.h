#ifndef UTILS_H
#define UTILS_H

#include <string>

#ifdef _WIN32
  #define CLEAR_SCREEN "cls"
#else
  #define CLEAR_SCREEN "clear"
#endif

void ShowMenu();
void ShowHelp();
void ProcessEncryption();
void ProcessDecryption();
void PrintBinary(const std::string& text);
char BinToChar(const std::string& binary);
std::string StringToBinary(const std::string& text);
std::string BinaryToString(const std::string& binary);

#endif // UTILS_H