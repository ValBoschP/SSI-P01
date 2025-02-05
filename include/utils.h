/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 1: Cifrado de Vernam
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 23/01/2025
 * Archivo: utils.h: En este archivo se declaran las funciones y constantes que se utilizan en el programa.
 */

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
bool IsStringASCII(const std::string& text);
bool IsASCII(const char character);
void ProcessEncryption();
void ProcessDecryption();
void PrintBinary(const std::string& text);
char BinToChar(const std::string& binary);
std::string StringToBinary(const std::string& text);
std::string BinaryToString(const std::string& binary);

#endif // UTILS_H