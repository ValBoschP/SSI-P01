/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 1: Cifrado de Vernam
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 23/01/2025
 * Archivo: vernam_cipher.h: En este archivo se declaran las funciones de la clase VernamCipher.
 */

#ifndef VERNAM_CIPHER_H
#define VERNAM_CIPHER_H

#include <string>

class VernamCipher {
 public:
  static std::string Encrypt(const std::string& plain_text, const std::string& key);
  static std::string Decrypt(const std::string& cipher_text, const std::string& key);
  static std::string GenerateKey(size_t length);
};

#endif // VERNAM_CIPHER_H