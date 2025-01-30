#include "vernam_cipher.h"
#include "utils.h"

#include <random>
#include <bitset>
#include <stdexcept>
#include <iostream>

std::string VernamCipher::Encrypt(const std::string& plain_text, const std::string& key) {
  /* -- DEBUG --
  std::cout << "text: " << plain_text << std::endl;
  std::cout << "key: " << key << std::endl;
  std::cout << "text size: " << plain_text.size() << std::endl;
  std::cout << "key size: " << key.size() << std::endl;
  */
  if (plain_text.size() != key.size()) {
    throw std::invalid_argument("The plain text and key must have the same length.");
  }

  std::string cipher_text;
  for (size_t i = 0; i < plain_text.size(); i += 8) {
    char plain_char = BinToChar(plain_text.substr(i, 8));
    char key_char = BinToChar(key.substr(i, 8));
    char encrypted_char = plain_char ^ key_char;
    cipher_text += std::bitset<8>(encrypted_char).to_string();
  }
  // DEBUG
  // std::cout << "cipher text: " << cipher_text << std::endl;
  return cipher_text;
}
std::string VernamCipher::Decrypt(const std::string& cipher_text, const std::string& key) {
  return Encrypt(cipher_text, key);
}

// Generate a random key in binary with the specified length
std::string VernamCipher::GenerateKey(size_t length) {
  std::string key;
  for (size_t i = 0; i < length; ++i) {
    key += (rand() % 2) ? '1' : '0';
  }
  return key;
}